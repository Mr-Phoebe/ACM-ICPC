class Solution {
    public String[] findRelativeRanks(int[] nums) {
        int[][] numi = new int[nums.length][2];

        for(int i = 0; i < nums.length; i++)
        {
            numi[i][0] = nums[i];
            numi[i][1] = i;
        }

        Arrays.sort(numi, (a, b) -> (b[0] - a[0]));

        String[] res = new String[nums.length];

        for(int i = 0; i < nums.length; i++)
        {
            if(i == 0)
                res[numi[i][1]] = "Gold Medal";
            else if(i == 1)
                res[numi[i][1]] = "Silver Medal";
            else if(i == 2)
                res[numi[i][1]] = "Bronze Medal";
            else
                res[numi[i][1]] = new Integer(i+1).toString();
        }
        return res;
    }
}
