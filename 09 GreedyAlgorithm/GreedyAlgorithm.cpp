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
		// 376. 摆动序列
		
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
		// 122.买卖股票的最佳时机 II
		int maxProfit(vector<int>& prices) {
			int result = 0;
			for (int i = 1; i < prices.size(); i++) {
				result += max(prices[i] - prices[i - 1], 0);
			}
			return result;
		}
		// 55. 跳跃游戏
		bool canJump(vector<int>& nums) {
			int cover = 0;
			if (nums.size() == 1) return true; // 只有一个元素，就是能达到
			for (int i = 0; i <= cover; i++) { // 注意这里是小于等于cover
				cover = max(i + nums[i], cover);
				if (cover >= nums.size() - 1) return true; // 说明可以覆盖到终点了
			}
			return false;
		}
	
		// 45. 跳跃游戏II
		int jump(vector<int>& nums) {
			if (nums.size() == 1) return 0;
			int curDistance = 0;    // 当前覆盖最远距离下标
			int ans = 0;            // 记录走的最大步数
			int nextDistance = 0;   // 下一步覆盖最远距离下标
			for (int i = 0; i < nums.size(); i++) {
				nextDistance = max(nums[i] + i, nextDistance);  // 更新下一步覆盖最远距离下标
				if (i == curDistance) {                         // 遇到当前覆盖最远距离下标
					ans++;                                  // 需要走下一步
					curDistance = nextDistance;             // 更新当前覆盖最远距离下标（相当于加油了）
					if (nextDistance >= nums.size() - 1) break;  // 当前覆盖最远距到达集合终点，不用做ans++操作了，直接结束
				}
			}
			return ans;
		}
		
		
		
		
		
		
		
	};
	
	int main() {
		
		return 0;
	}
