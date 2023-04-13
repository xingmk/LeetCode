#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	/*
	  ���ֲ���
	  >= X
	  > 	= (>= X) + 1
	  <   = (>= X) -1
	  <=  = (>= X + 1) -1
	 */
	

	/*
	  ���ֲ���
	  leetcode: 704
	 */
	// ������
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1; // ����target������ұյ������[left, right]
		while (left <= right) { // ��left==right������[left, right]��Ȼ��Ч�������� <=
			int middle = left + ((right - left) / 2);// ��ֹ��� ��ͬ��(left + right)/2
			if (nums[middle] > target) {
				right = middle - 1; // target �������䣬����[left, middle - 1]
			} else if (nums[middle] < target) {
				left = middle + 1; // target �������䣬����[middle + 1, right]
			} else { // nums[middle] == target
				return middle; // �������ҵ�Ŀ��ֵ��ֱ�ӷ����±�
			}
		}
		// δ�ҵ�Ŀ��ֵ
		return -1;
	}
	// ����ҿ� 
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size(); // ����target������ҿ������������[left, right)
		while (left < right) { // ��Ϊleft == right��ʱ����[left, right)����Ч�Ŀռ䣬����ʹ�� <
			int middle = left + ((right - left) >> 1);
			if (nums[middle] > target) {
				right = middle; // target �������䣬��[left, middle)��
			} else if (nums[middle] < target) {
				left = middle + 1; // target �������䣬��[middle + 1, right)��
			} else { // nums[middle] == target
				return middle; // �������ҵ�Ŀ��ֵ��ֱ�ӷ����±�
			}
		}
		// δ�ҵ�Ŀ��ֵ
		return -1;
	}

// 	35 ��������λ��
	int searchInsert(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size(); i++) {
			// �ֱ��������������
			// Ŀ��ֵ����������Ԫ��֮ǰ
			// Ŀ��ֵ����������ĳһ��Ԫ��
			// Ŀ��ֵ���������е�λ��
			if (nums[i] >= target) { // һ�����ִ��ڻ��ߵ���target��num[i]����ôi��������Ҫ�Ľ��
				return i;
			}
		}
		// Ŀ��ֵ����������Ԫ��֮������
		return nums.size(); // ���target�����ģ����� numsΪ�գ��򷵻�nums�ĳ���
	}
// 	34. �����������в���Ԫ�صĵ�һ�������һ��λ��
	class Solutions {
	public:
		vector<int> searchRange(vector<int>& nums, int target) {
			int leftBorder = getLeftBorder(nums, target);
			int rightBorder = getRightBorder(nums, target);
			// ���һ
			if (leftBorder == -2 || rightBorder == -2) return {-1, -1};
			// �����
			if (rightBorder - leftBorder > 1) return {leftBorder + 1, rightBorder - 1};
			// �����
			return {-1, -1};
		}
	private:
		int getRightBorder(vector<int>& nums, int target) {
			int left = 0;
			int right = nums.size() - 1;
			int rightBorder = -2; // ��¼һ��rightBorderû�б���ֵ�����
			while (left <= right) {
				int middle = left + ((right - left) / 2);
				if (nums[middle] > target) {
					right = middle - 1;
				} else { // Ѱ���ұ߽磬nums[middle] == target��ʱ�����left
					left = middle + 1;
					rightBorder = left;
				}
			}
			return rightBorder;
		}
		int getLeftBorder(vector<int>& nums, int target) {
			int left = 0;
			int right = nums.size() - 1;
			int leftBorder = -2; // ��¼һ��leftBorderû�б���ֵ�����
			while (left <= right) {
				int middle = left + ((right - left) / 2);
				if (nums[middle] >= target) { // Ѱ����߽磬nums[middle] == target��ʱ�����right
					right = middle - 1;
					leftBorder = right;
				} else {
					left = middle + 1;
				}
			}
			return leftBorder;
		}
	};
// 	69. x ��ƽ���� 
	int mySqrt(int x) {
		int lo = 0;
		int hi = x;
		int right = 0;
		while (lo <= hi) {
			long mid = lo + (hi - lo) / 2;
			if (mid * mid <= x) {
				lo = mid + 1;
				right = lo;
			} else {
				hi = mid - 1;
			}
		}
		return right-1;
	}
// 	367.��Ч����ȫƽ����
	bool isPerfectSquare(int num) {
		int lo = 0;
		int hi = num;
		while (lo <= hi) {
			long mid = lo + (hi - lo) / 2;
			if (mid * mid < num) {
				lo = mid + 1;
			} else if (mid * mid > num) {
				hi = mid - 1;
			} else {
				return true;
			}
		}
		return false;
	}
	/*
	  ���� && ˫ָ��
	  leetcode: 27
	 */
	int removeElement(vector<int>& nums, int val) {
		int slowIndex = 0;
		for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
			if (val != nums[fastIndex]) {
				nums[slowIndex++] = nums[fastIndex];
			}
		}
		return slowIndex;
	}
	/**
	 * ����˫ָ�뷽��������Ԫ��˳����Ըı����Ŀ�����ı���Ԫ�����λ�ã�ȷ�����ƶ�����Ԫ��
	 * ʱ�临�Ӷȣ�O(n)
	 * �ռ临�Ӷȣ�O(1)
	 */
	int removeElement(vector<int>& nums, int val) {
		int leftIndex = 0;
		int rightIndex = nums.size() - 1;
		while (leftIndex <= rightIndex) {
			// ����ߵ���val��Ԫ��
			while (leftIndex <= rightIndex && nums[leftIndex] != val){
				++leftIndex;
			}
			// ���ұ߲�����val��Ԫ��
			while (leftIndex <= rightIndex && nums[rightIndex] == val) {
				-- rightIndex;
			}
			// ���ұ߲�����val��Ԫ�ظ�����ߵ���val��Ԫ��
			if (leftIndex < rightIndex) {
				nums[leftIndex++] = nums[rightIndex--];
			}
		}
		return leftIndex;   // leftIndexһ��ָ������������ĩβ����һ��Ԫ��
	}
//	26.ɾ�����������е��ظ���
	int removeDuplicates(vector<int>& nums) {
		int slow = 0;
		for (int fast = 0; fast < nums.size(); fast++) {
			if (nums[fast] != nums[slow]) nums[++slow] = nums[fast];
		}
		return ++slow;
	}
//	283.�ƶ���
	void moveZeroes(vector<int>& nums) {
		int slow = 0;
		for (int cur = 0; cur < nums.size(); cur++) {
			if (nums[cur] != 0) nums[slow++] = nums[cur];
		}
		for (int cur = slow+1; slow < nums.size(); slow++) {
			nums[slow] = 0;
		}
	} 
//	844.�ȽϺ��˸���ַ���
	bool backspaceCompare(string S, string T) {
		string s;
		string t;
		for (int i=0; i<S.size(); i++) {
			if (S[i] != '#') s += S[i];
			else if (!s.empty()) s.pop_back();
		}
		for (int i=0; i<T.size(); i++) {
			if (T[i] != '#') t += T[i];
			else if (!t.empty()) t.pop_back();
		}
		if (s == t) return true;
		return false;
	}
	
	/*
	977 ���������ƽ��
	 */
	vector<int> sortedSquares(vector<int>& A) {
		int k = A.size() - 1;
		vector<int> result(A.size(), 0);
		for (int i = 0, j = A.size() - 1; i <= j;) { // ע������Ҫi <= j����Ϊ���Ҫ��������Ԫ��
			if (A[i] * A[i] < A[j] * A[j])  {
				result[k--] = A[j] * A[j];
				j--;
			}
			else {
				result[k--] = A[i] * A[i];
				i++;
			}
		}
		return result;
	}

	/*
	209 ������С��������
	*/
	int minSubArrayLen(int s, vector<int>& nums) {
		int result = INT32_MAX;
		int sum = 0; // ����������ֵ֮��
		int i = 0; // ����������ʼλ��
		int subLength = 0; // �������ڵĳ���
		for (int j = 0; j < nums.size(); j++) {
			sum += nums[j];
			// ע������ʹ��while��ÿ�θ��� i����ʼλ�ã��������ϱȽ��������Ƿ��������
			while (sum >= s) {
				subLength = (j - i + 1); // ȡ�����еĳ���
				result = result < subLength ? result : subLength;
				sum -= nums[i++]; // �������ֳ��������ڵľ���֮�������ϱ��i�������е���ʼλ�ã�
			}
		}
		// ���resultû�б���ֵ�Ļ����ͷ���0��˵��û�з���������������
		return result == INT32_MAX ? 0 : result;
	}
//	904.ˮ������
	int totalFruit(vector<int>& fruits) {
		int lo = 0, hi = 0, sum = 0;
		int ln = fruits[lo], hn = fruits[hi];
		for (hi; hi < fruits.size(); hi++) {
			if (fruits[hi] == ln || fruits[hi] == hn) sum = max(sum, hi - lo + 1);
			else {
				lo = hi - 1;
				ln = fruits[lo];
				while (lo >= 1 && fruits[lo - 1] == ln) lo--;
				hn =fruits[hi];
				sum = max(sum, hi - lo + 1);
			}
		}
		return sum;
	}
//	76. ��С�����Ӵ�
	string minWindow(string s, string t) {
		unordered_map<char,int> need;
		int Len = t.size(), correct = 0;
		for (char c : t) need[c]++; 
		
		int left = 0, right = 0, min_len = s.size() + 1, start = 0;
		for (; right < s.size(); right++) {
			if (need[s[right]] > 0) correct++; 
			need[s[right]]--; 
			while (correct == Len) {
				if(min_len > right - left + 1) {
					min_len = right-left+1;
					start = left;
				}
				if(need[s[left]] == 0) correct--; 
				need[s[left]]++;
				left++;
			}
		}
		return min_len == s.size() + 1 ? "" : s.substr(start, min_len);
	}
	
	/*
	59 ��������II
	 */
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0)); // ʹ��vector����һ����ά����
		int startx = 0, starty = 0; // ����ÿѭ��һ��Ȧ����ʼλ��
		int loop = n / 2; // ÿ��Ȧѭ�����Σ�����nΪ����3����ôloop = 1 ֻ��ѭ��һȦ�������м��ֵ��Ҫ��������
		int mid = n / 2; // �����м��λ�ã����磺nΪ3�� �м��λ�þ���(1��1)��nΪ5���м�λ��Ϊ(2, 2)
		int count = 1; // ������������ÿһ���ո�ֵ
		int offset = 1; // ��Ҫ����ÿһ���߱����ĳ��ȣ�ÿ��ѭ���ұ߽�����һλ
		int i,j;
		while (loop --) {
			i = startx;
			j = starty;
			
			// ���濪ʼ���ĸ�for����ģ��ת��һȦ
			// ģ��������д�����(����ҿ�)
			for (j = starty; j < n - offset; j++) {
				res[startx][j] = count++;
			}
			// ģ��������д��ϵ���(����ҿ�)
			for (i = startx; i < n - offset; i++) {
				res[i][j] = count++;
			}
			// ģ��������д��ҵ���(����ҿ�)
			for (; j > starty; j--) {
				res[i][j] = count++;
			}
			// ģ��������д��µ���(����ҿ�)
			for (; i > startx; i--) {
				res[i][j] = count++;
			}
			
			// �ڶ�Ȧ��ʼ��ʱ����ʼλ��Ҫ���Լ�1�� ���磺��һȦ��ʼλ����(0, 0)���ڶ�Ȧ��ʼλ����(1, 1)
			startx++;
			starty++;
			
			// offset ����ÿһȦ��ÿһ���߱����ĳ���
			offset += 1;
		}
		
		// ���nΪ�����Ļ�����Ҫ�������������м��λ�ø�ֵ
		if (n % 2) {
			res[mid][mid] = count;
		}
		return res;
	}

//	54.��������	
	
//	��ָOffer 29.˳ʱ���ӡ����
	
};

int main() {
	return 0;
}
