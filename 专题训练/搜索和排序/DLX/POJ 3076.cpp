//      whn6325689
//		Mr.Phoebe
//		http://blog.csdn.net/u013007900
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

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))
#define MID(x,y) (x+((y-x)>>1))
#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

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


const int M=4096*5;

int l[M], r[M], d[M], u[M], col[M], row[M], h[4100], control[1030];
int dcnt = 0;
char str[16][17];

inline void addnode(int &x)
{
    ++x;
    r[x]=l[x]=u[x]=d[x]=x;
}

inline void insert_row(int rowx, int x)
{
    r[l[rowx]]=x;
    l[x]=l[rowx];
    r[x]=rowx;
    l[rowx]=x;
}

inline void insert_col(int colx, int x)
{
    d[u[colx]]=x;
    u[x]=u[colx];
    d[x]=colx;
    u[colx]=x;
}

void dlx_init(int cols)
{
    memset(h, -1, sizeof(h));
    memset(control, 0, sizeof(control));
    dcnt=-1;
    addnode(dcnt);

    for(int i=1;i<=cols;++i)
    {
        addnode(dcnt);
        insert_row(0, dcnt);
    }
}

inline void remove(int c)
{
    l[r[c]]=l[c];
    r[l[c]]=r[c];

    for(int i=d[c];i!=c;i=d[i])
        for(int j=r[i];j!=i;j=r[j])
        {
            u[d[j]]=u[j];
            d[u[j]]=d[j];
            control[col[j]]--;
        }
}

inline void resume(int c)
{
    for(int i=u[c];i!=c;i=u[i])
        for(int j=l[i];j!=i;j=l[j])
        {
            u[d[j]]=j;
            d[u[j]]=j;
            control[col[j]]++;
        }
        l[r[c]]=c;
        r[l[c]]=c;
}

bool DLX(int deep)
{
    if(r[0]==0)
    {
        for(int i=0;i<16;i++)
            puts(str[i]);
        return true;
    }

    int min=M, tempc;
    for(int i=r[0];i!=0;i=r[i]) if(control[i]<min)
    {
        min=control[i];
        tempc=i;
    }
    remove(tempc);
    for(int i=d[tempc];i!=tempc;i=d[i])
    {
        str[row[i]/256][row[i]/16%16]=row[i]%16+'A';
        for(int j=r[i];j!=i;j=r[j]) remove(col[j]);
        if(DLX(deep+1)) return true;
        for(int j=l[i];j!=i;j=l[j]) resume(col[j]);
    }
    resume(tempc);
    return false;
}

inline void insert_node(int x, int y)
{
    control[y]++;
    addnode(dcnt);
    row[dcnt]=x;
    col[dcnt]=y;
    insert_col(y, dcnt);
    if(h[x]==-1)
        h[x]=dcnt;
    else
        insert_row(h[x], dcnt);
}

int main()
{
#ifdef ACM
    freopen("in.txt", "r", stdin);
#endif

    while(~scanf("%s", str[0]))
    {
        for(int i=1;i<16;i++) scanf("%s", str[i]);

        dlx_init(4*16*16);
        for(int i=1;i<=16;i++) for(int j=1;j<=16;j++)
        {
            for(int k=1;k<=16;k++) if(str[i-1][j-1]=='-' || str[i-1][j-1]=='A'+(k-1))
            {
                int rr=(i-1)*256+(j-1)*16+(k-1);
                insert_node(rr, 16*16*0+(i-1)*16+k);
                insert_node(rr, 16*16*1+(j-1)*16+k);
                insert_node(rr, 16*16*2+(i-1)/4+(j-1)/4*4+(k-1)*16+1);
                insert_node(rr, 16*16*3+(i-1)*16+j);
            }
        }

        DLX(0);
        puts("");
    }
}
