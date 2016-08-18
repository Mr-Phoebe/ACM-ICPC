//      whn6325689
//      Mr.Phoebe
//      http://blog.csdn.net/u013007900
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
#include <functional>
#include <numeric>
#pragma comment(linker, "/STACK:1024000000,1024000000")


using namespace std;
#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<50
#define speed std::ios::sync_with_stdio(false);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define CPY(x,y) memcpy(x,y,sizeof(x))
#define clr(a,x,size) memset(a,x,sizeof(a[0])*(size))
#define cpy(a,x,size) memcpy(a,x,sizeof(a[0])*(size))
#define debug(a) cout << #a" = " << (a) << endl;
#define debugarry(a, n) for (int i = 0; i < (n); i++) { cout << #a"[" << i << "] = " << (a)[i] << endl; }

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))

#define MID(x,y) (x+((y-x)>>1))
#define getidx(l,r) (l+r | l!=r)
#define ls getidx(l,mid)
#define rs getidx(mid+1,r)
#define lson l,mid
#define rson mid+1,r

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1;
    char c = getchar();
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

const int MAXN=9*9*9+10;
const int MAXM=9*9*4+10;
const int MAX=MAXN*MAXM;
const int SIGMA_SIZE=9;
const int SLOT=0;
const int ROW=1;
const int COL=2;
const int SUB=3;

struct DLX
{
    int n,m,size;
    int U[MAX],D[MAX],L[MAX],R[MAX];
    int H[MAXN],S[MAXM];
    int row[MAX],col[MAX];
    int ansd,ans[MAX];
    void init(int N,int M)
    {
        n=N,m=M;
        ansd=0;
        for(int i=0;i<=m;i++)
        {
            U[i]=D[i]=i;
            L[i]=i-1;
            R[i]=i+1;
        }
        L[0]=m;
        R[m]=0;
        size=m;
        CLR(S,0);
        CLR(H,-1);
    }
    void Link(int r,int c)
    {
        ++S[col[++size]=c];
        row[size]=r;
        D[size]=D[c];
        U[D[c]]=size;
        U[size]=c;
        D[c]=size;
        if(H[r]<0)H[r]=L[size]=R[size]=size;
        else
        {
            R[size]=R[H[r]];
            L[R[H[r]]]=size;
            L[size]=H[r];
            R[H[r]]=size;
        }
    }
    void remove(int c)
    {
        L[R[c]]=L[c];R[L[c]]=R[c];
        for(int i=D[c];i!=c;i=D[i])
        {
            for(int j=R[i];j!=i;j=R[j])
            {
                U[D[j]]=U[j];
                D[U[j]]=D[j];
                --S[col[j]];
            }
        }
    }
    void resume(int c)
    {
        for(int i=U[c];i!=c;i=U[i])
        {
            for(int j=L[i];j!=i;j=L[j])
            {
                U[D[j]]=D[U[j]]=j;
                ++S[col[j]];
            }
        }
        L[R[c]]=R[L[c]]=c;
    }
    void Dance(int d)
    {
        if(R[0]==0)
        {
            ansd++;
            return;
        }
        int c=R[0];
        for(int i=R[0];i;i=R[i])
            if(S[i]<S[c])c=i;
        remove(c);
        for(int i=D[c];i!=c;i=D[i])
        {
            ans[d]=row[i];
            for(int j=R[i];j!=i;j=R[j])remove(col[j]);
            Dance(d+1);
            for(int j=L[i];j!=i;j=L[j])resume(col[j]);
        }
        resume(c);
    }
}dlx;
inline int encode(int a,int b,int c)
{
    return a*81+b*9+c+1;
}
void decode(int code,int &a,int &b,int &c)
{
    code--;
    c=code%9;code/=9;
    b=code%9;code/=9;
    a=code;
}
char str[MAXN][MAXN];
vector<pii> alp[30];
int main()
{
    //freopen("data.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0;i<9;i++)
            scanf("%s",&str[i]);
        dlx.init(9*9*9,9*9*4);
        for(int i=0;i<=26;i++)
            alp[i].clear();
        for(int r=0;r<SIGMA_SIZE;r++)
            for(int c=0;c<SIGMA_SIZE;c++)
            {
                if(isalpha(str[r][c]) && str[r][c]!='o' && str[r][c]!='e')
                {
                    alp[str[r][c]-'a'].pb(mp(r,c));
                    continue;
                }
                for(int v=0;v<SIGMA_SIZE;v++)
                {
                    if(str[r][c]=='0'||str[r][c]==v+'1')
                    {
                        int row=encode(r,c,v);
                        dlx.Link(row,encode(SLOT,r,c));
                        dlx.Link(row,encode(ROW,r,v));
                        dlx.Link(row,encode(COL,c,v));
                        dlx.Link(row,encode(SUB,(r/3)*3+c/3,v));
                    }
                    else if((str[r][c]=='o' && v%2==0)||(str[r][c]=='e' && v%2==1))
                    {
                        int row=encode(r,c,v);
                        dlx.Link(row,encode(SLOT,r,c));
                        dlx.Link(row,encode(ROW,r,v));
                        dlx.Link(row,encode(COL,c,v));
                        dlx.Link(row,encode(SUB,(r/3)*3+c/3,v));
                    }
                }
            }


        for(int i=0;i<26;i++)
        {
            int sz=alp[i].size();
            for(int j=0;j<sz;j++)
            {
                for(int v=0;v<9;v++)
                {
                    int r=alp[i][j].first,c=alp[i][j].second;
                    int row=encode(r,c,v);
                    for(int k=j;k<sz;k++)
                    {
                        r=alp[i][k].first,c=alp[i][k].second;
                        dlx.Link(row,encode(SLOT,r,c));
                        dlx.Link(row,encode(ROW,r,v));
                        dlx.Link(row,encode(COL,c,v));
                        dlx.Link(row,encode(SUB,(r/3)*3+c/3,v));
                    }
                }

            }
        }
        dlx.Dance(0);
        printf("%d\n",dlx.ansd);
    }
    return 0;
}