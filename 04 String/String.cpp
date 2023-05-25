#include <bits/stdc++.h>

using namespace std;

/*
  344.反转字符串
 */

	class Solution {
	public:
		void reverseString(vector<char>& s) {
			for (int i = 0, j = s.size() - 1; i < s.size()/2; i++, j--) {
				swap(s[i],s[j]);
			}
		}
	};

/*
  541. 反转字符串II
 */

	class Solution {
	public:
		string reverseStr(string s, int k) {
			for (int i = 0; i < s.size(); i += (2 * k)) {
				// 1. 每隔 2k 个字符的前 k 个字符进行反转
				// 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
				if (i + k <= s.size()) {
					reverse(s.begin() + i, s.begin() + i + k );
				} else {
					// 3. 剩余字符少于 k 个，则将剩余字符全部反转。
					reverse(s.begin() + i, s.end());
				}
			}
			return s;
		}
	};

// 区间是左闭右闭区间
	class Solution {
	public:
		void reverse(string& s, int start, int end) {
			for (int i = start, j = end; i < j; i++, j--) {
				swap(s[i], s[j]);
			}
		}
		string reverseStr(string s, int k) {
			for (int i = 0; i < s.size(); i += (2 * k)) {
				// 1. 每隔 2k 个字符的前 k 个字符进行反转
				// 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
				if (i + k <= s.size()) {
					reverse(s, i, i + k - 1);
					continue;
				}
				// 3. 剩余字符少于 k 个，则将剩余字符全部反转。
				reverse(s, i, s.size() - 1);
			}
			return s;
		}
	};

// 另一种思路的解法
	class Solution {
	public:
		string reverseStr(string s, int k) {
			int n = s.size(),pos = 0;
			while(pos < n){
				//剩余字符串大于等于k的情况
				if(pos + k < n) reverse(s.begin() + pos, s.begin() + pos + k);
				//剩余字符串不足k的情况 
				else reverse(s.begin() + pos,s.end());
				pos += 2 * k;
			}
			return s;
		}
	};

/*
  剑指Offer 05.替换空格
 */
	class Solution {
	public:
		string replaceSpace(string s) {
			int count = 0; // 统计空格的个数
			int sOldSize = s.size();
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == ' ') {
					count++;
				}
			}
			// 扩充字符串s的大小，也就是每个空格替换成"%20"之后的大小
			s.resize(s.size() + count * 2);
			int sNewSize = s.size();
			// 从后先前将空格替换为"%20"
			for (int i = sNewSize - 1, j = sOldSize - 1; j < i; i--, j--) {
				if (s[j] != ' ') {
					s[i] = s[j];
				} else {
					s[i] = '0';
					s[i - 1] = '2';
					s[i - 2] = '%';
					i -= 2;
				}
			}
			return s;
		}
	};

/*
  151.翻转字符串里的单词
 */
	class Solution {
	public:
		void reverse(string& s, int start, int end){ //翻转，区间写法：左闭右闭 []
			for (int i = start, j = end; i < j; i++, j--) {
				swap(s[i], s[j]);
			}
		}
		
		void removeExtraSpaces(string& s) {//去除所有空格并在相邻单词之间添加空格, 快慢指针。
			int slow = 0;   //整体思想参考https://programmercarl.com/0027.移除元素.html
			for (int i = 0; i < s.size(); ++i) { //
				if (s[i] != ' ') { //遇到非空格就处理，即删除所有空格。
					if (slow != 0) s[slow++] = ' '; //手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
					while (i < s.size() && s[i] != ' ') { //补上该单词，遇到空格说明单词结束。
						s[slow++] = s[i++];
					}
				}
			}
			s.resize(slow); //slow的大小即为去除多余空格后的大小。
		}
		
		string reverseWords(string s) {
			removeExtraSpaces(s); //去除多余空格，保证单词之间之只有一个空格，且字符串首尾没空格。
			reverse(s, 0, s.size() - 1);
			int start = 0; //removeExtraSpaces后保证第一个单词的开始下标一定是0。
			for (int i = 0; i <= s.size(); ++i) {
				if (i == s.size() || s[i] == ' ') { //到达空格或者串尾，说明一个单词结束。进行翻转。
					reverse(s, start, i - 1); //翻转，注意是左闭右闭 []的翻转。
					start = i + 1; //更新下一个单词的开始下标start
				}
			}
			return s;
		}
	};

/*
  剑指Offer58-II.左旋转字符串
 */
	class Solution {
	public:
		string reverseLeftWords(string s, int n) {
			reverse(s.begin(), s.begin() + n);
			reverse(s.begin() + n, s.end());
			reverse(s.begin(), s.end());
			return s;
		}
	};

/*
  28. 实现 strStr()
 */
	class Solution {
	public:
		void getNext(int* next, const string& s) {
			int j = 0;
			next[0] = 0;
			for(int i = 1; i < s.size(); i++) {
				while (j > 0 && s[i] != s[j]) {
					j = next[j - 1];
				}
				if (s[i] == s[j]) {
					j++;
				}
				next[i] = j;
			}
		}
		int strStr(string haystack, string needle) {
			if (needle.size() == 0) {
				return 0;
			}
			int next[needle.size()];
			getNext(next, needle);
			int j = 0;
			for (int i = 0; i < haystack.size(); i++) {
				while(j > 0 && haystack[i] != needle[j]) {
					j = next[j - 1];
				}
				if (haystack[i] == needle[j]) {
					j++;
				}
				if (j == needle.size() ) {
					return (i - needle.size() + 1);
				}
			}
			return -1;
		}
	};

/*
  459.重复的子字符串
 */
// 移动匹配
	class Solution {
	public:
		bool repeatedSubstringPattern(string s) {
			string t = s + s;
			t.erase(t.begin()); t.erase(t.end() - 1); // 掐头去尾
			if (t.find(s) != std::string::npos) return true; // r
			return false;
		}
	};

// 这里使用了前缀表统一减一的实现方式
	class Solution {
	public:
		void getNext (int* next, const string& s){
			next[0] = -1;
			int j = -1;
			for(int i = 1;i < s.size(); i++){
				while(j >= 0 && s[i] != s[j + 1]) {
					j = next[j];
				}
				if(s[i] == s[j + 1]) {
					j++;
				}
				next[i] = j;
			}
		}
		bool repeatedSubstringPattern (string s) {
			if (s.size() == 0) {
				return false;
			}
			int next[s.size()];
			getNext(next, s);
			int len = s.size();
			if (next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0) {
				return true;
			}
			return false;
		}
	};

// 前缀表（不减一）的C++代码实现:
	class Solution {
	public:
		void getNext (int* next, const string& s){
			next[0] = 0;
			int j = 0;
			for(int i = 1;i < s.size(); i++){
				while(j > 0 && s[i] != s[j]) {
					j = next[j - 1];
				}
				if(s[i] == s[j]) {
					j++;
				}
				next[i] = j;
			}
		}
		bool repeatedSubstringPattern (string s) {
			if (s.size() == 0) {
				return false;
			}
			int next[s.size()];
			getNext(next, s);
			int len = s.size();
			if (next[len - 1] != 0 && len % (len - (next[len - 1] )) == 0) {
				return true;
			}
			return false;
		}
	};
