class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int precolor = -1, premin = 0, presecmin = 0;
        int n = costs.size();
        if(n == 0)
            return 0;
        int k = costs[0].size();
        for(int i = 0; i < n; i++)
        {
            int curcost = INT_MAX, cursecondcost = INT_MAX;
            int curcolor = -1;
            for(int j = 0; j < k; j++)
            {
                int curtmp = costs[i][j] + (j == precolor ? presecmin : premin);
                if(curtmp < curcost)
                {
                    cursecondcost = curcost;
                    curcost = curtmp;
                    curcolor = j;
                }
                else if(curtmp < cursecondcost)
                {
                    cursecondcost = curtmp;
                }
            }
            premin = curcost;
            presecmin = cursecondcost;
            precolor = curcolor;
        }
        return premin;
    }
};
