class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())   return 0;
        vector<int> dp;
        vector<int> magic;
        for (int i = 0; i < nums.size(); i ++) {
            int lis = 1;
            for (int j = magic.size() - 1; j >= 0; j --) {
                if (magic[j] < nums[i]) {
                    lis = j + 1 + 1;
                    break;
                }
            }
            dp.push_back(lis);
            if (lis - 1 == magic.size())    magic.push_back(nums[i]);
            else    magic[lis - 1] = nums[i];
        }
        int max = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (dp[i] > max)  max = dp[i];
        }
        return max;
    }
};