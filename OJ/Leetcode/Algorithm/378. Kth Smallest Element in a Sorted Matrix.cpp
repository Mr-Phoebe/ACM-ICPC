class Solution
{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int n = matrix.size();
        int le = matrix[0][0], ri = matrix[n - 1][n - 1];
        int mid = 0, ans;
        while (le < ri)
        {
            mid = le + ((ri - le) >> 1);
            int num = 0;
            for (int i = 0; i < n; i++)
                num += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            if (num < k)
                le = mid + 1;
            else
                ri = mid;
        }
        return le;
    }
};