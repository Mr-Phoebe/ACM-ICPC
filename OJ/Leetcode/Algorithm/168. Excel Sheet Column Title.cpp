class Solution {
public:
    string convertToTitle(int n) {
        if(n <= 26)
            return string(1, 'A'+n-1);
        else
        {
            string pre = convertToTitle((n-1)/26);          
            return pre+string(1, 'A'+(n-1)%26);
        }
    }
};