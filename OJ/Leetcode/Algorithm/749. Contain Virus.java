class Solution {
    int m, n;
    int[][] dirs = new int[][]{{0,1}, {0,-1}, {1,0}, {-1,0}};
    public int containVirus(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        Map<Point, Integer> zeroCounts = new HashMap<>(), wallCounts = new HashMap<>();
        boolean[][] visitedOne = new boolean[m][n];
        int zeroTotal = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    if (!visitedOne[i][j]){
                        visitedOne[i][j] = true;
                        int[] nums = countWalls(grid, i, j, visitedOne, new boolean[m][n]);
                        zeroCounts.put(new Point(i, j), nums[0]);
                        wallCounts.put(new Point(i, j), nums[1]);
                        zeroTotal += nums[0];
                    }
                }
            }
        }
        // System.out.println("zeroCounts: " + zeroCounts);
        // System.out.println("wallCounts: " + wallCounts);
        if (zeroTotal == 0) return 0;
        int max = 0;
        Point maxPoint = null;
        List<Point> candidates = new ArrayList<>();
        for (Map.Entry<Point, Integer> entry : zeroCounts.entrySet()){
            if (entry.getValue() > max){
                max = entry.getValue();
                maxPoint = entry.getKey();
                candidates = new ArrayList<>();
                candidates.add(entry.getKey());
            } else if (entry.getValue() == max){
                candidates.add(entry.getKey());
            }
        }
        int min = Integer.MAX_VALUE;
        for (Point candidate : candidates){
            int[][] newGrid = new int[m][n];
            System.arraycopy(grid, 0, newGrid, 0, grid.length);
            toTwo(newGrid, candidate);
            toOne(newGrid, new boolean[m][n]);
            min = Math.min(min, containVirus(newGrid) + wallCounts.get(candidate));
            // System.out.println(min);
        }
        return min;
    }
    private int[] countWalls(int[][] grid, int i, int j, boolean[][] visitedOne, boolean[][] visitedZero){
        int zero = 0, wall = 0;
        for (int[] dir : dirs){
            int x = dir[0] + i;
            int y = dir[1] + j;
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 2) continue;
            if (grid[x][y] == 0){
                if (!visitedZero[x][y]){
                    visitedZero[x][y] = true;
                    zero++;
                }
                wall++;
            } else if (grid[x][y] == 1){
                if (!visitedOne[x][y]){
                    visitedOne[x][y] = true;
                    int[] nums = countWalls(grid, x, y, visitedOne, visitedZero);
                    zero += nums[0];
                    wall += nums[1];
                }
            }
        }
        return new int[]{zero, wall};
    }
    private void toTwo(int[][] grid, Point p){
        for (int[] dir : dirs){
            int x = dir[0] + p.x;
            int y = dir[1] + p.y;
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1) continue;
            grid[x][y] = 2;
            toTwo(grid, new Point(x, y));
        }
    }
    private void toOne(int[][] grid, boolean[][] visited){
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    if (!visited[i][j]){
                        visited[i][j] = true;
                        for (int[] dir : dirs){
                            int x = dir[0] + i;
                            int y = dir[1] + j;
                            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 0) continue;
                            grid[x][y] = 1;
                            visited[x][y] = true;
                        }
                    }
                }
            }
        }
    }
}
class Point{
    int x;
    int y;
    public Point(int x, int y){
        this.x = x;
        this.y = y;
    }
    @Override
    public boolean equals(Object o){
        if (this == o) return true;
        if (!(o instanceof Point)) return false;
        Point p = (Point) o;
        return p.x == this.x && p.y == this.y;
    }
    @Override
    public int hashCode(){
        return Objects.hash(x, y);
    }
}
