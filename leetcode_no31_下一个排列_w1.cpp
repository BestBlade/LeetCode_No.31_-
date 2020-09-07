/*------------------------------------------------------------------|
ʵ�ֻ�ȡ��һ�����еĺ������㷨��Ҫ���������������������г��ֵ�������|
һ����������С�													|
																	|
�����������һ����������У��������������г���С�����У���������	|
�У���																|
																	|
����ԭ���޸ģ�ֻ����ʹ�ö��ⳣ���ռ䡣								|
																	|
������һЩ���ӣ�����λ������У�����Ӧ���λ���Ҳ��С�				|
1,2,3 �� 1,3,2														|
3,2,1 �� 1,2,3														|
1,1,5 �� 1,5,1														|
																	|
��Դ�����ۣ�LeetCode��												|
���ӣ�https://leetcode-cn.com/problems/next-permutation				|
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������|
-------------------------------------------------------------------*/

/*	������ҷ�
*
*	ִ����ʱ��4 ms, ������ C++ �ύ�л�����93.73%���û�
*	�ڴ����ģ�12.1 MB, ������ C++ �ύ�л�����71.77%���û�
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
	if (i == -1)																				/*	��i == -1 ��˵������nums���ǵ���ģ���reverseҪ��sort��	*/
	{
		reverse(nums.begin(), nums.end());
		return;
	}
	else
	{
		for (int j = nums.size() - 1; j > i; j--)												/*	��i����ʱ���������jʹ��nums[j]��nums[i]�󣬵�������˳���ٰ�i+1֮���Ԫ��reverse����Ϊi��ͨ������ķ�ʽ���ҵ���	*/
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