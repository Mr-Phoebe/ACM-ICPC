class Solution {
    int[][] dp;
    public List<List<String>> partition(String s) {
        int len = s.length();
        dp = new int[len+2][len+2];
        List<List<String>>[] ans = new List[len+2];
		ans[0] = new ArrayList<List<String>>();
		ans[0].add(new ArrayList<String>());

        for(int i = 0; i < s.length(); i++) {
			ans[i + 1] = new ArrayList<List<String>>();
			for(int j = 0; j <= i; j++) {
				if(s.charAt(j) == s.charAt(i) && (i-j <= 1 || dp[j + 1][i - 1] == 1)) {
					dp[j][i] = 1;
					String str = s.substring(j, i + 1);

					for(List<String> r : ans[j]){
						List<String> ri = new ArrayList<String>(r);
						ri.add(str);
						ans[i + 1].add(ri);
					}
				}
			}
		}
		return ans[len];
    }
}
