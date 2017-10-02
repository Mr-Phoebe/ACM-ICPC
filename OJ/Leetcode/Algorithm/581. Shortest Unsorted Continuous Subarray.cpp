public int findUnsortedSubarray(int[] nums) {
    int i = 0, j = -1, max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
    
    for (int l = 0, r = nums.length - 1; r >= 0; l++, r--) {
        max = Math.max(max, nums[l]);
        if (nums[l] != max) j = l;
        
        min = Math.min(min, nums[r]);
        if (nums[r] != min) i = r;
    }
    
    return (j - i + 1);
}
