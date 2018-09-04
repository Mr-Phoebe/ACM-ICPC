class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for(auto num : nums)
        {
            if(st.find(num) == st.end())
                continue;
            st.erase(num);
            int pre = num-1, next = num+1;
            while(st.find(pre) != st.end()) st.erase(pre--);
            while(st.find(next) != st.end()) st.erase(next++);
            ans = max(ans, next - pre - 1);
        }
        return ans;
    }
};
