public class Solution {
    public int candy(int[] ratings) {
        if(ratings == null || ratings.length == 0)
            return 0;
        int sum = 1, cnt = 0, base = 1;
        for(int i = 1; i < ratings.length; i++)
        {
            if(ratings[i] >= ratings[i-1])
            {
                if(cnt > 0)
                {
                    sum += cnt*(cnt+1)/2;
                    if(base <= cnt)
                        sum += cnt - base + 1;
                    base = 1; cnt = 0;
                }
                base = ratings[i] == ratings[i-1] ? 1 : base+1;
                sum += base;
            }
            else
            {
                cnt++;
            }
        }
        if(cnt > 0)
        {
            sum += cnt*(cnt+1)/2;
            if(base <= cnt)
                sum += cnt - base + 1;
        }
        return sum;
    }
}
