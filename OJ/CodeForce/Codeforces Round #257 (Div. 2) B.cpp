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

using namespace std;

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

typedef long long ll;
ll a[10];
const ll MOD=1e9+7;
const int p=1e9;

int main()
{
    ll x,y,n;
    read(x);read(y);
	n--;
    a[0]=(x+MOD)%MOD;
    a[1]=(y+MOD)%MOD;
    a[2]=(y-x+2*MOD)%MOD;
    a[3]=(-1*x+MOD)%MOD;
    a[4]=(-1*y+MOD)%MOD;
    a[5]=(x-y+2*MOD)%MOD;
    if(n>=6)
		n=n%6;
    printf("%I64d\n",a[n]);
    return 0;
}
