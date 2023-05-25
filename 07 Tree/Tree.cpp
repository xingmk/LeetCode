#include <bits/stdc++.h>

using namespace std;

class Greedy {
	// 455. 分发饼干
	class Solution {
	public:
		int findContentChildren(vector<int>& g, vector<int>& s) {
			sort(g.begin(), g.end());
			sort(s.begin(), s.end());
			//    int index = 0;
			//     for (int i = 0; i < s.size(); i++) { // 遍历饼干
			//         if (index < g.size() && g[index] <= s[i]) index++;
			//     }
			// return index;
			int index = s.size() - 1;
			int count = 0;
			for (int i = g.size() - 1; i >= 0; i--) { // 遍历胃口
				if (index >= 0 && s[index] >= g[i]) {
					index--;
					count++;
				}
			}
			return count;
		}
		
		// 53. 最大子数组和
		int maxSubArray(vector<int>& nums) {
			int result = INT32_MIN;
			int count = 0;
			for (int i = 0; i < nums.size(); i++) {
				count += nums[i];
				if (count > result) { // 取区间累计的最大值（相当于不断确定最大子序终止位置）
					result = count;
				}
				if (count <= 0) count = 0; // 相当于重置最大子序起始位置，因为遇到负数一定是拉低总和
			}
			return result;
		}
		// (动态规划)
		int maxSubArrays(vector<int>& nums) {
			int result = INT32_MIN;
			int count = 0;
			for (int i = 0; i < nums.size(); i++) {
				count += nums[i];
				if (count > result) { // 取区间累计的最大值（相当于不断确定最大子序终止位置）
					result = count;
				}
				if (count <= 0) count = 0; // 相当于重置最大子序起始位置，因为遇到负数一定是拉低总和
			}
			return result;
		}
};

int main() {

	return 0;
}
