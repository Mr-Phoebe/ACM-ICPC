class Solution {
public:
    string toGoatLatin(string S) {

        vector<string> strs;
        SplitString(S, strs, " ");
        strs[0] = change(strs[0], judge(strs[0][0]), 1);
        for(int i = 1; i < strs.size(); i++)
        {
            strs[i] = change(strs[i], judge(strs[i][0]), i+1);
        }
        string ans = strs[0];
        for(int i = 1; i < strs.size(); i++)
            ans += " " + strs[i];
        return ans;
    }
private:
    string change(string s, bool flag, int num)
    {
        string a = "";
        while(num--)
        {
            a += "a";
        }
        if(flag)
        {
            return s + "ma" + a;
        }
        else
        {
            return s.substr(1) + s[0] + "ma" + a;
        }
    }
    bool judge(char a)
    {
        static const string str = "aeiouAEIOU";
        return str.find(a) != -1;
    }

    void SplitString(const string& s, vector<string>& v, const string& c)
    {
      std::string::size_type pos1, pos2;
      pos2 = s.find(c);
      pos1 = 0;
      while(std::string::npos != pos2)
      {
        v.push_back(s.substr(pos1, pos2-pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
      }
      if(pos1 != s.length())
        v.push_back(s.substr(pos1));
    }
};
