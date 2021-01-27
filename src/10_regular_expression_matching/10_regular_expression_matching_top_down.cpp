/*
* Author: joannechen1223
* Date: 2021.01.27
* Note: https://hackmd.io/@jmmVOLEvQViVzHCqRCzKww/rJCxMsKJd
*/


class Solution {
public:
    bool isMatch(string s, string p) {
        _s = s;
        _p = p;
        initialize();
        return isMatchHelper(0, 0);
    }
    
private:
    string _s;
    string _p;
    vector<vector<int>> _dp;
    
    void initialize() {
        for (int i = 0; i < _s.length() + 1; i ++) {
            vector<int> v(_p.length() + 1, -1);
            _dp.push_back(v);
        }
    }
    
    bool isMatchHelper(int sIdx, int pIdx) {
        if (_dp[sIdx][pIdx] != -1) {
            return bool(_dp[sIdx][pIdx]);
        }
        if (sIdx == _s.length() && pIdx == _p.length())    return true;
        
        bool firstMatch = sIdx < _s.length() && pIdx < _p.length() && (_p[pIdx] == '.' || _s[sIdx] == _p[pIdx]);
        
        if (pIdx < _p.length() - 1 && _p[pIdx + 1] == '*') {
            if (isMatchHelper(sIdx, pIdx + 2)) {
                _dp[sIdx][pIdx] = 1;
                return true;
            }
            if (firstMatch && isMatchHelper(sIdx + 1, pIdx)) {
                _dp[sIdx][pIdx] = 1;
                return true;
            }
        } else if (firstMatch && isMatchHelper(sIdx + 1, pIdx + 1)) {
            _dp[sIdx][pIdx] = 1;
            return true;
        }
        _dp[sIdx][pIdx] = 0;
        return false;
    }
};