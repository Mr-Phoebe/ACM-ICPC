class Solution {
public:
    bool parseBoolExpr(string expression) {
        int pos = 0;
        bool ans =  parseBool(pos, expression);
        // cout<<pos << " " << expression.size()<<endl;
        return ans;
    }

    bool parseBool(int& i, const std::string expression) {
        while(i < expression.size()) {
            switch(expression[i++]) {
                case 't': return true;
                case 'f': return false;
                case '|':
                    return parseBoolRec(i, expression, false, '|');
                case '&':
                    return parseBoolRec(i, expression, true, '&');
                case '!':
                    return parseBoolRec(i, expression, true, '!');
            }
        }
        throw;
    }

    bool parseBoolRec(int& i, const std::string& expression, bool now, const char& type) {
        i++;
        for(; i < expression.size();) {
            // std::cout << expression[i] << std::endl;

            bool next = parseBool(i, expression);
            // std::cout << next << std::endl;
            switch(type) {
                case '|':
                    now = next || now;
                    break;
                case '&':
                    now = next && now;
                    break;
                case '!':
                    now = !next;
                    break;
            }
            if(expression[i] == ')') {
                break;
            }
            i++;
        }
        i++;
        return now;
    }
};