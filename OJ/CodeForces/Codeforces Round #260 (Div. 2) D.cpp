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

const int MAXN=100010;
const int CHARSET=26,BASE='a';

int n,k,num=0;
char str[MAXN];

struct Trie
{
    int tot,root,child[MAXN][CHARSET];
    int v[MAXN];
    Trie()
    {
        memset(child[1],0,sizeof(child[1]));
        root=tot=1;
    }
    void insert(const char *str)
    {
        int *cur=&root;
        for(const char *p=str;*p;p++)
        {
            cur=&child[*cur][*p-BASE];
            if(*cur==0)
            {
                *cur=++tot;
                memset(child[tot],0,sizeof(child[tot]));
            }
        }
    }

    void dfs(int x)
    {
        int l=0,flag=0;
        for(int i=0;i<26;i++)
            if(child[x][i])
            {
                dfs(child[x][i]);
                if(v[child[x][i]]==0)
                    l++;
                flag++;
            }
        if(!flag)
            v[x]=num;
        else if(l)
            v[x]=1;
        else
            v[x]=0;
        //cout<<x<<" "<<v[x]<<endl;
        return;
    }
};

Trie a;


int main()
{
	read(n),read(k);
	for(int i=0;i<n;i++)
    {
        gets(str);a.insert(str);
    }
    num=0;
    a.dfs(1);
    int temp=a.v[1];
    if(temp)   //ÏÈÊÖÓ®
    {
        num=1;
        a.dfs(1);
        if(a.v[1])
            puts("First");
        else
            printf("%s\n", (k&1) ? "First" : "Second");
    }
    else
        puts("Second");
    return 0;
}
