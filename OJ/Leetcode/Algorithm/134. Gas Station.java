class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        int be = 0;
        int total = 0;
        for(int i = 0; i < n; )
        {
            be = i;
            while(i < n && total >= 0)
            {
                total += gas[i] - cost[i];
                i++;
            }
            if(total < 0)
            {
                be = -1;
                total = 0;
            }

        }
        for(int i = 0; i < be; i++)
        {
            total += gas[i] - cost[i];
            if(total < 0)
                return -1;
        }
        return be;
    }
}
