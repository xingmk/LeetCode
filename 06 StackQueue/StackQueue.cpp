#include <bits/stdc++.h>

using namespace std;

	/*
	232:    ջʵ�ֶ���
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
			// ֻ�е�stOutΪ�յ�ʱ���ٴ�stIn�ﵼ�����ݣ�����stInȫ�����ݣ�
			if (stOut.empty()) {
				// ��stIn��������ֱ��stInΪ��
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
			int res = this->pop(); // ֱ��ʹ�����е�pop����
			stOut.push(res); // ��Ϊpop����������Ԫ��res����������ӻ�ȥ
			return res;
		}
		
		/** Returns whether the queue is empty. */
		bool empty() {
			return stIn.empty() && stOut.empty();
		}
	};

	/*
	225:    �ö���ʵ��ջ
	*/
class MyStack {
public:
	queue<int> que1;
	queue<int> que2; // �������У���������
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
		while (size--) { // ��que1 ����que2����Ҫ�������һ��Ԫ��
			que2.push(que1.front());
			que1.pop();
		}
		
		int result = que1.front(); // ���µ����һ��Ԫ�ؾ���Ҫ���ص�ֵ
		que1.pop();
		que1 = que2;            // �ٽ�que2��ֵ��que1
		while (!que2.empty()) { // ���que2
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

// �Ż���
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
		while (size--) { // ������ͷ����Ԫ�أ��������һ��Ԫ���⣩ ������ӵ�����β��
			que.push(que.front());
			que.pop();
		}
		int result = que.front(); // ��ʱ������Ԫ��˳�����ջ��˳����
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
	20:    ��Ч������ 
	*/
	class Solution {
	public:
		bool isValid(string s) {
			if (s.size() % 2 != 0) return false; // ���s�ĳ���Ϊ������һ��������Ҫ��
			stack<char> st;
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == '(') st.push(')');
				else if (s[i] == '{') st.push('}');
				else if (s[i] == '[') st.push(']');
				// ����������������ַ���ƥ��Ĺ����У�ջ�Ѿ�Ϊ���ˣ�û��ƥ����ַ��ˣ�˵��������û���ҵ���Ӧ�������� return false
				// �ڶ�������������ַ���ƥ��Ĺ����У�����ջ��û������Ҫƥ����ַ�������return false
				else if (st.empty() || st.top() != s[i]) return false;
				else st.pop(); // st.top() �� s[i]��ȣ�ջ����Ԫ��
			}
			// ��һ���������ʱ�����Ѿ����������ַ���������ջ��Ϊ�գ�˵������Ӧ��������û����������ƥ�䣬����return false�������return true
			return st.empty();
		}
	};

	/*
	1047:   ɾ���ַ����е����������ظ���
	*/
	class Solutionss {
	public:
		string removeDuplicates(string S) {
			stack<char> st;
			for (char s : S) {
				if (st.empty() || s != st.top()) {
					st.push(s);
				} else {
					st.pop(); // s �� st.top()��ȵ����
				}
			}
			string result = "";
			while (!st.empty()) { // ��ջ��Ԫ�طŵ�result�ַ�������
				result += st.top();
				st.pop();
			}
			reverse (result.begin(), result.end()); // ��ʱ�ַ�����Ҫ��תһ��
			return result;
			
		}
	};

	// �ַ�����Ϊջ
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
	239:    �����������ֵ
	*/
	class Solutioned {
	private:
		class MyQueue { //�������У��Ӵ�С��
		public:
			deque<int> que; // ʹ��deque��ʵ�ֵ�������
			// ÿ�ε�����ʱ�򣬱Ƚϵ�ǰҪ��������ֵ�Ƿ���ڶ��г���Ԫ�ص���ֵ���������򵯳���
			// ͬʱpop֮ǰ�ж϶��е�ǰ�Ƿ�Ϊ�ա�
			void pop(int value) {
				if (!que.empty() && value == que.front()) {
					que.pop_front();
				}
			}
			// ���push����ֵ�������Ԫ�ص���ֵ����ô�ͽ����к�˵���ֵ������ֱ��push����ֵС�ڵ��ڶ������Ԫ�ص���ֵΪֹ��
			// �����ͱ����˶��������ֵ�ǵ����Ӵ�С���ˡ�
			void push(int value) {
				while (!que.empty() && value > que.back()) {
					que.pop_back();
				}
				que.push_back(value);
				
			}
			// ��ѯ��ǰ����������ֵ ֱ�ӷ��ض���ǰ��Ҳ����front�Ϳ����ˡ�
			int front() {
				return que.front();
			}
		};
	public:
		vector<int> maxSlidingWindow(vector<int>& nums, int k) {
			MyQueue que;
			vector<int> result;
			for (int i = 0; i < k; i++) { // �Ƚ�ǰk��Ԫ�طŽ�����
				que.push(nums[i]);
			}
			result.push_back(que.front()); // result ��¼ǰk��Ԫ�ص����ֵ
			for (int i = k; i < nums.size(); i++) {
				que.pop(nums[i - k]); // ���������Ƴ���ǰ��Ԫ��
				que.push(nums[i]); // ��������ǰ����������Ԫ��
				result.push_back(que.front()); // ��¼��Ӧ�����ֵ
			}
			return result;
		}
	};

	/*
	347.	ǰ K ����ƵԪ��
	*/
	class Solutionsss {
	public:
		// С����
		class mycomparison {
		public:
			bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
				return lhs.second > rhs.second;
			}
		};
		vector<int> topKFrequent(vector<int>& nums, int k) {
			// Ҫͳ��Ԫ�س���Ƶ��
			unordered_map<int, int> map; // map<nums[i],��Ӧ���ֵĴ���>
			for (int i = 0; i < nums.size(); i++) {
				map[nums[i]]++;
			}
			
			// ��Ƶ������
			// ����һ��С���ѣ���СΪk
			priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
			
			// �ù̶���СΪk��С���ѣ�ɨ������Ƶ�ʵ���ֵ
			for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
				pri_que.push(*it);
				if (pri_que.size() > k) { // ����ѵĴ�С������K������е�������֤�ѵĴ�СһֱΪk
					pri_que.pop();
				}
			}
			
			// �ҳ�ǰK����ƵԪ�أ���ΪС�����ȵ���������С�ģ����Ե��������������
			vector<int> result(k);
			for (int i = k - 1; i >= 0; i--) {
				result[i] = pri_que.top().first;
				pri_que.pop();
			}
			return result;
			
		}
	};



