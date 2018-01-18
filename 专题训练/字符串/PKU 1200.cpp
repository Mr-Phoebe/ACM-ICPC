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
#define eps 1e-9
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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

const int MAXN=16000010;
const int MOD=100007;
char str[MAXN];
bool hash[10000000];
int ansi[256];


int main()
{
	int n,nc;
	while(read(n)&&read(nc))
	{
		int ans=0;
		gets(str);
		memset(hash,0,sizeof(hash));
		memset(ansi,0,sizeof(ansi));
		int len=strlen(str);
		for(int i=0;i<len;i++)
			ansi[str[i]]=1;
        int cnt=0;
        for(int i=0;i<256;i++)
			if(ansi[i])
				ansi[i]=cnt++;
		for(int i=0;i<len-n+1;i++)
		{
			ull sum=0;
			for(int j=i;j<i+n;j++)
				sum=sum*nc+ansi[str[j]];
			if(!hash[sum])
			{
				ans++;
				hash[sum]=true;
			}	
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}