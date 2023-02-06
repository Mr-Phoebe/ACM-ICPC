class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int n = text.length();
        vector<long> sumsuf(n+1, 0);
        for(int i = n-1; i >= 0; i--) {
            sumsuf[i] = sumsuf[i+1] + (text[i] == pattern[1] ? 1 : 0);
        }
        long sum1 = 0;
        long sum2 = sumsuf[0];
        long ans = 0;
        for(int i = 0; i < n; i++) {
            if(text[i] == pattern[0]) {
                sum1++;
                ans += sumsuf[i+1];
            }
        }
        ans += max(sum1, sum2);
        return ans;
    }
};