class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int i, j;
        for(i = k+1, j = 1; i > j; i--, j++)
        {
            ans.push_back(j);
            ans.push_back(i);
        }
        if(!(k&1))
            ans.push_back(j);
        for(i = k+2; i <= n; i++)
            ans.push_back(i);
        return ans;
    }
};
