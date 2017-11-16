class Solution {
    unordered_map<char, string> pDict;
    unordered_map<string, char> sDict;
    int n, m;
public:
    bool wordPatternMatch(string pattern, string str) {
        m = pattern.size();
        n = str.size();
        return match(pattern, 0, str, 0);
    }
    bool match(const string &pattern, int i,const string &str, int j) 
    {
        if(i == m || j == n)
            return (i == m && j == n);
        bool flag = false;
        for (int k = j; k < n; k++)
        {
            string s = str.substr(j, k - j + 1);
            if(pDict.find(pattern[i]) != pDict.end())
            {
                if(pDict[pattern[i]] != s)
                    continue;
            }
            else if(sDict.find(s) != sDict.end())
            {
                if(sDict[s] != pattern[i])
                    continue;
            }
            else
            {
                pDict[pattern[i]] = s;
                sDict[s] = pattern[i];
                flag = true;
            }
            if(match(pattern, i+1, str, k+1))
                return true;
            if(flag) 
            {
                pDict.erase(pattern[i]);
                sDict.erase(s);
            }
        }
        return false;
    }
};
