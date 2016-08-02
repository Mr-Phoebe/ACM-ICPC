#include <bits/stdc++.h>
#define max(a,b) ((a)>(b))?(a):(b)
#define min(a,b) ((a)>(b))?(b):(a)
#define rep(i,initial_n,end_n) for(int (i)=(initial_n);(i)<(end_n);i++)
#define repp(i,initial_n,end_n) for(int (i)=(initial_n);(i)<=(end_n);(i)++)
#define eps 1.0E-8
#define MAX_N 1010
#define INF 1 << 30
using namespace std;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef unsigned long long ull;

pii v1[10001], v2[10001];

int main()
{
    int n;
    scanf("%d", &n);
    rep(i, 0, n)
    {
        scanf("%d%d", &v1[i].first, &v1[i].second);
        scanf("%d%d", &v2[i].first, &v2[i].second);
        if(v1[i].first > v2[i].first) swap(v1[i].first, v2[i].first);
        if(v1[i].second > v2[i].second) swap(v1[i].second, v2[i].second);
    }
    pii point;
    scanf("%d%d", &point.first, &point.second);
    int cnt = 0;
    rep(i, 0, n)
    {
        if(v1[i].first == v2[i].first)
        {
            if(v1[i].first == point.first && v1[i].second <= point.second && v2[i].second >= point.second)
            {
                puts("BORDER");
                exit(0);
            }
            if(v1[i].first < point.first && v1[i].second <= point.second && v2[i].second > point.second)
                cnt++;
        }
        else if(v1[i].second == v2[i].second &&
                v1[i].first <= point.first && v2[i].first >= point.first)
        {
            if(v1[i].second == point.second)
            {
                puts("BORDER");
                exit(0);
            }
        }
    }
    if(cnt&1) puts("INSIDE");
    else puts("OUTSIDE");
    return 0;
}
