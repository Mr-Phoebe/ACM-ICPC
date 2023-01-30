class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int N = special.size();
        int ans = 0 ;
        int i = 0 ; 
        
        ans = max(special[0]-bottom,top-special[N-1]) ;
        
        for(int i = 1; i < N; i++)
        {
            if(special[i] != special[i-1]+1)
                ans = max(ans, special[i] - special[i-1] - 1) ;
        }
        
        return ans;
    }
};