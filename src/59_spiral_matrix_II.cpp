/*
* Author: joannechen1223
* Date: 2020.12.08
*/


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top = 0, left = 0, bottom = n-1, right = n-1;
        int row = 0, col = 0;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        string status = "top";
        for (int i = 1; i <= n*n; i ++) {
            ans[row][col] = i;
            if (status == "top") {
                if (++col == right) {
                    status = "right";
                    top ++;
                }
            } else if (status == "right") {
                if (++row == bottom) {
                    status = "bottom";
                    right --;
                }
            } else if (status == "bottom") {
                if (--col == left) {
                    status = "left";
                    bottom --;
                }
            } else if (status == "left") {
                if (--row == top) {
                    status = "top";
                    left ++;
                }
            }
        }
        return ans;
    }
};