/*
* Author: joannechen1223
* Date: 2021.01.14
*/


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        permuteFromStartPoint(nums, 0);
        return _perm;
    }
    
private:
    vector<vector<int>> _perm;
    
    void permuteFromStartPoint(vector<int>& nums, int start) {
        if (start == nums.size() - 1) {
            _perm.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i ++) {
            swap(nums[start], nums[i]);
            permuteFromStartPoint(nums, start + 1);
            swap(nums[start], nums[i]);
        }
    }
};