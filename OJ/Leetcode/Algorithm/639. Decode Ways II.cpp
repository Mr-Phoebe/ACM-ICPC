class Solution {
    const int MOD = 1e9+7;
    int get_number(string s)
    {
        if(s.size() == 1) 
        {
            if(s[0] == '*')         return 9;
            else if(s[0] >= '1')    return 1;
            else                    return 0;
        }
        if(s == "**")  
            return 15;
        else if(s[1] == '*') 
        {
            if(s[0] == '1')         return 9;
            else if(s[0] == '2')    return 6;
            else                    return 0;
        }
        else if(s[0] == '*')
        {
            if(s[1] <= '6')         return 2;
            else                    return 1;
        }
        else if(s[1] <= '6')
        {
            if(s[0] == '1' || s[0] == '2')  return 1;
            else                    return 0;
        }
        else if(s[0] == '1')
            return 1;
        else
            return 0;
    }
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        long long dp1 = 1, dp2 = get_number(s.substr(0,1));
        for (int i = 1; i < s.length(); i++) {
            long long dp3 = (dp2*get_number(s.substr(i, 1)))+(dp1*get_number(s.substr(i-1, 2)));
            dp1 = dp2;
            dp2 = dp3%MOD;
        }
        return dp2;
    }
};


