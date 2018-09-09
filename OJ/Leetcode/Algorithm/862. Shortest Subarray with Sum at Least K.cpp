class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        deque<int> que;
        vector<long long> B(A.size()+1);
        int n = A.size();
        if(n == 0)
            return 0;
        B[0] = 0;
        for(int i = 1; i <= n; i++)
            B[i] = B[i-1] + A[i-1];
        int ans = INT_MAX;
        for(int i  = 0; i <= n; i++)
        {
            while(!que.empty() && B[i] - B[que.front()] >= K)
            {
                ans = min(ans, i - que.front());
                que.pop_front();
            }
            while(!que.empty() && B[i] <= B[que.back()])
            {
                que.pop_back();
            }
            que.push_back(i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
