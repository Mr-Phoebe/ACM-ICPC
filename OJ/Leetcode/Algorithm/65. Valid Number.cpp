class Solution {
public:
    bool isNumber(string s) {
        bool hasE = false;
        bool afterE = true;
        bool beforeE = false;
        bool hasDot = false;
        ltrim(s);
        rtrim(s);
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                beforeE = true;
                afterE = true;
            }
            else if(s[i] == '.')
            {
                if(hasE || hasDot)
                    return false;
                hasDot = true;
            }
            else if(s[i] == 'e' || s[i] == 'E')
            {
                if(!beforeE || hasE)
                    return false;
                hasE = true;
                afterE = false;
            }
            else if(s[i] == '+' || s[i] == '-')
            {
                if(i != 0 && s[i-1] != 'e' && s[i-1] != 'E')
                    return false;
            }
            else
                return false;

        }
        return beforeE && afterE;
    }
private:
    // trim from start (in place)
    static inline void ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
            return !std::isspace(ch);
        }));
    }

    // trim from end (in place)
    static inline void rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
            return !std::isspace(ch);
        }).base(), s.end());
    }
};
