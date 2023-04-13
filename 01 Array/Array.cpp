#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	/*
	  二分查找
	  >= X
	  > 	= (>= X) + 1
	  <   = (>= X) -1
	  <=  = (>= X + 1) -1
	 */
	

	/*
	  二分查找
	  leetcode: 704
	 */
	// 闭区间
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
		while (left <= right) { // 当left==right，区间[left, right]依然有效，所以用 <=
			int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
			if (nums[middle] > target) {
				right = middle - 1; // target 在左区间，所以[left, middle - 1]
			} else if (nums[middle] < target) {
				left = middle + 1; // target 在右区间，所以[middle + 1, right]
			} else { // nums[middle] == target
				return middle; // 数组中找到目标值，直接返回下标
			}
		}
		// 未找到目标值
		return -1;
	}
	// 左闭右开 
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size(); // 定义target在左闭右开的区间里，即：[left, right)
		while (left < right) { // 因为left == right的时候，在[left, right)是无效的空间，所以使用 <
			int middle = left + ((right - left) >> 1);
			if (nums[middle] > target) {
				right = middle; // target 在左区间，在[left, middle)中
			} else if (nums[middle] < target) {
				left = middle + 1; // target 在右区间，在[middle + 1, right)中
			} else { // nums[middle] == target
				return middle; // 数组中找到目标值，直接返回下标
			}
		}
		// 未找到目标值
		return -1;
	}

// 	35 搜索插入位置
	int searchInsert(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size(); i++) {
			// 分别处理如下三种情况
			// 目标值在数组所有元素之前
			// 目标值等于数组中某一个元素
			// 目标值插入数组中的位置
			if (nums[i] >= target) { // 一旦发现大于或者等于target的num[i]，那么i就是我们要的结果
				return i;
			}
		}
		// 目标值在数组所有元素之后的情况
		return nums.size(); // 如果target是最大的，或者 nums为空，则返回nums的长度
	}
// 	34. 在排序数组中查找元素的第一个和最后一个位置
	class Solutions {
	public:
		vector<int> searchRange(vector<int>& nums, int target) {
			int leftBorder = getLeftBorder(nums, target);
			int rightBorder = getRightBorder(nums, target);
			// 情况一
			if (leftBorder == -2 || rightBorder == -2) return {-1, -1};
			// 情况三
			if (rightBorder - leftBorder > 1) return {leftBorder + 1, rightBorder - 1};
			// 情况二
			return {-1, -1};
		}
	private:
		int getRightBorder(vector<int>& nums, int target) {
			int left = 0;
			int right = nums.size() - 1;
			int rightBorder = -2; // 记录一下rightBorder没有被赋值的情况
			while (left <= right) {
				int middle = left + ((right - left) / 2);
				if (nums[middle] > target) {
					right = middle - 1;
				} else { // 寻找右边界，nums[middle] == target的时候更新left
					left = middle + 1;
					rightBorder = left;
				}
			}
			return rightBorder;
		}
		int getLeftBorder(vector<int>& nums, int target) {
			int left = 0;
			int right = nums.size() - 1;
			int leftBorder = -2; // 记录一下leftBorder没有被赋值的情况
			while (left <= right) {
				int middle = left + ((right - left) / 2);
				if (nums[middle] >= target) { // 寻找左边界，nums[middle] == target的时候更新right
					right = middle - 1;
					leftBorder = right;
				} else {
					left = middle + 1;
				}
			}
			return leftBorder;
		}
	};
// 	69. x 的平方根 
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
// 	367.有效的完全平方数
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
	  暴力 && 双指针
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
	 * 相向双指针方法，基于元素顺序可以改变的题目描述改变了元素相对位置，确保了移动最少元素
	 * 时间复杂度：O(n)
	 * 空间复杂度：O(1)
	 */
	int removeElement(vector<int>& nums, int val) {
		int leftIndex = 0;
		int rightIndex = nums.size() - 1;
		while (leftIndex <= rightIndex) {
			// 找左边等于val的元素
			while (leftIndex <= rightIndex && nums[leftIndex] != val){
				++leftIndex;
			}
			// 找右边不等于val的元素
			while (leftIndex <= rightIndex && nums[rightIndex] == val) {
				-- rightIndex;
			}
			// 将右边不等于val的元素覆盖左边等于val的元素
			if (leftIndex < rightIndex) {
				nums[leftIndex++] = nums[rightIndex--];
			}
		}
		return leftIndex;   // leftIndex一定指向了最终数组末尾的下一个元素
	}
//	26.删除排序数组中的重复项
	int removeDuplicates(vector<int>& nums) {
		int slow = 0;
		for (int fast = 0; fast < nums.size(); fast++) {
			if (nums[fast] != nums[slow]) nums[++slow] = nums[fast];
		}
		return ++slow;
	}
//	283.移动零
	void moveZeroes(vector<int>& nums) {
		int slow = 0;
		for (int cur = 0; cur < nums.size(); cur++) {
			if (nums[cur] != 0) nums[slow++] = nums[cur];
		}
		for (int cur = slow+1; slow < nums.size(); slow++) {
			nums[slow] = 0;
		}
	} 
//	844.比较含退格的字符串
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
	977 有序数组的平方
	 */
	vector<int> sortedSquares(vector<int>& A) {
		int k = A.size() - 1;
		vector<int> result(A.size(), 0);
		for (int i = 0, j = A.size() - 1; i <= j;) { // 注意这里要i <= j，因为最后要处理两个元素
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
	209 长度最小的子数组
	*/
	int minSubArrayLen(int s, vector<int>& nums) {
		int result = INT32_MAX;
		int sum = 0; // 滑动窗口数值之和
		int i = 0; // 滑动窗口起始位置
		int subLength = 0; // 滑动窗口的长度
		for (int j = 0; j < nums.size(); j++) {
			sum += nums[j];
			// 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
			while (sum >= s) {
				subLength = (j - i + 1); // 取子序列的长度
				result = result < subLength ? result : subLength;
				sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
			}
		}
		// 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
		return result == INT32_MAX ? 0 : result;
	}
//	904.水果成篮
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
//	76. 最小覆盖子串
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
	59 螺旋矩阵II
	 */
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0)); // 使用vector定义一个二维数组
		int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
		int loop = n / 2; // 每个圈循环几次，例如n为奇数3，那么loop = 1 只是循环一圈，矩阵中间的值需要单独处理
		int mid = n / 2; // 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
		int count = 1; // 用来给矩阵中每一个空格赋值
		int offset = 1; // 需要控制每一条边遍历的长度，每次循环右边界收缩一位
		int i,j;
		while (loop --) {
			i = startx;
			j = starty;
			
			// 下面开始的四个for就是模拟转了一圈
			// 模拟填充上行从左到右(左闭右开)
			for (j = starty; j < n - offset; j++) {
				res[startx][j] = count++;
			}
			// 模拟填充右列从上到下(左闭右开)
			for (i = startx; i < n - offset; i++) {
				res[i][j] = count++;
			}
			// 模拟填充下行从右到左(左闭右开)
			for (; j > starty; j--) {
				res[i][j] = count++;
			}
			// 模拟填充左列从下到上(左闭右开)
			for (; i > startx; i--) {
				res[i][j] = count++;
			}
			
			// 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
			startx++;
			starty++;
			
			// offset 控制每一圈里每一条边遍历的长度
			offset += 1;
		}
		
		// 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
		if (n % 2) {
			res[mid][mid] = count;
		}
		return res;
	}

//	54.螺旋矩阵	
	
//	剑指Offer 29.顺时针打印矩阵
	
};

int main() {
	return 0;
}
