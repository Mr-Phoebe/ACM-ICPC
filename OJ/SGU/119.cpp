#include <bits/stdc++.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
#define rep(i,initial_n,end_n) for(int (i)=(initial_n);(i)<(end_n);i++)
#define repp(i,initial_n,end_n) for(int (i)=(initial_n);(i)<=(end_n);(i)++)
#define reep(i,initial_n,end_n) for((i)=(initial_n);(i)<(end_n);i++)
#define reepp(i,initial_n,end_n) for((i)=(initial_n);(i)<=(end_n);(i)++)
#define eps 1.0e-9
#define MAX_N 1010

using namespace std;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int64 ll;
typedef unsigned __int64 ull;
/*
int getint(){
    int x=0,tmp=1; char c=getchar();
    while((c<'0'||c>'9')&&c!='-') c=getchar();
    if(c == '-') c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
*/

struct node
{
    int first, second;
};

node ans[10000];

bool cmp(node a, node b)
{
    return a.first < b.first || (a.first == b.first && a.second < b.second);
}
int main()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    a %= n, b %= n;
    ans[0].first = a, ans[0].second = b;
    int ta = a*2%n, tb = b*2%n, len = 1;
    while(ta != a || tb != b)
    {
        ans[len].first = ta, ans[len++].second = tb;
        ta = (ta+a) % n, tb = (tb+b) % n;
    }
    sort(ans, ans + len, cmp);
    printf("%d\n", len);
    rep(i, 0, len) printf("%d %d\n", ans[i].first, ans[i].second);
}
