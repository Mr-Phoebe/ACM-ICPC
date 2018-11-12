class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double> > v;
        map<int, double> m;
        for (int i = 0; i < position.size(); i++)
            v.push_back({-position[i], (double)(target - position[i]) / speed[i]});
        sort(v.begin(), v.end());
        int res = 0;
        double cur = 0;
        for(auto it : v)
            if(it.second > cur)
                cur = it.second, res++;
        return res;

    }
};
