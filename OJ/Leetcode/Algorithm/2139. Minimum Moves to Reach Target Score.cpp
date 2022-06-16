class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int N = target;
        int k = maxDoubles;
        int res = 0;
        while(N>1)
        {
            if(!k)
                return res + N - 1 ;
            else if( N&1 )
            {
                res++;
                N--;
            }
            else if(k && !(N&1))
            {
                k--;
                N/=2;
                res++;
            }
        }
        return res; 
    }
};