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
const int BLOCK=10000;
const int HASHTHING=6000;
int hashTable[20000];
int father[20000]; //0..9999 , 10000..19999

unsigned int hash(int number)
{
    int pos=number % HASHTHING;
    while(hashTable[pos]!=-1 && hashTable[pos]!=number) pos=(pos+1)%HASHTHING;
    hashTable[pos]=number;
    return pos;
}

int find_fa(int x)
{
    return father[x]==x?x:father[x]=find_fa(father[x]);
}

bool merge(int x,int y)
{
    x=find_fa(x),y=find_fa(y);
    if(x!=y)
        father[x]=y;
}

int main()
{
    freopen("data.txt","r",stdin);
    int n,m;
    while(read(n))
    {
        if(n==-1)
            break;
        read(m);
        int l,r,i;
        char str[11];
        CLR(hashTable,0xff);
        for(int i=0; i<20000; i++)
            father[i]=i;
        for(i=0; i<m; i++)
        {
            scanf("%d %d %s",&l,&r,str);
            l=hash(l-1),r=hash(r);
            bool even=(str[0]=='e');
            if(even)
            {
                if(find_fa(l)==find_fa(r+BLOCK))
                    break;
                merge(l,r);
                merge(l+BLOCK,r+BLOCK);
            }
            else
            {
                if(find_fa(l)==find_fa(r))
                    break;
                merge(l,r+BLOCK);
                merge(l+BLOCK,r);
            }
        }
        write(i++),putchar('\n');
        for(; i<m; i++)
            scanf("%d %d %s",&l,&r,str);
    }
    return 0;
}
