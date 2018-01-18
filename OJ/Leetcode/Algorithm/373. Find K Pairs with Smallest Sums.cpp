#define mp(x,y) make_pair(x,y)
#define pb(x) emplace(x)
#define ls first
#define rs second
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.empty() || nums2.empty() || k <= 0) return res;
        auto comp = [&nums1, &nums2](pii a, pii b) {
            return nums1[a.ls] + nums2[a.rs] > nums1[b.ls] + nums2[b.rs];};
        priority_queue<pii, vii, decltype(comp)> que(comp);
        que.pb(mp(0,0));
        while(k-- && !que.empty())
        {
            pii cur = que.top();que.pop();
            res.push_back(mp(nums1[cur.ls], nums2[cur.rs]));
            if(cur.first + 1 < nums1.size())
                que.emplace(cur.first + 1, cur.second);
            if(cur.first == 0 && cur.second + 1 < nums2.size())
                que.emplace(cur.first, cur.second + 1);
        }
        return res;
    }
private:
    typedef pair<int, int> pii;
    typedef vector<pii> vii;
    vii res;
};
