class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end(), greater<char>());
        int cur = 0, pos;
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] != sortedStr[i])
            {
                cur = i;
                break;
            }
        }
        for(int i = cur; i < str.length(); i++)
            if(str[i] == sortedStr[cur])
                pos = i;
        swap(str[cur], str[pos]);
        return stoi(str);
    }
};
