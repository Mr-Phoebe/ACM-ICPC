class Solution {
public:
    string reorganizeString(string S) {
        int maxx = 0, c;
        int n = S.length();
        map<int, int> mp;
        for(int i = 0 ; i < n; i++)
        {
            mp[S[i]]++;
            if(mp[S[i]] > maxx)
            {
                maxx = mp[S[i]];
                c = S[i];
            }
        }
        if(maxx > (n+1)/2)
            return "";
        int even = 0, odd = 1;
        string ans(S.length(), ' ');
        for(int i = 0; i < maxx; i++, even+=2)
            ans[even] = c;
        mp[c] = 0;

        for(int i = 'a'; i <= 'z'; i++)
        {
            while(mp[i] > 0)
            {
                if(even < n)
                {
                    ans[even] = i;
                    even+=2;
                }
                else
                {
                    ans[odd] = i;
                    odd+=2;
                }
                mp[i]--;
            }
        }
        return ans;
    }
};
