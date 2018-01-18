class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int count[26] = {0};
        for (char c : tasks)
            ++count[c - 'A'];
        
        sort(count, count+26);
        int i = 24;
        for ( ; i >= 0 && count[i] == count[25]; --i);
        
        return max((int)tasks.size(), (n+1)*(count[25]-1) + 25-i);
    }
};

/*

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int count = 0;
        for(auto e : tasks)
            mp[e]++;
        
        int ans = 0;
        for(auto e : mp)
            if(e.second == count)
                ans++;
            else if(e.second > count)
                ans = 1, count = e.second;
        ans += (count-1)*(n+1);
        return max((int)tasks.size(), ans);
    }
private:
    unordered_map<char,int> mp;
};
*/