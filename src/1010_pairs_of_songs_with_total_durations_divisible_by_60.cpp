/*
* Author: joannechen1223
* Date: 2020.12.08
*/


class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int remain[60] = {0};
        for (int i = 0; i < time.size(); i ++) {
            remain[time[i]%60]++;
        }
        int ans = 0;
        ans += remain[0]*(remain[0]-1)/2;
        ans += remain[30]*(remain[30]-1)/2;
        for (int i = 1; i < 30; i ++) {
            ans += remain[i]*remain[60-i];
        }
        return ans;
    }
};