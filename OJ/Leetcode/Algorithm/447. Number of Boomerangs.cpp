class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = points.size();
        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            unordered_map<int, int> ha;
            for(int j = 0; j < n; j++)
                if(i!=j)
                    ha[dis(points[i].first, points[i].second, points[j].first, points[j].second)]++;

            for(auto& u : ha)
                if(u.second > 1)
                    ans += u.second*(u.second-1);
        }
            
        return ans;
    }
private:
    
    inline int dis(int i, int j, int x, int y)
    {
        return (i-x)*(i-x)+(j-y)*(j-y);
    }
};