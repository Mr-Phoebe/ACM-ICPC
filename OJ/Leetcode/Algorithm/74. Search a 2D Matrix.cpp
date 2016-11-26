class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())  return false;
        
        int n = matrix.size(); //行数
        int m = matrix[0].size();//列数
        
        if(matrix[0][0] > target || matrix[n-1][m-1] < target)  return false;
        int l = 0, r = n - 1;
        while(l <= r)
        {
            int mid = l + (r - l + 1 >> 1);
            if(matrix[mid][0] > target) r = mid - 1;
            else if(matrix[mid][0] < target) l = mid + 1;
            else return true;
        }
        int row = r; 
        l = 0, r = m - 1;
        while(l <= r)
        {
            int mid = l + (r - l >> 1);
            if(matrix[row][mid] > target) r = mid - 1;
            else if(matrix[row][mid] < target) l = mid + 1;
            else return true;
        }
        return false;
    }
};