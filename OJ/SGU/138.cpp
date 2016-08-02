#include <bits/stdc++.h>

#define up(i, lower, upper) for(int i = lower; i < upper; i++)
#define down(i, lower, upper) for(int i = upper-1; i >= lower; i--)

using namespace std;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef long long ll;
typedef unsigned long long ull;

const double pi = acos(-1.0);
const double eps = 1.0e-9;

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

///---------------------------------------------------------

struct node
{
    int num, cnt;
    node() :cnt(0) {}
    friend bool operator < (node a, node b)
    {
        return a. cnt > b. cnt;
    }
};

node a[101];
int winner[10001], loser[10001];

int main()
{
    int n;
    read(n);
    up(i, 1, n+1) a[i].num = i;
    int sum = 0;
    up(i, 1, n+1)
    {
        read(a[i].cnt);
        sum += a[i].cnt;
    }
    sort(a+1, a+n+1);
    sum /= 2;
    int pt = 1;
    up(i, 0, sum)
    {
        if(a[pt].cnt>1) winner[i] = a[pt].num, a[pt].cnt--;
        else
        {
            loser[i] = a[pt].num, a[pt].cnt--;
            while(a[pt].cnt <= 1) pt++;
            winner[i] = a[pt].num, a[pt].cnt--;
        }
    }
    pt = 1;
    up(i, 0, sum)
    {
        if(!loser[i])
        {
            while(a[pt].cnt < 1) pt++;
            loser[i] = a[pt].num, a[pt].cnt--;
        }
    }
    write(sum);
    puts("");
    up(i, 0, sum) printf("%d %d\n", winner[i], loser[i]);
}
