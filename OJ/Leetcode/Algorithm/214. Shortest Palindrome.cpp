class Solution {
public:
    string shortestPalindrome(string s) {
        string sr(s);
        reverse(sr.begin(), sr.end());
        string ss = s + '#' + sr;
        int* fair = new int[ss.length()+5];
        memset(fair, 0, sizeof(fair));
        for(int i = 1; i < ss.length(); i++)
        {
            int tmp = fair[i-1];
            while(tmp && ss.at(tmp) != ss.at(i))  tmp = fair[tmp-1];
            if(ss.at(tmp) == ss.at(i))    tmp++;
            fair[i] = tmp;
        }
        return sr.substr(0, s.length() - fair[ss.length() - 1]) + s;
    }
};

