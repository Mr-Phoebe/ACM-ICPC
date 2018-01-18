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
#define mp(x,y) make_pair(x,y)
#define eps 1e-9
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

using namespace std;

typedef long long ll;
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

string s[33],pos[33];
int a[33],b[33][33];

int ans,maxn,cont1,cont2,cont3,cont4;

void dfs(int n, int mask)
{
    if(__builtin_popcount(mask)==11)        // ym S¾ÕÜÄ
    {
        ans=max(ans,maxn);
        return;
    }
    if(n==23)
        return;

    if(cont1+cont2+cont3+cont4+22-n>=11)        //  ²»Ñ¡
        dfs(n+1,mask);

    if(pos[n][0]=='g') cont1++;
    else if(pos[n][0]=='d') cont2++;
    else if(pos[n][0]=='m') cont3++;
    else if(pos[n][0]=='s') cont4++;

    if(cont1<=1 && cont2<=4 && cont3<=4 && cont4<=2 && cont1+cont2+cont3+cont4+22-n>=11)        // Ñ¡
    {
        maxn+=a[n];
        for(int i=0; i<n; i++)
            if((mask>>i)&1)
                maxn+=b[n][i];
        dfs(n+1,mask|(1<<n));
        maxn-=a[n];
        for(int i=0; i<n; i++)
            if((mask>>i)&1)
                maxn-=b[n][i];
    }

    if(pos[n][0]=='g') cont1--;
    else if(pos[n][0]=='d') cont2--;
    else if(pos[n][0]=='m') cont3--;
    else if(pos[n][0]=='s') cont4--;
}

map<string, int> id;
string u,v;

int main()
{
    while(cin>>s[0]>>a[0]>>pos[0])
    {
        id.clear();
        cont1=cont2=cont3=cont4=maxn=0;
        ans=-INF;
        id[s[0]]=0;
        for(int i=1; i<23; i++)
        {
            cin>>s[i]>>a[i]>>pos[i];
            id[s[i]]=i;
        }
        int m,idu,idv,w;
        read(m);
        CLR(b,0);
        for(int i=0; i<m; i++)
        {
            cin>>u>>v>>w;
            idu=id[u];
            idv=id[v];
            b[idu][idv]+=w;
            b[idv][idu]+=w;
        }
        dfs(0,0);
        if(ans==-INF)
            puts("impossible");
        else
            cout<<ans<<endl;
    }
    return 0;
}
