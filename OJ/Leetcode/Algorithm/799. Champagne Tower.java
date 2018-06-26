class Solution {
    public double champagneTower(int poured, int query_row, int query_glass) {
        if(poured <= 0) return (double)0;
        Queue<Double> q = new LinkedList<>();

        double p = ((double)poured);
        q.offer(p);
        int level = 0;
        while(level < query_row)
        {
            int size = q.size();
            double left = 0;
            double right = q.poll();
            while(size >= 0)
            {
                double fall = 0;
                if(left > 1)
                    fall += (left - 1) / 2;
                if(right > 1)
                    fall += (right - 1) / 2;

                q.offer(fall);
                size --;
                left = right;
                right = size <= 0? 0 : q.poll();
            }
            level ++;
        }
        for(int i = 0; i < query_glass; i ++)
            q.poll();

        double res = q.poll();
        if(res > 1) return (double)1;
        else return res;
    }
}
