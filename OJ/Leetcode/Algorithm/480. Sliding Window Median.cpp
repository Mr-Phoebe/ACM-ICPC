class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> heap(nums.begin(), nums.begin() + k);
        auto mid = next(heap.begin(), k / 2);
        vector<double> medians;
        int n = nums.size();
        for(int i = k; ; i++)
        {
            medians.emplace_back((1.0 * *mid + *prev(mid, 1-k%2)) / 2.0);

            if(i == n)
                return medians;

            heap.insert(nums[i]);
            if(*mid > nums[i])
                mid--;
            if (nums[i-k] <= *mid)
                mid++;
            heap.erase(heap.lower_bound(nums[i-k]));
        }
        return medians;
    }
};
