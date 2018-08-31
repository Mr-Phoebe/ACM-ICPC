class Solution {
public:

    int maxSubArrayLen(vector<int>& nums, int k) {
		unordered_map<int, int> mp; // sum->pos
		int n = nums.size(), sum = 0, ans = 0;
		mp[0] = -1; // for the situation of 0~i
		for (int i = 0; i < n; i++){
			sum += nums[i];
			if (mp.find(sum-k) != mp.end())
				ans = max(i - mp[sum-k], ans);
			if (mp.find(sum) == mp.end())
				mp[sum] = i;
		}
		return ans;
    }
};
