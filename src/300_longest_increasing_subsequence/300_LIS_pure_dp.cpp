class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())   return 0;
        vector<int> dp;
        for (int i = 0; i < nums.size(); i ++) {
            int lis = 1;
            for (int j = 0; j < i; j ++) {
                if (nums[i] > nums[j] && dp[j] + 1 > lis)  lis = dp[j] + 1; 
            }
            dp.push_back(lis);
        }

        int max = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (dp[i] > max)  max = dp[i];
        }
        return max;
    }
};