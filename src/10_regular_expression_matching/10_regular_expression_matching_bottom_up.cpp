/*
* Author: joannechen1223
* Date: 2021.01.27
* Note: https://hackmd.io/@jmmVOLEvQViVzHCqRCzKww/rJCxMsKJd
*/


class Solution {
public:
    bool isMatch(string s, string p) {
        initialize(s, p);
        for (int i = s.length(); i >= 0; i --) {
            for (int j = p.length(); j >= 0; j --) {
                if (i == s.length() && j == p.length()) {
                    _dp[i][j] = true;
                    continue;
                }
                
                bool firstMatch = i < s.length() && j < p.length() && (p[j] == '.' || s[i] == p[j]);
        
                if (j < p.length() - 1 && p[j+1] == '*') {
                    _dp[i][j] = _dp[i][j + 2] || (firstMatch && _dp[i + 1][j]);
                } else {
                    _dp[i][j] = firstMatch && _dp[i+1][j+1];
                }
            }
        }
        return _dp[0][0];
    }
    
private:
    vector<vector<bool>> _dp;
    
    void initialize(string s, string p) {
        for (int i = 0; i < s.length() + 1; i ++) {
            vector<bool> v(p.length() + 1, false);
            _dp.push_back(v);
        }
    }
};
