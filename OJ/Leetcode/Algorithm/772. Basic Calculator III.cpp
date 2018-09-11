class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return getExp(s, i);
    }
private:
    int getExp(const string& s, int& i)
    {
        vector<int> nums;
        char op = '+';
        for(; i < s.length() && op != ')'; i++)
        {
            if(s[i] == ' ')
                continue;
            int cur = s[i] == '(' ? getExp(s, ++i) : getNum(s, i);
            if(op == '+')
            {
                nums.emplace_back(cur);
            }
            else if(op == '-')
            {
                nums.emplace_back(-cur);
            }
            else if(op == '*')
            {
                nums.back() *= cur;
            }
            else if(op == '/')
            {
                nums.back() /= cur;
            }
            op = s[i];
        }

        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
            ans += nums[i];
        return ans;
    }

    int getNum(const string& s, int& i)
    {
        int ans = 0;
        for(; i < s.length() && isdigit(s[i]); i++)
        {
            ans *= 10;
            ans += s[i]-'0';
        }
        return ans;
    }
};
