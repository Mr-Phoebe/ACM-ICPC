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

string a;
int n,p;

bool dfs(int i)
{
	if(i>=a.length())
		return 1;
	if(i==n-1)
		a.at(n-1)++;
	for(;a.at(i)<=p+'a'-1;a.at(i)++)
	{
		if(a.at(i)!=a.at(i-1) && !(i>1&&a.at(i-2)==a.at(i)) && dfs(i+1))  
                return 1;
	}
		
        
	a.at(i)='a';
	if(i==n-1)
		a.at(i)--;   
  	return 0;
}

int main()
{
	read(n),read(p);
	cin>>a;
	if(n==1)
	{
		if(a.at(0)=='a'+p-1)
			puts("NO");
		else
			cout<<(char)(a.at(0)+1)<<endl;
		return 0;
	}
	for(;a.at(0)<='a'+p-1;a.at(0)++)
		if(dfs(1))
			goto OK;
	goto No;
OK:
	cout<<a<<endl;
	return 0;
No: 
	cout<<"NO"<<endl;
	return 0;
} 