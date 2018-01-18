class Solution {
    vector<int> num;
public:
    Solution(vector<int> nums) {
        num = nums;
    }
    
    int pick(int target) {
        int n = 0;
        int ans = -1;
        for(int i = 0; i < num.size(); i++)
        {
            if(target == num[i])
            {
                if(n==0)
                {
                    ans = i;
                    n++;
                }
                else
                {
                    n++;
                    if(rand()%n == 0)   ans = i;
                }
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
