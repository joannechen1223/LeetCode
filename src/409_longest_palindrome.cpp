/*
* Author: joannechen1223
* Date: 2021.02.01
*/


class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> uppercase(26, 0);
        vector<int> lowercase(26, 0);
        for (int i = 0; i < s.length(); i ++) {
            if (isupper(s[i])) {
                uppercase[s[i] - 'A'] ++;
            } else {
                lowercase[s[i] - 'a'] ++;
            }
        }
        int rtn = 0;
        bool exist_odd = false;
        for (int i = 0; i < 26; i ++) {
            if (uppercase[i] % 2 || lowercase[i] % 2)   exist_odd = true;
            rtn += (uppercase[i]/2) * 2;
            rtn += (lowercase[i]/2) * 2;
        }
        if (exist_odd)   rtn ++;
        return rtn;
    }
};