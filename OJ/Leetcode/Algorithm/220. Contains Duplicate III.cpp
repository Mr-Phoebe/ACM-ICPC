class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() < 2 || t < 0 || k < 0)
            return false;
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++)
        {
            int value = getValue(nums[i], t);
            if(value != 0)
            {
                if(mp.find(value) != mp.end())
                    return true;
                if(mp.find(value+1) != mp.end() && abs(mp[value+1] - nums[i]) <= t)
                    return true;
                if(mp.find(value-1) != mp.end() && abs(mp[value-1] - nums[i]) <= t)
                    return true;
            }
            else if(value == 0 && mp.find(value) != mp.end())
                return true;
            mp[value] = nums[i];
            if(i >= k)
                mp.erase(getValue(nums[i-k], t));
        }
        return false;
    }
private:
    int getValue(int value, int t)
    {
        if(t == 0)
            return value;
        return floor(value*1.0 / t);
    }
};
