/*
* Author: joannechen1223
* Date: 2021.01.16
* Note: https://hackmd.io/FmFNE7XBR36IP3X72tVqXw?view
*/


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int target = -1;
        for (int i = nums.size() - 1; i >= 1; i --) {
            if (nums[i-1] < nums[i]) {
                target = i-1;
                break;
            }
        }
        if (target != -1)  {
            for (int i = nums.size() - 1; i > target; i --) {
                if (nums[i] > nums[target]) {
                    swap(nums[i], nums[target]);
                    break;
                }
            }
        }
        reverse(nums, target + 1);
        
        return;
    }
    
    void reverse(vector<int> & nums, int start) {
        int end = nums.size() - 1;
        while (start < end) {
            swap(nums[start], nums[end]);
            start ++;
            end --;
        }
    }
};