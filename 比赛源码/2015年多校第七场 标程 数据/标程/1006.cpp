#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 200010
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
#define ABS(m) (m<0?-m:m)
typedef long long LL;

int n,m,a[MAXN],mo[3]={1,2,4};
bool vis[3][4][4][4],board[20][20];
char op[MAXN];

void Init()
{
    vis[0][0][0][0]=vis[0][0][0][1]=vis[0][0][1][0]=vis[0][0][1][1]=1;
    
    vis[1][0][0][0]=vis[1][0][1][0]=vis[1][0][2][0]=vis[1][0][3][0]=1;
    vis[1][1][0][0]=vis[1][1][0][1]=vis[1][1][0][2]=vis[1][1][0][3]=1;
    
    vis[2][0][0][0]=vis[2][0][0][1]=vis[2][0][0][2]=vis[2][0][1][0]=1;
    vis[2][1][0][0]=vis[2][1][1][0]=vis[2][1][2][0]=vis[2][1][2][1]=1;
    vis[2][2][1][0]=vis[2][2][1][1]=vis[2][2][1][2]=vis[2][2][0][2]=1;
    vis[2][3][0][0]=vis[2][3][0][1]=vis[2][3][1][1]=vis[2][3][2][1]=1;
}

bool Check(int k,int t,int x,int y)
{
    if(x<1||x>12||y<1||y>9) return false;
    int i,j;
    for(i=0;i<4;++i)
        for(j=0;j<4;++j)
            if(vis[k][t][i][j]&&(x+i>12||y+j>9||board[x+i][y+j])) return false;
    return true;
}

void Put(int k,int t,int x,int y)
{
    int i,j;
    for(i=0;i<4;++i)
        for(j=0;j<4;++j){
            if(x+i>12||y+j>9) continue;
            board[x+i][y+j]|=vis[k][t][i][j];
        }
}

int Romove()
{
    int i,j,k,score=0;
    for(i=1,k=1;i<=12;++i){
        for(j=1;j<=9;++j) if(!board[i][j]) break;
        if(j<10) for(j=1,++k;j<=9;++j) board[k-1][j]=board[i][j];
        else ++score;
    }
    for(;k<=12;++k) memset(board[k],0,sizeof(board[k]));
    return score;
}

void Print()
{
    for(int i=12;i;--i){
        for(int j=1;j<=9;++j)
            printf("%d",(int)board[i][j]);
        printf("\n");
    }
    printf("\n");
}

int Work()
{
    memset(board,0,sizeof(board));
    int i,j,x,y,k,t,ans=0;
    for(i=0,x=9,y=4,k=a[j=1],t=0;i<m;++i){
        switch(op[i]){
            case 'w': Check(k,(t+1)%mo[k],x,y)&&(t=(t+1)%mo[k]); break;
            case 'a': Check(k,t,x,y-1)&&(--y); break;
            case 'd': Check(k,t,x,y+1)&&(++y); break;
            case 's': Check(k,t,x-1,y)&&(--x); break;
        }
        if(!Check(k,t,x-1,y)){
            Put(k,t,x,y); ans+=Romove();
            k=a[++j]; x=9; y=4; t=0;
            //Print();
        }
        else --x;
    }
    return ans;
}


int main()
{
    Init();
    int i,j,t;
    for(scanf("%d",&t),i=1;i<=t;++i){
        scanf("%d%s",&n,op); m=strlen(op);
        for(j=1;j<=n;++j) scanf("%d",a+j);
        printf("Case %d: %d\n",i,Work());
    }
    return 0;
}
