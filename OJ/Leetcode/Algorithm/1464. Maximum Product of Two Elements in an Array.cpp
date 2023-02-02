class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        for(auto n:nums){
            if(n > max1){
                max2 = max1;
                max1 = n;
            }
            else if(n > max2){
                max2 = n;
            }
        }
        return (max1 - 1) * (max2 - 1);
    }
};