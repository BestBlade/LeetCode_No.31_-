/*------------------------------------------------------------------|
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下|
一个更大的排列。													|
																	|
如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排	|
列）。																|
																	|
必须原地修改，只允许使用额外常数空间。								|
																	|
以下是一些例子，输入位于左侧列，其相应输出位于右侧列。				|
1,2,3 → 1,3,2														|
3,2,1 → 1,2,3														|
1,1,5 → 1,5,1														|
																	|
来源：力扣（LeetCode）												|
链接：https://leetcode-cn.com/problems/next-permutation				|
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	反向查找法
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了93.73%的用户
*	内存消耗：12.1 MB, 在所有 C++ 提交中击败了71.77%的用户
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

void nextPermutation(vector<int>& nums) 
{
	int i = 0;
	for (i = nums.size() - 2; i >= 0; i--)
	{
		if (nums[i] >= nums[i + 1])
		{
			continue;
		}
		else
		{
			break;
		}
	}	
	if (i == -1)																				/*	当i == -1 是说明整个nums都是倒序的，用reverse要比sort快	*/
	{
		reverse(nums.begin(), nums.end());
		return;
	}
	else
	{
		for (int j = nums.size() - 1; j > i; j--)												/*	当i存在时，倒序查找j使得nums[j]比nums[i]大，调换两者顺序，再把i+1之后的元素reverse，因为i是通过倒序的方式查找到的	*/
		{
			if (nums[j] > nums[i])
			{
				swap(nums[j], nums[i]);
				reverse(nums.begin() + i + 1, nums.end());
				return;
			}
		}
	}
	return;
}

int main()
{
	vector<int> nums = { 1,3,2};
	nextPermutation(nums);
}