class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        vector<pair<int, int> > temp;
        for(int i = nums1.size() - 1; i >= 0; i--)
            temp.push_back(make_pair(nums1[i],1));
        for(int i = nums2.size() - 1; i >= 0; i--)
            temp.push_back(make_pair(nums2[i],2));
        sort(temp.begin(),temp.end());
        vector<pair<int,int> >::iterator iter = unique(temp.begin(),temp.end());
        temp.erase(iter,temp.end());
        int len = temp.size();
        for(int i = 0; i < len; i++)
        {
            if(i+1 < len && temp[i].first == temp[i+1].first)
                ans.push_back(temp[i++].first);
        }

        return ans;
    }
};
