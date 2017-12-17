#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
#include <complex>
#include <bitset>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef double DB;

#define pb push_back
#define mset(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#define X first
#define Y second

#define Error(x) cout << #x << " = " << x << endl

template <typename T, typename U> 
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}

const int MAXL = 2 * 222222;
const int MAXC = 27;

int n, m;
int sz, last;
int nxt[MAXL][MAXC], lnk[MAXL], len[MAXL], pos[MAXL];
char s[MAXL];

void init() {
	sz = 0;
	len[0] = 0;
	lnk[0] = -1;
	last = 0;
	memset(nxt[0], 0, 4 * 27);
}

int newNode() {
	++sz;
	memset(nxt[sz], 0, 4 * 27);
	return sz;
}

void extend(char c, int j) {
	int cur = newNode(), p;
	len[cur] = len[last] + 1;
	pos[cur] = j;
	for (p = last; p != -1 && !nxt[p][c]; p = lnk[p]) nxt[p][c] = cur;
	if (p == -1) lnk[cur] = 0;
	else {
		int q = nxt[p][c];
		if (len[q] == len[p] + 1) lnk[cur] = q;
		else {
			int clone = newNode();
			len[clone] = len[p] + 1;
			pos[clone] = j;
			lnk[clone] = lnk[q];
			for (int j = 0; j < MAXC; ++j) nxt[clone][j] = nxt[q][j];
			for (; p != -1 && nxt[p][c] == q; p = lnk[p]) nxt[p][c] = clone;
			lnk[q] = lnk[cur] = clone;
		}
	}
	last = cur;
}

int main() {

	int ncase, tc(0);
	for (scanf("%d", &ncase); ncase--; ) {
		printf("Case #%d:\n", ++tc);
		init();
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%s", s);
			for (int j = 0; s[j]; j++) extend(s[j] - 'a', j + 1);
			extend(26, 0);
		}
		for (int i = 0; i < m; i++) {
			scanf("%s", s);
			int cur = 0;
			for (int j = 0; s[j]; j++) {
				cur = nxt[cur][s[j] - 'a'];
				if (cur == 0) break;
			}
			printf("%d\n", min(pos[cur], len[cur]) - len[lnk[cur]]);
		}
	}

	return 0;
}

