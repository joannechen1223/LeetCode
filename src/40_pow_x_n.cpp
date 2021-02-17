class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0)  return 1/posPow(x, (long long) n * (-1));
        return posPow(x, n);
    }
    
private:
    double posPow(double x, long long n) {
        if (n == 0)     return 1.0;
        double num = posPow(x, n/2);
        if (n % 2) {
            return num * num * x;
        }
        return num * num;
    }
};