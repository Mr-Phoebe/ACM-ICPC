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

const int maxn = 100000 + 5;
int a[maxn];
int n, T;
 
bool findK(int k){
    queue<ll>q;
    ll ans = 0, s = 0;
    int r = (n - 1) % (k - 1),p=0;
    if (r){
        while (p < r + 1) s += a[p++];
 
        ans += s;
        q.push(s);
    }
    while (true){
        s = 0;
        for (int i = 0; i < k; i++){
            if (p < n && (q.empty() || a[p] < q.front())) s += a[p++];
            else{
                s += q.front();
                q.pop();
            }
        }
        ans += s;
        if (ans>T)return false;
        if (p >= n&&q.empty())break;
        q.push(s);
    }
    return ans <= T;
}
 
int search(int l, int r){
    while (l < r){
        int k = (l + r) >> 1;
        if (findK(k))
            r = k;
        else l = k + 1;
    }
    return r;
}
 
int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        scanf("%d%d", &n, &T);
        for (int i = 0; i < n; i++)scanf("%d", &a[i]);
 
        sort(a, a + n);  //排序
        printf("%d\n", search(2, n));
    }
    return 0;
}