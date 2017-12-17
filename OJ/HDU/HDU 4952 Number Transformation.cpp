#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
#define CLR(x,y) memset(x,y,sizeof(x))
#define eps 1e-9
#define INF 0x3f3f3f3f

using namespace std;

typedef __int64 ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1; char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
template <class T>
inline void write(T n)
{
    if(n < 0)
    {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n)
    {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
//-----------------------------------
int n,m,c;
int xxxx;
int chess[11][11];
void turn(int x,int y)//翻转
{
     if(x>=0&&x<=n-1&&y>=0&&y<=m-1)
     chess[x][y]=!chess[x][y];
}
void flip(int s)//一个棋子变化，周围四个都要变化
{
    int i=s/4;//行
    int j=s%4;//列
    turn(i,j);
    turn(i+1,j);
    turn(i,j+1);
    turn(i-1,j);
    turn(i,j-1);
}

int complete()//判断棋盘是否变成同一的颜色
{
    int i,j,s1=0;
    for(i=0;i<n;i++)
       for(j=0;j<m;j++)
          s1+=chess[i][j];
    if(s1)
      return 0;
    else
      return 1;
}

void dfs(int s,int b)//进行深搜.s代表当前的方格，b代表翻转的方格数
{
     if(complete())//如果是同一颜色
     {
         if(c>b)c=b;
         return;
     }
     if(s>=xxxx)//如果遍历完
        return;
    dfs(s+1,b);//对每一个棋子都开始进行翻转
    flip(s);//做出翻转自己的第e步
    dfs(s+1,b+1);//再对翻转之后的局面每一个进行再一次的翻转
    turn(s/4,s%4);  //  turn itself
    dfs(s+1,b+1);//再对翻转之后的局面每一个进行再一次的翻转
    flip(s);//again
    turn(s/4,s%4);  //  turn itself
}

int main(){
    freopen("data.txt","r",stdin);
    while(read(n)&&read(m)&&(n+m)){
        char ch;
        int i,j;
        int xx=n*m*2+1;
        c=xx;
        xxxx=n*m;
        memset(chess,0,sizeof chess);
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                ch=getchar();
                if(ch=='1')
                    chess[i][j]=1;
                else if(ch=='0')
                    chess[i][j]=0;
                else
                    j--;
            }
        }
        dfs(0,0);
        if(c==xx)printf("33\n");
        else printf("%d\n",c);
        puts("");
    }
    return 0;
}
