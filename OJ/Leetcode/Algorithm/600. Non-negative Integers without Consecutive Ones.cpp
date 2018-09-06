class Solution {
public:
    int findIntegers(int num) {
        vector<int> bits;
        for (; num > 0; num >>= 1)
            bits.push_back(num & 1);
        int n = bits.size();

        vector<int> one(n, 0), zero(n, 0);
        one[0] = zero[0] = 1;
        for(int i = 1; i < n; i++)
        {
            one[i] = zero[i - 1];
            zero[i] = zero[i - 1] + one[i - 1];
        }

        int ans = zero[n - 1] + one[n - 1];
        for(int i = n - 2; i >= 0; i--)
            if(bits[i] == 0 && bits[i + 1] == 0)
                ans -= one[i];
            else if(bits[i] == 1 && bits[i + 1] == 1)
                break;
        return ans;
    }
};
