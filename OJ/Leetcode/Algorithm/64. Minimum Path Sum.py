class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid[0])
        m = len(grid)
        dp = [[-1 for _ in range(n)] for _ in range(m)]
        dp[-1][-1] = grid[-1][-1]
        def dfs(x, y):
            if x >= m or y >= n:
                return 999999999
            if dp[x][y] != -1:
                return dp[x][y]
            dp[x][y] = min(dfs(x+1, y), dfs(x, y+1)) + grid[x][y]
            return dp[x][y]
        return dfs(0, 0)
