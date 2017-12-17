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

const int MN = 210;
const int L = 3;
const int MOD = 1e9 + 7;
const LL oo = LL(1e18);

int n, m, K, now, pre, hn, rlt, rltc, shift;
int maze[10][10];
LL A[MN][MN], a[MN][MN], b[MN][MN], ans[MN][MN];
int AC[MN][MN], ac[MN][MN], bc[MN][MN], ansc[MN][MN];
map<int, int> H;
map<int, PII> dp[2];
map<int, PII>::iterator it;
int S[MN], cnt[10];
int code[10], ch[10], cc[10];
int id[10];

void go(int f, int h, int s) {
	if (f == m) {
		int c = 0;
		for (int i = 1; i <= (m + 1) / 2; i++)
			if (cnt[i] == 1) c++;
		if (c != 1) return;
		for (int i = 0; i < m; i++) if (id[i]) {
			for (int j = i + 1; j < m; j++) if (id[j]) {
				for (int k = j + 1; k < m; k++) if (id[k]) {
					if (id[i] != id[k]) continue;
					if (cnt[id[j]] == 1) return;
					for (int t = k + 1; t < m; t++) if (id[t]) {
						if (id[j] == id[t]) return;
					}
				}
			}
		}
		H[h] = hn;
		S[hn++] = h;
		return;
	}
	for (int i = 0; i <= (m + 1) / 2; i++) {
		if (i > 0 && cnt[i] == 2) continue;
		if (i > 0 && cnt[i] == 0 && i != s + 1) continue;
		id[f] = i;
		cnt[i]++;
		go(f + 1, (h << L) + i, max(s, i));
		cnt[i]--;
	}
}

int tot;

inline int encode() {
	int s = 0;
	int cnt = 1;
	if (shift) {
		if (code[m]) return -1;
		for (int i = m; i > 0; i--) code[i] = code[i - 1];
		code[0] = 0;
	}
	memset(ch, -1, sizeof(ch));
	ch[0] = 0;
	for (int i = 0; i <= m; i++) {
		if (ch[code[i]] == -1) ch[code[i]] = cnt++;
		cc[i] = ch[code[i]];
	}
	for (int i = 0; i <= m; i++) {
		s <<= L;
		s += cc[i];
	}
	return s;
}

inline void decode(int s) {
	for (int i = m; i >= 0; i--) {
		code[i] = s & (bit(L) - 1);
		s >>= L;
	}
}

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

inline void push() {
	int s = encode();
	if (s == -1) return;
	if (dp[now].count(s)) {
		if (dp[now][s].X < rlt) {
			dp[now][s] = PII(rlt, rltc);	
		} else if (dp[now][s].X == rlt) {
			add(dp[now][s].Y, rltc);
		}
	} else {
		dp[now][s] = PII(rlt, rltc);
	}
}

void build() {
	H.clear();
	hn = 0;
	go(0, 0, 0);
	memset(A, 0xcf, sizeof A);
	memset(AC, 0, sizeof AC);

	for (int hid = 0; hid < hn; hid++) {
		now = 0, pre = 1;
		dp[0].clear();
		dp[1].clear();

		dp[now][S[hid]] = PII(0, 1);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				swap(now, pre);
				dp[now].clear();
				shift = (j == m);
				for (it = dp[pre].begin(); it != dp[pre].end(); it++) {
					decode(it->X);
					rlt = it->Y.X;
					rltc = it->Y.Y;
					int left = code[j - 1];
					int up = code[j];
					int ma = max(left, up);
					int mi = min(left, up);
					
					if (!maze[i][j]) {
						if (left == 0 && up == 0) push();
						continue;
					}
					if (mi > 0) {
						if (left == up) continue;
						code[j - 1] = code[j] = 0;
						for (int k = 0; k <= m; k++) {
							if (code[k] == left) {
								code[k] = up;
								break;
							}
							if (code[k] == up) {
								code[k] = left;
								break;
							}
						}
						rlt++;
						push();
					} else if (ma > 0) {
						rlt++;
						code[j] = ma, code[j - 1] = 0;
						push();
						code[j] = 0, code[j - 1] = ma;
						push();
					} else {
						push();
						rlt++;
						code[j] = code[j - 1] = 7;
						push();
					}
				}
			}
		}
		for (it = dp[now].begin(); it != dp[now].end(); it++) {
			int s = it->X;
			if (A[hid][H[s]] < it->Y.X) {
				A[hid][H[s]] = it->Y.X;
				AC[hid][H[s]] = it->Y.Y;
			} else if (A[hid][H[s]] == it->Y.X) {
				add(AC[hid][H[s]], it->Y.Y);
			}
		}
	}
}

void multi(LL _a[MN][MN], LL _b[MN][MN], LL c[MN][MN], int _ac[MN][MN], int _bc[MN][MN], int cc[MN][MN]) {
	for (int i = 0; i < hn; i++) {
		for (int j = 0; j < hn; j++) {
			a[i][j] = _a[i][j];
			b[i][j] = _b[i][j];
			ac[i][j] = _ac[i][j];
			bc[i][j] = _bc[i][j];
		}
	}

	for (int i = 0; i < hn; i++) {
		for (int j = 0; j < hn; j++) {
			LL tmp = -oo, tmpc = 0;
			for (int k = 0; k < hn; k++) {
				if (tmp < a[i][k] + b[k][j]) {
					tmp = a[i][k] + b[k][j];
					tmpc = (LL)ac[i][k] * bc[k][j];
				} else if (tmp == a[i][k] + b[k][j]) {
					tmpc += (LL)ac[i][k] * bc[k][j];
				}
				if (tmpc > oo) tmpc %= MOD;
			}
			c[i][j] = tmp;
			cc[i][j] = tmpc % MOD;
		}
	}
}

void solve() {
  for (int i = 0; i < hn; i++) {
    for (int j = 0; j < hn; j++) {
      ans[i][j] = (i == j ? 0 : -oo);
      ansc[i][j] = (i == j);
    }
  }
  while (K) {
    if (K & 1) multi(ans, A, ans, ansc, AC, ansc);
    multi(A, A, A, AC, AC, AC);
    K >>= 1;
	}
	for (int i = m - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (j != m - 1) putchar(' ');
			printf("%lld", max(0LL, ans[H[bit(L * i)]][H[(bit(L * j))]]));
		} puts("");
	}
	for (int i = m - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (j != m - 1) putchar(' ');
			printf("%d", ansc[H[bit(L * i)]][H[(bit(L * j))]]);
		} puts("");
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	
	int ncase, tc(0);
	for (scanf("%d", &ncase); ncase--; ) {
		printf("Case #%d:\n", ++tc);
		memset(maze, 0, sizeof maze);
		scanf("%d%d%d", &n, &m, &K);
		for (int i = 0; i < n; i++) {
			char s[10];
			scanf("%s", s);
			for (int j = 0; j < m; j++) {
				maze[i + 1][j + 1] = (s[j] == '.');
			}
		}
		build();
		solve();
	}

	return 0;
}

