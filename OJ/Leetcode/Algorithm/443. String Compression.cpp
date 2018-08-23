class Solution {
public:
    int compress(vector<char>& chars) {
        chars.push_back(-1);
        string ans = "";
        int num = 0;
        char pre = -1;
        for(int i = 0; i < chars.size(); i++)
        {
            if(chars[i] == pre)
                num++;
            else
            {
                ans += pre;
                if(num != 1)
                    ans += to_string(num);
                pre = chars[i];
                num = 1;
            }
        }
        ans = ans.substr(2);
        for(int i = 0 ; i < ans.length(); i++)
            chars[i] = ans[i];
        return ans.length();
    }
};
