class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = k;

        while(l <= r)
        {
            int mid = l + (r-l>>1);
            if(count(mid, n, m) >= k)
                r = mid-1;
            else
                l = mid+1;
        }
        return l;
    }
private:
    int count(int num, int n, int m)
    {
        int cnt = 0;
        for(int i = 1; i <= n; i++)
            cnt += min(m, num/i);
        printf("%d\n", cnt);
        return cnt;
    }
};
