class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        unsigned long long mi;
        if(n < 0)
        {
            mi = -n;
            x = 1 / x;
        }
        else
            mi = n;
        while(mi)
        {
            if(mi&1)  ans *= x;
            x *= x;
            mi>>=1;
        }
        return ans;
    }
};