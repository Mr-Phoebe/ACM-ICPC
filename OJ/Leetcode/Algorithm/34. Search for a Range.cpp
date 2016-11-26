class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int first = 0, middle;
        int half, len;
        int size = nums.size();
        len = size;
    
        while(len > 0) {
            half = len >> 1;
            middle = first + half;
            if(nums[middle] < target) {     
                first = middle + 1;          
                len = len-half-1;       
            }
            else
                len = half;            
        }
        if(nums[first] != target)   first = -1;
        ans.push_back(first);
        first = 0;
        len = size;
        while(len > 0){
            half = len >> 1;
            middle = first + half;
            if(nums[middle] > target)     
                len = half;
            else{
                first = middle + 1;    
                len = len - half - 1;
            }
        }
        if(nums[first-1] != target)   first = 0;
        ans.push_back(first-1);
        return ans;
    }
};