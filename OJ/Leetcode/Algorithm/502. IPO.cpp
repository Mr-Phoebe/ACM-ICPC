class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        auto cmp1 = [](const auto& a, const auto& b){return a.first < b.first;};
        auto cmp2 = [](const auto& a, const auto& b){return a.second > b.second;};
        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmp1)> q1(cmp1);
        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmp2)> q2(cmp2);

        for(int i = 0; i < Capital.size(); i++)
            q2.push(make_pair(Profits[i], Capital[i]));

        for(int i = 0; i < k; i++)
        {
            while(!q2.empty() && q2.top().second <= W)
            {
                q1.push(q2.top());
                q2.pop();
            }
            if(q1.empty())
                break;
            W += q1.top().first;
            q1.pop();
        }
        return W;
    }
};
