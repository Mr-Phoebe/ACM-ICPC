class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int ans = 0, n = matrix.size(), m = matrix[0].size();
        int height[m+5] = {0};
        for (int i = 0; i < n; i++) 
        {
            stack<int> st;
            for(int j = 0; j < m+1; j++)
            {
                if(j<m)
                    height[j] = matrix[i][j] == '1'? height[j]+1:0;
                while (!st.empty() && height[st.top()] >= height[j]) {
                    int cur = st.top(); st.pop();
                    ans = max(ans, height[cur] * (st.empty() ? j : (j - st.top() - 1)));
                }
                st.push(j);
            }
                
        }
        return ans;
    }
};