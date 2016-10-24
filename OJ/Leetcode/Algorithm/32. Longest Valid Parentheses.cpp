class Solution
{
    public:
        int longestValidParentheses(string s)
        {
            int res = 0, l = 0;
            stack<int> si;
            for(int i = 0; i < s.size(); i ++)
            {
                if(s[i] == '(')
                    si.push(i);
                else
                {
                    if(si.empty())
                    l = i + 1;
                    else
                    {
                        si.pop();
                        if(si.empty())
                            res = max(res, i - l + 1);
                        else
                            res = max(res, i - si.top());
                    }
                }
            }
            return res;
        }
 };