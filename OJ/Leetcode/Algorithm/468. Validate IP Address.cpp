class Solution
{
  public:
    string validIPAddress(string IP)
    {
        int cnt = 0;
        if(IP.find('.') == string::npos) // IPV6
        {
            for(auto c : IP)
                if(c == ':')
                    cnt++;
            if(cnt != 7)
                return "Neither";
            vector<string> strs = split(IP, ":");
            if(strs.size() != 8)
            {
                return "Neither";
            }
            for(int i = 0; i < 8; i++)
            {
                if(strs[i].size() == 0 || strs[i].size() > 4)
                    return "Neither";
                for(auto c : strs[i])
                    if(!(isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f') ))
                        return "Neither";
            }
            return "IPv6";
        }
        else
        {
            for(auto c : IP)
                if(c == '.')
                    cnt++;
            if(cnt != 3)
                return "Neither";
            vector<string> strs = split(IP, ".");
            if(strs.size() != 4)
            {
                return "Neither";
            }
            for(int i = 0; i < 4; i++)
            {
                if(strs[i].size() == 0 || strs[i].size() > 3)
                    return "Neither";
                for(auto c : strs[i])
                    if(!isdigit(c))
                        return "Neither";
                int nums = stoi(strs[i]);
                if(nums < 0 || nums > 255)
                    return "Neither";
                if(to_string(nums) != strs[i])
                    return "Neither";
            }
            return "IPv4";
        }
    }

  private:
    vector<string> split(const string &s, const string &seperator)
    {
        vector<string> result;
        typedef string::size_type string_size;
        string_size i = 0;

        while (i != s.size())
        {
            //找到字符串中首个不等于分隔符的字母；
            int flag = 0;
            while (i != s.size() && flag == 0)
            {
                flag = 1;
                for (string_size x = 0; x < seperator.size(); ++x)
                    if (s[i] == seperator[x])
                    {
                        ++i;
                        flag = 0;
                        break;
                    }
            }

            //找到又一个分隔符，将两个分隔符之间的字符串取出；
            flag = 0;
            string_size j = i;
            while (j != s.size() && flag == 0)
            {
                for (string_size x = 0; x < seperator.size(); ++x)
                    if (s[j] == seperator[x])
                    {
                        flag = 1;
                        break;
                    }
                if (flag == 0)
                    ++j;
            }
            if (i != j)
            {
                result.push_back(s.substr(i, j - i));
                i = j;
            }
        }
        return result;
    }
};
