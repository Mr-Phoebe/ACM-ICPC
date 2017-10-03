
class UniformBoard
{
public:
    int NA[52][52],NP[52][52],NE[52][52];

    int getArea(vector <string> board, int K)
    {
        int N=board.size();
        int x,y,h,w,h2;
        int ret=0;

        clr(NA);
        clr(NP);
        clr(NE);
        for(y = 0; y < N; y++)
            for(x = 0; x < N; x++)
            {
                for(h = 0; h <= y; h++) NA[y+1][x+1]+=count(board[h].begin(),board[h].begin()+x+1,'A');
                for(h = 0; h <= y; h++) NP[y+1][x+1]+=count(board[h].begin(),board[h].begin()+x+1,'P');
                for(h = 0; h <= y; h++) NE[y+1][x+1]+=count(board[h].begin(),board[h].begin()+x+1,'.');
            }
        if(NE[N][N]==0) K=0;
        for(y = 0; y < N; y++)
            for(x = 0; x < N; x++)
                for(h=1; y+h <= N; h++)
                    for(w=1; x+w <= N; w++)
                    {
                        if(h*w<=ret) continue;
                        int CA = NA[y+h][x+w]-NA[y+h][x]-NA[y][x+w]+NA[y][x];
                        int CP = NP[y+h][x+w]-NP[y+h][x]-NP[y][x+w]+NP[y][x];
                        int CE = NE[y+h][x+w]-NE[y+h][x]-NE[y][x+w]+NE[y][x];

                        if(NA[N][N] >= h*w && CE+CP*2 <= K) ret = h*w;
                        if(NP[N][N] >= h*w && CE+CA*2 <= K) ret = h*w;
                        if(NE[N][N] >= h*w && CA+CP <= K) ret = h*w;
                    }
        return ret;
    }
}
