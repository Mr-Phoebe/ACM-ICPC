class Solution {
public:
    bool judgeCircle(string moves) {
        int a = 0, b = 0;
        for(const auto& c : moves) {
            if(c == 'U') {
                a++;
            } else if (c == 'D') {
                a--;
            } else if (c == 'R') {
                b++;
            } else if (c == 'L') {
                b--;
            }
        }
        return a == 0 && b == 0;
        
    }
};