#include <bits/stdc++.h>

using namespace std;

/*
  344.��ת�ַ���
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
  541. ��ת�ַ���II
 */

	class Solution {
	public:
		string reverseStr(string s, int k) {
			for (int i = 0; i < s.size(); i += (2 * k)) {
				// 1. ÿ�� 2k ���ַ���ǰ k ���ַ����з�ת
				// 2. ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ�
				if (i + k <= s.size()) {
					reverse(s.begin() + i, s.begin() + i + k );
				} else {
					// 3. ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
					reverse(s.begin() + i, s.end());
				}
			}
			return s;
		}
	};

// ����������ұ�����
	class Solution {
	public:
		void reverse(string& s, int start, int end) {
			for (int i = start, j = end; i < j; i++, j--) {
				swap(s[i], s[j]);
			}
		}
		string reverseStr(string s, int k) {
			for (int i = 0; i < s.size(); i += (2 * k)) {
				// 1. ÿ�� 2k ���ַ���ǰ k ���ַ����з�ת
				// 2. ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ�
				if (i + k <= s.size()) {
					reverse(s, i, i + k - 1);
					continue;
				}
				// 3. ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
				reverse(s, i, s.size() - 1);
			}
			return s;
		}
	};

// ��һ��˼·�Ľⷨ
	class Solution {
	public:
		string reverseStr(string s, int k) {
			int n = s.size(),pos = 0;
			while(pos < n){
				//ʣ���ַ������ڵ���k�����
				if(pos + k < n) reverse(s.begin() + pos, s.begin() + pos + k);
				//ʣ���ַ�������k����� 
				else reverse(s.begin() + pos,s.end());
				pos += 2 * k;
			}
			return s;
		}
	};

/*
  ��ָOffer 05.�滻�ո�
 */
	class Solution {
	public:
		string replaceSpace(string s) {
			int count = 0; // ͳ�ƿո�ĸ���
			int sOldSize = s.size();
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == ' ') {
					count++;
				}
			}
			// �����ַ���s�Ĵ�С��Ҳ����ÿ���ո��滻��"%20"֮��Ĵ�С
			s.resize(s.size() + count * 2);
			int sNewSize = s.size();
			// �Ӻ���ǰ���ո��滻Ϊ"%20"
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
  151.��ת�ַ�����ĵ���
 */
	class Solution {
	public:
		void reverse(string& s, int start, int end){ //��ת������д��������ұ� []
			for (int i = start, j = end; i < j; i++, j--) {
				swap(s[i], s[j]);
			}
		}
		
		void removeExtraSpaces(string& s) {//ȥ�����пո������ڵ���֮����ӿո�, ����ָ�롣
			int slow = 0;   //����˼��ο�https://programmercarl.com/0027.�Ƴ�Ԫ��.html
			for (int i = 0; i < s.size(); ++i) { //
				if (s[i] != ' ') { //�����ǿո�ʹ�����ɾ�����пո�
					if (slow != 0) s[slow++] = ' '; //�ֶ����ƿո񣬸�����֮����ӿո�slow != 0˵�����ǵ�һ�����ʣ���Ҫ�ڵ���ǰ��ӿո�
					while (i < s.size() && s[i] != ' ') { //���ϸõ��ʣ������ո�˵�����ʽ�����
						s[slow++] = s[i++];
					}
				}
			}
			s.resize(slow); //slow�Ĵ�С��Ϊȥ������ո��Ĵ�С��
		}
		
		string reverseWords(string s) {
			removeExtraSpaces(s); //ȥ������ո񣬱�֤����֮��ֻ֮��һ���ո����ַ�����βû�ո�
			reverse(s, 0, s.size() - 1);
			int start = 0; //removeExtraSpaces��֤��һ�����ʵĿ�ʼ�±�һ����0��
			for (int i = 0; i <= s.size(); ++i) {
				if (i == s.size() || s[i] == ' ') { //����ո���ߴ�β��˵��һ�����ʽ��������з�ת��
					reverse(s, start, i - 1); //��ת��ע��������ұ� []�ķ�ת��
					start = i + 1; //������һ�����ʵĿ�ʼ�±�start
				}
			}
			return s;
		}
	};

/*
  ��ָOffer58-II.����ת�ַ���
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
  28. ʵ�� strStr()
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
  459.�ظ������ַ���
 */
// �ƶ�ƥ��
	class Solution {
	public:
		bool repeatedSubstringPattern(string s) {
			string t = s + s;
			t.erase(t.begin()); t.erase(t.end() - 1); // ��ͷȥβ
			if (t.find(s) != std::string::npos) return true; // r
			return false;
		}
	};

// ����ʹ����ǰ׺��ͳһ��һ��ʵ�ַ�ʽ
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

// ǰ׺������һ����C++����ʵ��:
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
