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

#define X first
#define Y second
// #define X real()
// #define Y imag()
// #define cin fin
// #define cout fout

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int maxn = 3 * 1e5;

//ll n, p, cnt, d[maxn];
//pll a[maxn];
//map<pll, ll> mp;


int main()
{
	int n,mug;
	int a[111];
	scanf("%d %d",&n,&mug);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	for(int i=0;i<n-1;i++)
		mug-=a[i];
	if(mug>=0)
		puts("YES");
	else
		puts("NO");
		
	return 0;
} 
