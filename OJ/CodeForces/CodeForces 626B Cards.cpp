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

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))
#define MID(x,y) (x+((y-x)>>1))
#define speed std::ios::sync_with_stdio(false);
#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62
#define lson id<<1, l, mid
#define rson id<<1|1, mid+1, r
#define ls id<<1
#define rs id<<1|1

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

int main()
{
	int n, g = 0, b = 0, r = 0;
	char str[222];
	read(n);
	scanf("%s", str);
	for(int i = 0; i < n; i++)
	{
		if(str[i] == 'B')
			b++;
		else if(str[i] == 'G')
			g++;
		else if(str[i] == 'R')
			r++;
	}
	if(r>0&&g==0&&b==0)
        printf("R\n");
    else if(r==0&&g>0&&b==0)
        printf("G\n");
    else if(r==0&&g==0&&b>0)
        printf("B\n");
    else if(r==0&&g==1&&b==1)
        printf("R\n");
    else if(r==1&&g==0&&b==1)
        printf("G\n");
    else if(r==1&&g==1&&b==0)
        printf("B\n");
	else
	{
		if(r>1)
        {
        	if(g==1&&b==0)
                printf("BG\n");
            else if(g==0&&b==1)
                printf("BG\n");
            else
                printf("BGR\n");
        }
		else if(g>1)
        {
        	if(r==1&&b==0)
                printf("BR\n");
            else if(r==0&&b==1)
                printf("BR\n");
            else
                printf("BGR\n");
        }
		else if(b>1)
        {
        	if(g==1&&r==0)
                printf("GR\n");
            else if(g==0&&r==1)
                printf("GR\n");
            else
                printf("BGR\n");
        }
		else
			printf("BGR\n");
	}
	return 0;
}
