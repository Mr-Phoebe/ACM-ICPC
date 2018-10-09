class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.length())   return "0";
        stack<char> st;
        for(auto ch : num)
        {
            while(k > 0 && !st.empty() && st.top() > ch)
            {
                st.pop();
                k--;
            }
            st.push(ch);
        }
        while(k-- > 0)
            st.pop();
        string str = "";
        while(!st.empty())
        {
            str += string(1, st.top());
            st.pop();
        }
        bool flag = false;
        for(int i = str.length()-1; i >= 0; i--)
        {
            if(str[i] != '0')
            {
                str = str.substr(0, i+1);
                flag = true;
                break;
            }
        }
        if(!flag)
            return "0";
        reverse(str.begin(), str.end());
        return str;
    }
};
