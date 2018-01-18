class Solution {
public:
    int myAtoi(string str) {
        int result = 0;  
        bool isNegative = false;  
        int i = 0;
        while(str[i] == ' ')   
            i++;  
        if(str[i] == '+')   
            i++;  
        else if(str[i] == '-') {  
            isNegative = true;  
            i++;  
        }  
        while(str[i] != '\0') {  
            if (str[i] - '0' == 0 && result == 0) {  
                i++;  
                continue;  
            }  
            if (str[i] - '0' < 0 || str[i] - '9' > 0)  
                return isNegative? -result: result;  
            if (result > INT_MAX / 10)  
                return isNegative? INT_MIN : INT_MAX;  
            result *= 10;  
            if ((str[i] - '0') > (INT_MAX - result))  
                return isNegative? INT_MIN : INT_MAX;  
            result = result + str[i] - '0';  
            i++;  
        }  
        return isNegative? -result : result;  
    }
};