class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> mp;
        stack<int> st;
        for(auto num : nums)
        {
            while(!st.empty() && st.top() < num)
            {
                mp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        vector<int> ans(findNums.size(), -1);
        for(int i = 0; i < findNums.size(); i++)
        {
            if(mp.find(findNums[i]) != mp.end())
            {
                ans[i] = mp[findNums[i]];
            }
            else
            {
                ans[i] = -1;
            }
        }
        return ans;
    }
};
