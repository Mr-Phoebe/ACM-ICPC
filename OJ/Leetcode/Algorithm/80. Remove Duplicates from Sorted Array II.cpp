class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size(), cnt = 0;
        for(int i = 2; i < size; i++)
        {
            if(nums[i] == nums[i-2-cnt]) cnt++;
            else nums[i-cnt] = nums[i];
        }
        return size-cnt;
    }
};