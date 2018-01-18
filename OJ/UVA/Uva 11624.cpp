#include<cstdio>  
#include<cstring>  
#include<queue>  
using namespace std;  
typedef pair<int,int> tp;  
const int inf=0x3f3f3f3f;  
const int N=1111;  
char s[N][N];  
int dx[4]={1,0,-1,0};  
int dy[4]={0,1,0,-1};  
int t,n,m,lim[N][N],dis[N][N];  
void init()  
{  
    queue<tp>q;  
    memset(lim,63,sizeof(lim));  
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(s[i][j]=='F') q.push(tp(i,j)),lim[i][j]=0;  
    while(!q.empty())  
    {  
        tp u=q.front();q.pop();  
        for(int i=0;i<4;i++)  
        {  
            int x=u.first+dx[i],y=u.second+dy[i];  
            if(x<0||y<0||x==n||y==m||lim[x][y]!=inf||s[x][y]=='#') continue;  
            lim[x][y]=lim[u.first][u.second]+1;  
            q.push(tp(x,y));  
        }  
    }  
}  
int bfs()  
{  
    queue<tp>q;  
    memset(dis,63,sizeof(dis));  
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(s[i][j]=='J') q.push(tp(i,j)),dis[i][j]=0;  
    while(!q.empty())  
    {  
        tp u=q.front();q.pop();  
        for(int i=0;i<4;i++)  
        {  
            int x=u.first+dx[i],y=u.second+dy[i],d=dis[u.first][u.second];  
            if(x<0||y<0||x==n||y==m) return d+1;  
            if(dis[x][y]!=inf||d+1>=lim[x][y]||s[x][y]=='#') continue;  
            dis[x][y]=d+1;  
            q.push(tp(x,y));  
        }  
    }  
    return -1;  
}  
int main()  
{  
	
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d%d",&n,&m);  
        for(int i=0;i<n;i++) scanf("%s",s[i]);  
        init();  
        int ans=bfs();  
        if(ans==-1) puts("IMPOSSIBLE");  
        else printf("%d\n",ans);  
    }  
    return 0;  
}  