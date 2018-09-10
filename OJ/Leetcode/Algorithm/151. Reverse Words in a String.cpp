class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        auto left = s.begin();
        auto right = s.begin();
        while(left < s.end())
        {
            while(right < s.end() && *right == ' ')
                right++;
            s.erase(left, right);
            right = left;
            while(right < s.end() && *right != ' ')
                right++;

            reverse(left, right);
            left = right+1;
            right = left;
        }

    }
};
