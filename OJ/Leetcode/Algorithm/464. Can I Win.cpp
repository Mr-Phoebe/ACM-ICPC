class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger >= desiredTotal)
            return true;
        int sum = ((maxChoosableInteger + 1) * maxChoosableInteger) >> 1;
        if(sum < desiredTotal)
            return false;
        return dp(0, maxChoosableInteger, desiredTotal);
    }
private:
    unordered_map<int, bool> mp;
    bool dp(int used, const int &maxChoosableInteger, int desiredTotal) {
        if(mp.find(used) != mp.end())
            return mp[used];
        for(int i = 1; i <= maxChoosableInteger; i++)
        {
            int bits = 1<<(i-1);
            if((used & bits) != 0)
                continue;
            if(i >= desiredTotal || !dp(used | bits, maxChoosableInteger, desiredTotal - i))
            {
                mp[used] = true;
                return true;
            }
        }
        mp[used] = false;
        return false;
    }

};
