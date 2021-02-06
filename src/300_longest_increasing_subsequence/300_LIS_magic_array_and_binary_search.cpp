class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())   return 0;
        vector<int> magic;
        for (int i = 0; i < nums.size(); i ++) {
            int lis = binarySearch(magic, nums[i]) + 1;
            if (lis - 1 == magic.size())    magic.push_back(nums[i]);
            else    magic[lis - 1] = nums[i];
        }
        return magic.size();
    }
    
    int binarySearch(vector<int>& v, int target) {
        int left = 0, right = v.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (v[mid] < target)    left = mid + 1;
            else    right = mid - 1;
        }
        return left;
    }
};