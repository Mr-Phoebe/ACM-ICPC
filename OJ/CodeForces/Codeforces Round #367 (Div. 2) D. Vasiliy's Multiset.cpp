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

const int MAXN =100010;

struct Node
{
    Node *next[2];
    int cnt;
    Node()
    {
        next[0] = next[1] = nullptr;
        cnt = 0;
    }
};
Node *root = new Node();

void Insert(int x)
{
    Node* p = root;
    for(int i = 30; i >= 0; i--)
    {
        int num = !!(x&(1<<i));
        if(p->next[num] == nullptr)
            p->next[num] = new Node();
        p = p->next[num];
        p->cnt++;

    }
}

void Delete(int x)
{
    Node* p = root;
    for(int i = 30; i >= 0; i--)
    {
        int num = !!(x&(1<<i));
        p = p->next[num];
        p->cnt--;
    }
}

int Query(int x)
{
    int res = 0;
    Node* p = root;
    for(int i = 30; i >= 0; i--)
    {
        int num = !(x&(1<<i));
        Node *temp;
        temp = p->next[num];
        if(temp&&temp->cnt>0)
        {
            res += pow(2.0,i);
            p = temp;
        }
        else
            p=p->next[!num];
    }
    return res;
}


int main()
{
    int T;
    Insert(0);
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        char op[2];
        int x;
        scanf("%s%d",op,&x);
        if(op[0]=='+')
            Insert(x);
        else if(op[0]=='-')
            Delete(x);
        else
            printf("%d\n",Query(x));
    }
    return 0;
}
