class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, n = height.size();
        int max_i = 0, max_n = -1;
        for(int i = 0; i < n; i++)
        {
            if(height[i] > max_n)
            {
                max_i = i;
                max_n = height[i];
            }
        }
        int max_cur = -1;
        for(int i = 0; i < max_i; i++)
        {
            if(max_cur < height[i])
                max_cur = height[i];
            ans += max_cur - height[i];
        }
        max_cur = -1;
        for(int i = n - 1; i > max_i; i--)
        {
            if(max_cur < height[i])
                max_cur = height[i];
            ans += max_cur - height[i];
        }
        return ans;
    }
};
