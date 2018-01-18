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

const int MAXN=10010;

int dp[111],temp[111],a[MAXN];


int main()
{
	int n,k;
	CLR(temp,0),CLR(dp,0);
	read(n),read(k);
	for(int i=0;i<n;i++)
		read(a[i]);
	int aa=(a[0]%k+k)%k,ff=((-a[0])%k+k)%k;
	dp[aa]=temp[aa]=1;
	for(int i=1;i<n;i++)
	{
		CLR(temp,0);
		aa=(a[i]%k+k)%k;
		ff=((-a[i])%k+k)%k;
		for(int j=0;j<k;j++)
			if(dp[j])
			{
				if(j+aa<k)
					temp[j+aa]=1;
				if(j-aa>=0)
					temp[j-aa]=1;
				if(j+ff<k)
					temp[j+ff]=1;
				if(j-ff>=0)
					temp[j-ff]=1;
			}
		
		for(int j=0;j<k;j++)
			dp[j]=temp[j];

	}
	if(dp[0])
		cout<<"Divisible"<<endl;
	else
		cout<<"Not divisible"<<endl;
	return 0;
}