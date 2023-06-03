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
		// 1005 .K次取反后最大化的数组和
		static bool cmp(int a, int b) {
			return abs(a) > abs(b);
		}
		int largestSumAfterKNegations(vector<int>& A, int K) {
			sort(A.begin(), A.end(), cmp);       // 第一步
			for (int i = 0; i < A.size(); i++) { // 第二步
				if (A[i] < 0 && K > 0) {
					A[i] *= -1;
					K--;
				}
			}
			if (K % 2 == 1) A[A.size() - 1] *= -1; // 第三步
			int result = 0;
			for (int a : A) result += a;        // 第四步
			return result;
		}
		
		// 134 . 加油站
		// 暴力
		int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
			for (int i = 0; i < cost.size(); i++) {
				int rest = gas[i] - cost[i]; // 记录剩余油量
				int index = (i + 1) % cost.size();
				while (rest > 0 && index != i) { // 模拟以i为起点行驶一圈（如果有rest==0，那么答案就不唯一了）
					rest += gas[index] - cost[index];
					index = (index + 1) % cost.size();
				}
				// 如果以i为起点跑一圈，剩余油量>=0，返回该起始位置
				if (rest >= 0 && index == i) return i;
			}
			return -1;
		}
		// 贪心
		int canCompleteCircuits(vector<int>& gas, vector<int>& cost) {
			int curSum = 0;
			int min = INT_MAX; // 从起点出发，油箱里的油量最小值
			for (int i = 0; i < gas.size(); i++) {
				int rest = gas[i] - cost[i];
				curSum += rest;
				if (curSum < min) {
					min = curSum;
				}
			}
			if (curSum < 0) return -1;  // 情况1
			if (min >= 0) return 0;     // 情况2
			// 情况3
			for (int i = gas.size() - 1; i >= 0; i--) {
				int rest = gas[i] - cost[i];
				min += rest;
				if (min >= 0) {
					return i;
				}
			}
			return -1;
		}
		
		int canCompleteCircuitss(vector<int>& gas, vector<int>& cost) {
			int curSum = 0;
			int totalSum = 0;
			int start = 0;
			for (int i = 0; i < gas.size(); i++) {
				curSum += gas[i] - cost[i];
				totalSum += gas[i] - cost[i];
				if (curSum < 0) {   // 当前累加rest[i]和 curSum一旦小于0
					start = i + 1;  // 起始位置更新为i+1
					curSum = 0;     // curSum从0开始
				}
			}
			if (totalSum < 0) return -1; // 说明怎么走都不可能跑一圈了
			return start;
		}
	};
	
	int main() {
		
		return 0;
	}
