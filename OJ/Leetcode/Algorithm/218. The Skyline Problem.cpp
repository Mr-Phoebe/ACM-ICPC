class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        int cur = 0, cur_X, cur_H = -1;
        int len = buildings.size();
        priority_queue<pair<int, int>> liveBlg; // first: height; second: end X

        while(cur < len || !liveBlg.empty() ) {
            // if either some new building is not processed or live building queue is not empty
            cur_X = liveBlg.empty()? buildings[cur][0] : liveBlg.top().second;
            // next critical point to process

            if(cur < len && buildings[cur][0] <= cur_X )
            {
                cur_X = buildings[cur][0];
                while(cur < len && buildings[cur][0] == cur_X )
                {
                    liveBlg.push(make_pair(buildings[cur][2], buildings[cur][1]));
                    cur++;
                }
            }
            else
            {
                while(!liveBlg.empty() && (liveBlg.top().second <= cur_X))
                    liveBlg.pop();

            }

            cur_H = liveBlg.empty()? 0 : liveBlg.top().first;
            if(res.empty() || (res.back().second != cur_H) )
                res.push_back(make_pair(cur_X, cur_H));
        }
        return res;
    }
};
