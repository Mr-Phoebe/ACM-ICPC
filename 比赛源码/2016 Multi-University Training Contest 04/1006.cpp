#include<time.h>
#include<stdlib.h>
#include<assert.h>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define rep(i,l,r) for(int i=l;i<(r);++i)
#define per(i,l,r) for(int i=r-1;i>=(l);--i)
#define sz(x) ((int)((x).size()))
#define sqr(x) ((ll)(x)*(x))
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define de(x) cout << #x << " = " << x << endl;
#define debug(x) freopen(x".in", "r", stdin);
#define setIO(x) freopen(x".in", "r", stdin);freopen(x".out", "w", stdout);
const ll LINF = 1e18 + 7;
const ul BASE = 33;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double Pi = acos(-1.);
const double EPS = 1e-8;
ll kpow(ll a, ll b) {
	ll ret = 1;
	for (; b; b >>= 1, a = a * a)
		if (b & 1)
			ret = ret * a;
	return ret;
}
//--------------head--------------
char ch, str[N];
int r[N], nx[N];
int rk[N], sa[N], ht[N], wa[N], wb[N], wx[N], wv[N];
bool isq(int *r, int a, int b, int len) {
	return r[a] == r[b] && r[a + len] == r[b + len];
}
bool isEqual(int *r, int a, int b, int len) {
	return r[a] == r[b] && r[a + len] == r[b + len];
}
void getSa(int r[], int n, int m) {
	int i, j, p, *t, *x = wa, *y = wb;
	for (i = 0; i < m; ++i)
		wx[i] = 0;
	for (i = 0; i < n; ++i)
		++wx[x[i] = r[i]];
	for (i = 1; i < m; ++i)
		wx[i] += wx[i - 1];
	for (i = n - 1; i >= 0; --i)
		sa[--wx[x[i]]] = i;
	for (j = 1, p = 0; p < n; j <<= 1, m = p) {
		for (p = 0, i = n - j; i < n; ++i)
			y[p++] = i;
		for (i = 0; i < n; ++i)
			sa[i] >= j ? y[p++] = sa[i] - j : 0;
		for (i = 0; i < m; ++i)
			wx[i] = 0;
		for (i = 0; i < n; ++i)
			++wx[wv[i] = x[y[i]]];
		for (i = 1; i < m; ++i)
			wx[i] += wx[i - 1];
		for (i = n - 1; i >= 0; --i)
			sa[--wx[wv[i]]] = y[i];
		p = 1, t = x, x = y, y = t;
		x[sa[0]] = 0;
		for (i = 1; i < n; ++i)
			x[sa[i]] = isEqual(y, sa[i], sa[i - 1], j) ? p - 1 : p++;
	}
}
void getHet(int r[], int n) {
	int i, j, k = 0;
	for (i = 1; i <= n; ++i)
		rk[sa[i]] = i;
	for (i = 0; i < n; ht[rk[i++]] = k) {
		k = k > 0 ? k - 1 : 0;
		j = sa[rk[i] - 1];
		while (r[i + k] == r[j + k])
			++k;
	}
}
int main() {
//	setIO("data");
	int T;
	scanf("%d", &T);
	rep(cas, 0, T)
	{
		scanf(" %c", &ch);
		scanf(" %s", str);
		int len = strlen(str);
		rep(i, 0, len)
			r[i] = str[i] - 'a' + 1;
		r[len] = 0;
		getSa(r, len + 1, 30);
		getHet(r, len);
		nx[len] = len;
		per(i, 0, len)
			nx[i] = (str[i] == ch ? i : nx[i + 1]);
		ll ans = 0;
		rep(i, 1, len + 1)
			ans += len - max(sa[i] + ht[i], nx[sa[i]]);
		printf("Case #%d: %I64d\n", cas + 1, ans);
	}
	return 0;
}
