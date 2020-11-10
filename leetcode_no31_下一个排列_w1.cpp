/* ------------------------------------------------------------------|
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	双指针法
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了93.93%的用户
*	内存消耗：12 MB, 在所有 C++ 提交中击败了51.49%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void nextPermutation(vector<int>& nums) {
    int len = nums.size() - 1;
    for (int i =len; i >= 0; i--) {
        if (i == 0) {
            reverse(nums.begin(),nums.end());
            return;
        }
        if (nums[i] > nums[i - 1]) {
            int val = nums[i - 1];
            for (int j = len; j >= i; j--) {
                if (nums[j] > val) {
                    swap(nums[j], nums[i - 1]);
                    reverse(nums.begin() + i, nums.end());
                    return;
                }
            }
        }
    }
    return;
}