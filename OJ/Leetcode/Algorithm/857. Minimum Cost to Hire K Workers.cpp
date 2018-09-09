class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<pair<double, int> > vec;
        int n = quality.size();
        for(int i = 0; i < n; i++)
        {
            vec.emplace_back(make_pair(1.0 * wage[i] / quality[i], quality[i]));
        }
        sort(vec.begin(), vec.end());
        priority_queue<int> que;
        int quality_sum = 0;
        double ans = 0.0;
        for(int i = 0; i < K; i++)
        {
            que.push(vec[i].second);
            quality_sum += vec[i].second;
        }
        ans = quality_sum * vec[K-1].first;
        for(int i = K; i < n; i++)
        {
            que.push(vec[i].second);
            quality_sum += vec[i].second;
            quality_sum -= que.top();
            que.pop();
            ans = min(ans, quality_sum * vec[i].first);
        }
        return ans;
    }
};
