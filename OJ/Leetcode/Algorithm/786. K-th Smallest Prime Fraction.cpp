class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        vector<int> ans;
        int n = A.size();

        auto cmp = [&A](auto& a, auto& b) {return A[a.first] * A[b.second] > A[a.second] * A[b.first];};
        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmp)> q(cmp);

        for(int i = 0; i < n; i++)
            q.push(make_pair(0, i));
        int cnt = 0;
        pair<int, int> frac;
        while(cnt < K)
        {
            cnt++;
            frac = q.top(); q.pop();
            if(frac.first + 1 >= frac.second) continue;
            q.push(make_pair(frac.first + 1, frac.second));
        }
        ans.push_back(A[frac.first]);
        ans.push_back(A[frac.second]);
        return ans;
    }
};
