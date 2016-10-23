class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> result;
        vector<int> local(3,0);
        if(nums.size() < 3) return result;

        sort(nums.begin(), nums.end());
        if(nums[0]>0 || nums[nums.size()-1]<0) return result;

        int p1 = 1, p2=nums.size()-1;
        for(int i = 0; i < nums.size()-2; )
        {
            p1 = i+1;
            p2 = nums.size()-1;
            while(p1 < p2)
            {
                if(nums[i] + nums[p1] + nums[p2] == 0)
                {

                    local[0] = nums[i];
                    local[1] = nums[p1];
                    local[2] = nums[p2];
                    result.push_back(local);
                    do
                    {
                        --p2;
                    }
                    while(p2 > p1 && nums[p2] == nums[p2+1]);
                    do
                    {
                        ++p1;
                    }
                    while(p1 < p2 && nums[p1] == nums[p1-1]);
                }
                else if(nums[i] + nums[p1] + nums[p2] > 0)
                {
                    do
                    {
                        --p2;
                    }
                    while(p2 > p1 && nums[p2] == nums[p2+1]);
                }
                else
                {
                    do
                    {
                        ++p1;
                    }
                    while(p1 < p2 && nums[p1] == nums[p1-1]);
                }
            }
            do
            {
                ++i;
            }
            while(i < nums.size() && nums[i] == nums[i-1]);
        }
        return result;
    }
};
