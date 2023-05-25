#include <bits/stdc++.h>

using namespace std;

	/*
	232:    栈实现队列
	*/
	class MyQueue {
	public:
		stack<int> stIn;
		stack<int> stOut;
		/** Initialize your data structure here. */
		MyQueue() {
			
		}
		/** Push element x to the back of queue. */
		void push(int x) {
			stIn.push(x);
		}
		
		/** Removes the element from in front of queue and returns that element. */
		int pop() {
			// 只有当stOut为空的时候，再从stIn里导入数据（导入stIn全部数据）
			if (stOut.empty()) {
				// 从stIn导入数据直到stIn为空
				while(!stIn.empty()) {
					stOut.push(stIn.top());
					stIn.pop();
				}
			}
			int result = stOut.top();
			stOut.pop();
			return result;
		}
		
		/** Get the front element. */
		int peek() {
			int res = this->pop(); // 直接使用已有的pop函数
			stOut.push(res); // 因为pop函数弹出了元素res，所以再添加回去
			return res;
		}
		
		/** Returns whether the queue is empty. */
		bool empty() {
			return stIn.empty() && stOut.empty();
		}
	};

	/*
	225:    用队列实现栈
	*/
class MyStack {
public:
	queue<int> que1;
	queue<int> que2; // 辅助队列，用来备份
	/** Initialize your data structure here. */
	MyStack() {
		
	}
	
	/** Push element x onto stack. */
	void push(int x) {
		que1.push(x);
	}
	
	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int size = que1.size();
		size--;
		while (size--) { // 将que1 导入que2，但要留下最后一个元素
			que2.push(que1.front());
			que1.pop();
		}
		
		int result = que1.front(); // 留下的最后一个元素就是要返回的值
		que1.pop();
		que1 = que2;            // 再将que2赋值给que1
		while (!que2.empty()) { // 清空que2
			que2.pop();
		}
		return result;
	}
	
	/** Get the top element. */
	int top() {
		return que1.back();
	}
	
	/** Returns whether the stack is empty. */
	bool empty() {
		return que1.empty();
	}
};

// 优化：
class MyStack {
public:
	queue<int> que;
	/** Initialize your data structure here. */
	MyStack() {
		
	}
	/** Push element x onto stack. */
	void push(int x) {
		que.push(x);
	}
	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int size = que.size();
		size--;
		while (size--) { // 将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部
			que.push(que.front());
			que.pop();
		}
		int result = que.front(); // 此时弹出的元素顺序就是栈的顺序了
		que.pop();
		return result;
	}
	
	/** Get the top element. */
	int top() {
		return que.back();
	}
	/** Returns whether the stack is empty. */
	bool empty() {
		return que.empty();
	}
};

	/*
	20:    有效的括号 
	*/
	class Solution {
	public:
		bool isValid(string s) {
			if (s.size() % 2 != 0) return false; // 如果s的长度为奇数，一定不符合要求
			stack<char> st;
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == '(') st.push(')');
				else if (s[i] == '{') st.push('}');
				else if (s[i] == '[') st.push(']');
				// 第三种情况：遍历字符串匹配的过程中，栈已经为空了，没有匹配的字符了，说明右括号没有找到对应的左括号 return false
				// 第二种情况：遍历字符串匹配的过程中，发现栈里没有我们要匹配的字符。所以return false
				else if (st.empty() || st.top() != s[i]) return false;
				else st.pop(); // st.top() 与 s[i]相等，栈弹出元素
			}
			// 第一种情况：此时我们已经遍历完了字符串，但是栈不为空，说明有相应的左括号没有右括号来匹配，所以return false，否则就return true
			return st.empty();
		}
	};

	/*
	1047:   删除字符串中的所有相邻重复项
	*/
	class Solutionss {
	public:
		string removeDuplicates(string S) {
			stack<char> st;
			for (char s : S) {
				if (st.empty() || s != st.top()) {
					st.push(s);
				} else {
					st.pop(); // s 与 st.top()相等的情况
				}
			}
			string result = "";
			while (!st.empty()) { // 将栈中元素放到result字符串汇总
				result += st.top();
				st.pop();
			}
			reverse (result.begin(), result.end()); // 此时字符串需要反转一下
			return result;
			
		}
	};

	// 字符串作为栈
	class Solutions {
	public:
		string removeDuplicates(string S) {
			string result;
			for(char s : S) {
				if(result.empty() || result.back() != s) {
					result.push_back(s);
				}
				else {
					result.pop_back();
				}
			}
			return result;
		}
	};

	/*
	239:    滑动窗口最大值
	*/
	class Solutioned {
	private:
		class MyQueue { //单调队列（从大到小）
		public:
			deque<int> que; // 使用deque来实现单调队列
			// 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
			// 同时pop之前判断队列当前是否为空。
			void pop(int value) {
				if (!que.empty() && value == que.front()) {
					que.pop_front();
				}
			}
			// 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
			// 这样就保持了队列里的数值是单调从大到小的了。
			void push(int value) {
				while (!que.empty() && value > que.back()) {
					que.pop_back();
				}
				que.push_back(value);
				
			}
			// 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
			int front() {
				return que.front();
			}
		};
	public:
		vector<int> maxSlidingWindow(vector<int>& nums, int k) {
			MyQueue que;
			vector<int> result;
			for (int i = 0; i < k; i++) { // 先将前k的元素放进队列
				que.push(nums[i]);
			}
			result.push_back(que.front()); // result 记录前k的元素的最大值
			for (int i = k; i < nums.size(); i++) {
				que.pop(nums[i - k]); // 滑动窗口移除最前面元素
				que.push(nums[i]); // 滑动窗口前加入最后面的元素
				result.push_back(que.front()); // 记录对应的最大值
			}
			return result;
		}
	};

	/*
	347.	前 K 个高频元素
	*/
	class Solutionsss {
	public:
		// 小顶堆
		class mycomparison {
		public:
			bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
				return lhs.second > rhs.second;
			}
		};
		vector<int> topKFrequent(vector<int>& nums, int k) {
			// 要统计元素出现频率
			unordered_map<int, int> map; // map<nums[i],对应出现的次数>
			for (int i = 0; i < nums.size(); i++) {
				map[nums[i]]++;
			}
			
			// 对频率排序
			// 定义一个小顶堆，大小为k
			priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
			
			// 用固定大小为k的小顶堆，扫面所有频率的数值
			for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
				pri_que.push(*it);
				if (pri_que.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
					pri_que.pop();
				}
			}
			
			// 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
			vector<int> result(k);
			for (int i = k - 1; i >= 0; i--) {
				result[i] = pri_que.top().first;
				pri_que.pop();
			}
			return result;
			
		}
	};



