/*
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

*/

#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int nums[]={};
    int target;
    int i, j;
    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                return { i, j };
            }
        }
    }
     return { i, j };

    return 0;
}
