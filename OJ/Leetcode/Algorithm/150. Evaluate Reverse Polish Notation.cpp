class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(auto& str : tokens)
        {
            if(isdigit(str[0]) || (str.length() > 1 && isdigit(str[1])))
            {
                st.push(stoi(str));
            }
            else
            {
                long long num2 = st.top();
                st.pop();
                long long num1 = st.top();
                st.pop();
                if(str[0] == '+')
                    num1 += num2;
                else if(str[0] == '-')
                    num1 -= num2;
                else if(str[0] == '*')
                    num1 *= num2;
                else if(str[0] == '/')
                    num1 /= num2;
                st.push(num1);
            }
        }
        return st.top();
    }
};
