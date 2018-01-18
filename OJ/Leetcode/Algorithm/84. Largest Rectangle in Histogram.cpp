class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(!n) return 0;
        int dp[n][2] = {0};
        priority_queue<pair<int, int> > que;
        // 左开右闭
        for(int i = 0; i < n; i++)
        {
            while(que.size() && que.top().first > heights[i])
            {
                pair<int, int> top = que.top();
                que.pop();
                dp[top.second][1] = i-top.second;
            }   
            que.push(make_pair(heights[i], i));
        }
        while(!que.empty())
        {
            pair<int, int> top = que.top();
            que.pop();
            dp[top.second][1] = n-top.second;
        }
        for(int i = n-1; i >= 0; i--)
        {
            while(que.size() && que.top().first > heights[i])
            {
                pair<int, int> top = que.top();
                que.pop();
                dp[top.second][0] = top.second-i-1;
            }   
            que.push(make_pair(heights[i], i));
        }
        while(!que.empty())
        {
            pair<int, int> top = que.top();
            que.pop();
            dp[top.second][0] = top.second;
        }
        int ans = -1;
        for(int i = 0; i < n; i++)
            ans = max(ans, (dp[i][0]+dp[i][1])*heights[i]);
        return ans;
    }
};