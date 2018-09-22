class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> pre, cur, next;
        pre.clear();cur.clear();next.clear();
        for(int i = 0; i <= board.size(); i++)
        {
            if(i == board.size())
            {
                vector<vector<int> > tmpboard(2);
                tmpboard[0] = pre;
                tmpboard[1] = cur;
                find(1, tmpboard);
                board[i-1] = tmpboard[1];
                break;
            }
            if(cur.size() == 0)
            {
                cur = board[i];
                continue;
            }
            if(next.size() == 0)
            {
                next = board[i];
            }
            if(pre.size() == 0)
            {
                vector<vector<int> > tmpboard(2);
                tmpboard[0] = cur;
                tmpboard[1] = next;
                find(0, tmpboard);
                board[i-1] = tmpboard[0];
            }
            else
            {
                vector<vector<int> > tmpboard(3);
                tmpboard[0] = pre;
                tmpboard[1] = cur;
                tmpboard[2] = next;
                find(1, tmpboard);
                board[i-1] = tmpboard[1];
            }
            pre = cur;
            cur = next;
            next.clear();
        }
    }
private:
    const int d[8][2] = {{1,-1},{1,0},{1,1},{0,-1},{0,1},{-1,-1},{-1,0},{-1,1}};
    void find(int i, vector<vector<int>>& board)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            int live = 0;
            for(int k = 0; k < 8; k++)
            {
                int x = d[k][0] + i;
                int y = d[k][1] + j;
                if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
                {
                    continue;
                }
                if(board[x][y] & 1)
                {
                    live++;
                }
            }
            if(board[i][j] == 0)
            {
                if(live == 3)
                {
                    board[i][j] = 2;
                }
            }
            else
            {
                if(live < 2 || live > 3)
                {
                    board[i][j] = 1;
                }
                else
                {
                    board[i][j] = 3;
                }
            }
        }
        for(auto& item : board[i])
            item >>= 1;
    }
};
