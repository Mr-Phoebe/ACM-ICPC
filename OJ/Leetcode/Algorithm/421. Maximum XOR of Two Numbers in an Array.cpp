class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        if(!n || n == 1)  return 0;
        int MAXN = n*32+10;
        Trie[0] = new int[MAXN];
        Trie[1] = new int[MAXN];
        val = new int[MAXN];
        Trie[0][0] = Trie[1][0] = val[0] = 0;
        int ans = 0;
        for(int i = 0; i < n; i++)
            insert(nums[i]);
        for(int i = 0; i < n; i++)
            ans = max(ans, query(nums[i]));
        return ans;
    }
private:
    int* Trie[2];
    int* val;
    int sz = 1;
    void insert(int v)
    {
        if(!v)  val[0] = -1;
        int u = 0;
        for(int i = 31; i >= 0; i--)
        {
            int c = 1&(v>>i);
            if(!Trie[c][u])
            {                
                Trie[0][sz] = Trie[1][sz] = val[sz] = 0;
                Trie[c][u] = sz++;
            }
            u = Trie[c][u];
        }
        val[u] = v;
    }
    int query(int v)
    {
        int u = 0;
        int ans = 0;
        for(int i = 31; i >= 0; i--)
        {
            int c = 1&(v>>i);
            if(Trie[c^1][u])          
                u = Trie[c^1][u], ans += (1<<i);
            else if(Trie[c][u])
                u = Trie[c][u];
            else
                break;
        }
        return ans;
    }
};