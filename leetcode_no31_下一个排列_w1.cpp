/* ------------------------------------------------------------------|
ʵ�ֻ�ȡ��һ�����еĺ������㷨��Ҫ���������������������г��ֵ�������һ����������С�

�����������һ����������У��������������г���С�����У����������У���

����ԭ���޸ģ�ֻ����ʹ�ö��ⳣ���ռ䡣

������һЩ���ӣ�����λ������У�����Ӧ���λ���Ҳ��С�
1,2,3 �� 1,3,2
3,2,1 �� 1,2,3
1,1,5 �� 1,5,1

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/next-permutation
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������|
-------------------------------------------------------------------*/

/*	˫ָ�뷨
*
*	ִ����ʱ��4 ms, ������ C++ �ύ�л�����93.93%���û�
*	�ڴ����ģ�12 MB, ������ C++ �ύ�л�����51.49%���û�
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