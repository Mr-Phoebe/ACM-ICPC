class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        map<int, int> pos;
        vector<vector<int>> nextJump(n+1, vector<int>(2, -1));
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
        pos[arr[n-1]] = n-1;
        dp[n-1][0] = dp[n-1][1] = 1;
        for(int i = n - 2; i >= 0; i--) {
            auto posEven = pos.upper_bound(arr[i]);
            if(posEven != pos.begin()) {
                nextJump[i][0] = prev(posEven)->second;    
            }               
            auto posOdd = pos.lower_bound(arr[i]);
            if(posOdd != pos.end()) {
                nextJump[i][1] = posOdd->second;
            }
            pos[arr[i]] = i;
        }
        int ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(nextJump[i][1] != -1)
                dp[i][1] |= dp[nextJump[i][1]][0];
            if(nextJump[i][0] != -1)
                dp[i][0] |= dp[nextJump[i][0]][1];
            if(dp[i][1] == 1)
                ans++;
        }
        return ans;
    }
};