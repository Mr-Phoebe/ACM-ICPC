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


int main()
{
    int a[16], delta;
    up(i, 0, 16)
    {
        read(a[i]);
        if(a[i] == 0) delta = 6-(i%4+i/4);
    }
    int sum = 0;
    up(i, 0, 16) up(j, i+1, 16)
    if(a[i] > a[j]) sum++;
    if((delta&1) != (sum&1)) puts("YES");
    else puts("NO");
    return 0;
}
