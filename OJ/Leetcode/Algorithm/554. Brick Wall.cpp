class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> sum;
        int ans = 0, maxx = -1;
        int n = wall.size();
        int total = 0;
        for(int i = 0; i < n; i++)
        {
            int tmp = 0;
            for(auto num : wall[i])
            {
                tmp += num;
                sum[tmp]++;
            }
            sum[tmp]--;
        }
        for(auto num : sum)
        {
            if(num.second > maxx)
            {
                maxx = num.second;
                ans = n - maxx;
            }
        }
        return ans;
    }
};
