//      whn6325689
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
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

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

const int MAXN=66;

int n, m;
int adj[MAXN][MAXN];
int labelx[MAXN], usedx[MAXN], lnk[MAXN];
int labely[MAXN], usedy[MAXN];
int mat;
char s1[2000005];
char s2[2000005];


bool path(int i)
{
    usedx[i]=1;
    for(int j=0; j<m; j++)
    {
        if(!usedy[j] && adj[i][j]!=-INF && !abs(adj[i][j]-labelx[i]-labely[j]))
        {
            usedy[j]=1;
            if(lnk[j]==-1 || path(lnk[j]))
            {
                lnk[j]=i;
                return true;
            }
        }
    }
    return false;
}

int match()
{
    mat=0;
    CLR(lnk,-1);
    CLR(labely,0);
    for(int i=0; i<n; i++)
    {
        labelx[i]=0;
        for(int j=0; j<m; j++)
            if(adj[i][j] > labelx[i])
                labelx[i] = adj[i][j];
    }
    for(int k=0; k<n; k++)
    {
        while(1)
        {
            CLR(usedx,0);
            CLR(usedy,0);
            if(path(k))
            {
                mat++;
                break;
            }
            int del=INF;
            for(int i=0; i<n; i++)
                if(usedx[i])
                    for(int j=0; j<m; j++)
                        if(!usedy[j] && adj[i][j]!=-INF)
                            del=min(del,labelx[i]+labely[j]-adj[i][j]);

            if(del==0 || del==INF)
                break;
            for(int i=0; i<n; i++)
                if(usedx[i])
                    labelx[i] -= del;
            for(int j=0; j<m; j++)
                if(usedy[j])
                    labely[j] += del;
        }
    }
    int sum=0;
    for(int i=0; i<n; i++)
        sum+=labelx[i];
    for(int j=0; j<m; j++)
        sum+=labely[j];
    return sum;
}

int main(void)
{
    int len, k;
    int a,b;
    read(len),read(k);
    gets(s1),gets(s2);

    n=m=k;
    for(int i=0; i<len; i++)
    {
        if(islower(s1[i]))
            a=s1[i]-'a';
        else
            a=s1[i]-'A'+26;
        if(islower(s2[i]))
            b=s2[i]-'a';
        else
            b=s2[i]-'A'+26;
        adj[a][b]++;
    }
    int r=match();
    write(r),putchar('\n');
    for(int i=0; i<k; i++)
        for(int j=0; j<k; j++)
            if(lnk[j]==i)
                if(j>=26)
                    printf("%c", j+'A'-26);
                else
                    printf("%c", j+'a');
    puts("");
    return 0;
}
