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

int score[10]= {16,7,8,1,1,2,3};
char str[10];
int red[20],black[20];
int ans_red;
int ans_black;
int n,m;

int main()
{
    int T;
    int i,j,k;
    read(T);
    while(T--)
    {
        ans_red=ans_black=0;
        CLR(red,0);
        CLR(black,0);
        read(n);
        for(i=0; i<n; i++)
        {
            scanf("%s",str);
            red[str[0]-'A']++;
        }
        read(m);
        for(i=0; i<m; i++)
        {
            scanf("%s",str);
            black[str[0]-'A']++;
        }
        for(i=0; i<7; i++)
            ans_red+=score[i]*red[i];
        for(i=0; i<7; i++)
            ans_black+=score[i]*black[i];
        if(!(red[1]&&red[2]))
        {
            ans_red--;
            if(ans_red<=0)
                ans_red=1;
        }
        if(!(black[1]&&black[2]))
        {
            ans_black--;
            if(ans_black<=0)
                ans_black=1;
        }
        if(ans_red==ans_black)
            puts("tie");
        else if(ans_red>ans_black)
            puts("red");
        else
            puts("black");

    }
    return 0;
}
