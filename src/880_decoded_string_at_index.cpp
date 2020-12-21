/*
* Author: joannechen1223
* Date: 2020.12.21
* Note: Time complexity in O(n), and space complexity in O(1).
*/


class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long long size = 1;        // length of decoded string
        int breakPoint = K;
        for (int i = 1; i < S.length(); i ++) {
            if (!isdigit(S[i]))     size ++;
            else    size *= (S[i] - '0');
            
            if (size >= K) {
                breakPoint = i;
                break;
            }
        }
        for (int i = breakPoint; i >= 0; i --) {
            if (isdigit(S[i])) {
                size /= (S[i] - '0');
                K %= size;
            } else {
                if (K == 0 || K == size)     return string(1, S[i]);
                size --;
            }
        }
        return "";
    }
};