class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0;
        for(int i = 0; i < secret.length(); i++)
        {
            if(secret[i] == guess[i])
                A++;
        }
        int B = 0;
        sort(secret.begin(), secret.end());
        sort(guess.begin(), guess.end());
        int l = 0, r = 0;
        while(l < secret.length() && r < secret.length())
        {
            if(secret[l] < guess[r])
                l++;
            else if(secret[l] > guess[r])
                r++;
            else
                r++, l++, B++;
        }
        B -= A;
        return to_string(A) + "A" + to_string(B) + "B";
    }
};
