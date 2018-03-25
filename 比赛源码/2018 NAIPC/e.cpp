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

#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62
#define speed std::ios::sync_with_stdio(false);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define CPY(x,y) memcpy(x,y,sizeof(x))
#define clr(a,x,size) memset(a,x,sizeof(a[0])*(size))
#define cpy(a,x,size) memcpy(a,x,sizeof(a[0])*(size))
#define debug(a) cout << #a" = " << (a) << endl;
#define debugarry(a, n) for (int i = 0; i < (n); i++) { cout << #a"[" << i << "] = " << (a)[i] << endl; }

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))

#define MID(x,y) (x+((y-x)>>1))
#define ls (idx<<1)
#define rs (idx<<1|1)
#define lson ls,l,mid
#define rson rs,mid+1,r

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

#define MOD 1000000007
#define int long long

int bit[1000006];
int fac[1000006];
int inv[1000006];

int power(int x,int p){
	int res = 1;
	for(int i=0;i<60;i++){
		if(p&(1LL<<i)){
			res *= x;
			res %= MOD;
		}
		x *= x;
		x %= MOD;
	}
	return res;
}

void update(int x){
	while(x < 1000006){
		bit[x] += 1;
		x += (x&-x);
	}
	return;
}

int sum(int x){
	int sum = 0;
	while(x > 0){
		sum += bit[x];
		x -= (x&-x);
	}
	return sum;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fac[0] = 1;
	inv[0] = 1;
	for(int i=1;i<1000006;i++){
		fac[i] = fac[i-1]*i;
		fac[i] %= MOD;
		inv[i] = power(fac[i], MOD-2);
	}
	int n,m;
	cin >> n >> m;
	vector<string> s(n);
	int pr = 31;

	for(int i=0;i<n;i++){
		cin >> s[i];
	}
	map<int, int> mp;
	sort(s.begin(),s.end());
	for(int i=0;i<n;i++){
		int temp = 0;
		for(int j=0;j<s[i].length();j++){
			temp = temp*pr + (s[i][j] - 'a');
			temp ^= 99937;
		}
		mp[temp] = i+1;
	}
	string t;
	cin >> t;
	int cur = 0;
	string temp = "";
	int hash = 0;
	int res = 0;
	for(int i=0;i<t.length();i++){
		hash = hash*pr + (t[i]-'a');
		hash ^= 99937;
		if(mp.find(hash) != mp.end()){
			//cout << temp << endl;
			int curTemp = fac[n-cur-1];
			curTemp *= inv[n-m];
			curTemp %= MOD;
			curTemp *= (mp[hash] - sum(mp[hash]) - 1);
			curTemp %= MOD;
			update(mp[hash]);
			hash = 0;
			res += curTemp;
			res %= MOD;
			cur++;
			//cout << cur << " " << curTemp << " " << res << endl;
		}
	}
	res += 1;
	res %= MOD;
	cout << res << endl;
	return 0;
}