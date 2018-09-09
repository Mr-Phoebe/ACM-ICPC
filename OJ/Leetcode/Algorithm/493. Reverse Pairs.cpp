class Solution {
public:
    int reversePairs(vector<int>& nums) {
        ans = 0;
        mergeSort(nums, 0, nums.size()-1);
        return ans;
    }
private:
    int ans;
    void mergeSort(vector<int>& nums, int left, int right)
    {
        if(right <= left)
            return;
        int mid = left + ((right - left)>>1);
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);

        int count = 0;
        for(int l = left, r = mid+1; l <= mid;)
            if(r > right || nums[l] <= 2LL*nums[r])
                l++, ans += count;
            else
                r++, count++;

        sort(nums.begin()+left, nums.begin()+right+1);
    }
};
