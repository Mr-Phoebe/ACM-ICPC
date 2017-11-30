class Solution {
    void getResult(vector<vector<int>> &result,vector<int> &row,int n)
    {
        int i=row.empty()?2:row.back();
        for(;i<=n/i;i++)
        {
            if(n%i==0)
            {
                row.push_back(i);
                row.push_back(n/i);
                result.push_back(row);
                row.pop_back();
                getResult(result,row,n/i);
                row.pop_back();
            }
        }
    }
public:    
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        vector<int>row;
        getResult(result,row,n);
        return result;
    }
};
