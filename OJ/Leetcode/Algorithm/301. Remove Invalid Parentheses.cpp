/*
* @Author: Haonan Wu
* @Date:   2017-10-06 08:15:40
* @Last Modified by:   Haonan Wu
* @Last Modified time: 2017-10-06 08:15:54
*/

class Solution
{
private:
    vector<string> res;
    string p= {'(',')'};
    void helper(string& s, int si, int sj, int rev)
    {
        int stn=0;
        for(int i=si; i<s.size(); i++)
        {
            if(s[i]==p[rev]) stn++;
            else if(s[i]==p[1-rev]) stn--;
            if(stn<0)
            {
                for(int j=sj; j<=i; j++)
                {
                    if(s[j]==p[1-rev] && (j==sj || s[j-1]!=p[1-rev]))
                    {
                        string t=s.substr(0,j)+s.substr(j+1);
                        helper(t, i, j, rev);
                    }
                }
                return ;
            }
        }
        string rs=s;
        reverse(rs.begin(), rs.end());
        if(p[rev]=='(')
        {
            helper(rs, 0, 0, 1-rev);
        }
        else
        {
            res.push_back(rs);
        }
    }
public:
    vector<string> removeInvalidParentheses(string s)
    {
        res.clear();
        helper(s, 0, 0, 0);
        return res;
    }
};
