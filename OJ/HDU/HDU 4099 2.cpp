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

const int CHARSET=10,BASE='0',MAX_NODE=10000005;
char str[4][100];

struct Trie
{
    int tot,root,child[MAX_NODE][CHARSET];
    int flag[MAX_NODE];

    Trie()
    {
        CLR(child,0);
        CLR(flag,-1);
        root=tot=1;
    }

    void insert(const char *str,int i)
    {
        int *cur=&root;
        int num=0;
        for(const char *p=str;*p && num<41;p++,num++)
        {
            cur=&child[*cur][*p-BASE];
            if(*cur==0)
            {
                *cur=++tot;
                CLR(child[tot],0);
            }
            if(flag[*cur]<0)
                flag[*cur]=i;
        }
        if(flag[*cur]<0)
            flag[*cur]=i;
    }
    int find(const char *str)
    {
        int *cur=&root;
        for(const char *p=str;*p;p++)
        {
            if(*cur==0)
                return -1;
            else
                cur=&child[*cur][*p-BASE];
        }
        return flag[*cur];
    }

}g;

void add(char a[],char b[],char c[])
{
    int lena=strlen(a)-1;
    int lenb=strlen(b)-1;
    int lenc=0,up=0,x,y,z;
    while(lena>=0 || lenb>=0)
    {
        if(lena<0)
            x=0;
        else
            x=a[lena--]-BASE;
        if(lenb<0)
            y=0;
        else
            y=b[lenb--]-BASE;
        z=x+y+up;
        c[lenc++]=z%10+BASE;
        up=z/10;
    }
    if(up>0)
		c[lenc++]=up+BASE;
    c[lenc]='\0';
    for(int i=0;i<lenc/2;i++)
        swap(c[i],c[lenc-i-1]);
}

void init()
{
    str[1][0]='1';str[1][1]='\0';
    g.insert(str[1],0);
    str[2][0]='1';str[2][1]='\0';
    g.insert(str[2],1);
    for(int i=2;i<100000;i++)
    {
        int lena=strlen(str[1]);
        int lenb=strlen(str[2]);
        if(lenb>90)
        {
            str[1][--lena]='\0';
            str[2][--lenb]='\0';
        }
        add(str[1],str[2],str[3]);
        g.insert(str[3],i);
        strcpy(str[1],str[2]);
        strcpy(str[2],str[3]);
    }
}

int main()
{
    int T,cas=0;
    char ttt[44];
    init();
    read(T);
    while(T--)
    {
        gets(ttt);
        printf("Case #%d: %d\n",++cas,g.find(ttt));
    }
    return 0;
}
