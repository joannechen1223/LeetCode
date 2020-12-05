/*
* Author: joannechen1223
* Date: 2020.12.06
*/


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int space = 0;
        for (int i = 0; i < flowerbed.size(); i ++) {
            if (flowerbed[i] == 0) {
                bool left = (i == 0) || (flowerbed[i-1] == 0);
                bool right = (i == flowerbed.size() - 1) || (flowerbed[i+1] == 0);
                if (left && right) {
                    space ++;
                    i ++;
                    if (space >= n) return true;
                }
            }
        }
        return space >= n;
    }
};