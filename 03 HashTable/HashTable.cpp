#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	/*
	  242:	有效的字母异位词
	 */
	bool isAnagram(string s, string t) {
		int hash[26] = {0};
		// 统计s
		for (int i : s){
			hash[i - 'a']++;
		}
		// 统计t
		for (int j : t){
			hash[j - 'a']--;
		}
		// 判断hash
		for (int k : hash){
			if (k != 0) return false;
		}
		return true;
	}
	// 同上
	bool isAnagrams(string s, string t) {
	int record[26] = { 0 };
		for (int i = 0; i < s.size(); i++) {
		// 并不需要记住字符a的ASCII，只要求出一个相对数值就可以了
			record[s[i] - 'a']++;
		}
		for (int i = 0; i < t.size(); i++) {
			record[t[i] - 'a']--;
		}
		for (int i = 0; i < 26; i++) {
			if (record[i] != 0) {
			// record数组如果有的元素不为零0，说明字符串s和t 一定是谁多了字符或者谁少了字符。
				return false;
				}
		}
		// record数组所有元素都为零0，说明字符串s和t是字母异位词
		return true;
	}
	
	/*
	  349:    两个数组的交集
	 */
	// 数组
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
		int hash[1005] = {0}; // 默认数值为0
		for (int num : nums1) { // nums1中出现的字母在hash数组中做记录
			hash[num] = 1;
		}
		for (int num : nums2) { // nums2中出现话，result记录
			if (hash[num] == 1) {
				result_set.insert(num);
			}
		}
		return vector<int>(result_set.begin(), result_set.end());
	}
	// set
	vector<int> intersections(vector<int>&nums1, vector<int>&nums2) {
		unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
		unordered_set<int> nums_set(nums1.begin(), nums1.end());
		for (int num : nums2) {
			// 发现nums2的元素 在nums_set里又出现过
			if (nums_set.find(num) != nums_set.end()) {
				result_set.insert(num);
			}
		}
		return vector<int>(result_set.begin(), result_set.end());
	}

	/*
	  1   两数之和
	 */
	vector<int> twoSum(vector<int>& nums, int target) {
		std::unordered_map <int,int> map;
		for(int i = 0; i < nums.size(); i++) {
			// 遍历当前元素，并在map中寻找是否有匹配的key
			auto iter = map.find(target - nums[i]); 
			if(iter != map.end()) {
				return {iter->second, i};
			}
			// 如果没找到匹配对，就把访问过的元素和下标加入到map中
			map.insert(pair<int, int>(nums[i], i)); 
		}
		return {};
	}
	
	/*
	  454:   四数相加||
	 */
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		unordered_map<int, int> umap; //key:a+b的数值，value:a+b数值出现的次数
		// 遍历大A和大B数组，统计两个数组元素之和，和出现的次数，放到map中
		for (int a : A) {
			for (int b : B) {
				umap[a + b]++;
			}
		}
		int count = 0; // 统计a+b+c+d = 0 出现的次数
		// 在遍历大C和大D数组，找到如果 0-(c+d) 在map中出现过的话，就把map中key对应的value也就是出现次数统计出来。
		for (int c : C) {
			for (int d : D) {
				if (umap.find(0 - (c + d)) != umap.end()) {
					count += umap[0 - (c + d)];
				}
			}
		}
		return count;
	}
	/*
    383.  赎金信
	*/
	bool canConstruct(string ransomNote, string magazine) {
		int record[26] = {0};
		//add
		if (ransomNote.size() > magazine.size()) {
			return false;
		}
		for (int i = 0; i < magazine.length(); i++) {
			// 通过recode数据记录 magazine里各个字符出现次数
			record[magazine[i]-'a'] ++;
		}
		for (int j = 0; j < ransomNote.length(); j++) {
			// 遍历ransomNote，在record里对应的字符个数做--操作
			record[ransomNote[j]-'a']--;
			// 如果小于零说明ransomNote里出现的字符，magazine没有
			if(record[ransomNote[j]-'a'] < 0) {
				return false;
			}
		}
		return true;
	}

	/*
	  15:     三数之和
	 */
	// 双指针
	vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> result;
	sort(nums.begin(), nums.end());
	// 找出a + b + c = 0
	// a = nums[i], b = nums[left], c = nums[right]
	for (int i = 0; i < nums.size(); i++) {
		// 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
		if (nums[i] > 0) {
			return result;
		}
		// 错误去重a方法，将会漏掉-1,-1,2 这种情况
		/*
		  if (nums[i] == nums[i + 1]) {
		  continue;
		  }
		 */
		// 正确去重a方法
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		int left = i + 1;
		int right = nums.size() - 1;
		while (right > left) {
			// 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
			/*
			  while (right > left && nums[right] == nums[right - 1]) right--;
			  while (right > left && nums[left] == nums[left + 1]) left++;
			 */
			if (nums[i] + nums[left] + nums[right] > 0) right--;
			else if (nums[i] + nums[left] + nums[right] < 0) left++;
			else {
				result.push_back(vector<int>{nums[i], nums[left], nums[right]});
				// 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
				while (right > left && nums[right] == nums[right - 1]) right--;
				while (right > left && nums[left] == nums[left + 1]) left++;
				
				// 找到答案时，双指针同时收缩
				right--;
				left++;
			}
		}
		
	}
	return result;
}
	// Hash
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		// 找出a + b + c = 0
		// a = nums[i], b = nums[j], c = -(a + b)
		for (int i = 0; i < nums.size(); i++) {
			// 排序之后如果第一个元素已经大于零，那么不可能凑成三元组
			if (nums[i] > 0) {
				break;
			}
			if (i > 0 && nums[i] == nums[i - 1]) { //三元组元素a去重
				continue;
			}
			unordered_set<int> set;
			for (int j = i + 1; j < nums.size(); j++) {
				if (j > i + 2
					&& nums[j] == nums[j-1]
					&& nums[j-1] == nums[j-2]) { // 三元组元素b去重
					continue;
				}
				int c = 0 - (nums[i] + nums[j]);
				if (set.find(c) != set.end()) {
					result.push_back({nums[i], nums[j], c});
					set.erase(c);// 三元组元素c去重
				} else {
					set.insert(nums[j]);
				}
			}
		}
		return result;
	}
	
	/*
	18. 四数之和 
	*/
	// 双指针
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> result;
	sort(nums.begin(), nums.end());
	for (int k = 0; k < nums.size(); k++) {
		// 剪枝处理
		if (nums[k] > target && nums[k] >= 0) {
			break; // 这里使用break，统一通过最后的return返回
		}
		// 对nums[k]去重
		if (k > 0 && nums[k] == nums[k - 1]) {
			continue;
		}
		for (int i = k + 1; i < nums.size(); i++) {
			// 2级剪枝处理
			if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) {
				break;
			}
			
			// 对nums[i]去重
			if (i > k + 1 && nums[i] == nums[i - 1]) {
				continue;
			}
			int left = i + 1;
			int right = nums.size() - 1;
			while (right > left) {
				// nums[k] + nums[i] + nums[left] + nums[right] > target 会溢出
				if ((long) nums[k] + nums[i] + nums[left] + nums[right] > target) {
					right--;
					// nums[k] + nums[i] + nums[left] + nums[right] < target 会溢出
				} else if ((long) nums[k] + nums[i] + nums[left] + nums[right]  < target) {
					left++;
				} else {
					result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
					// 对nums[left]和nums[right]去重
					while (right > left && nums[right] == nums[right - 1]) right--;
					while (right > left && nums[left] == nums[left + 1]) left++;
					
					// 找到答案时，双指针同时收缩
					right--;
					left++;
				}
			}
			
		}
	}
	return result;
}
};


int main() {
	return 0;
}
