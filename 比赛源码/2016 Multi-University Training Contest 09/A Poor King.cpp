#include <cstdio>
#include <cstring>
#include <cassert>

char typ[] = "RBQ";
const int N = 64;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, -1, 1, -1, 1};
int st[] = {0, 4, 0};
int en[] = {4, 8, 8};
bool chk[3][N][N][N];
int val[3][3][N][N][N];
int t1, t2;

inline bool in(int x, int y) {
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}

bool go(int p1, int p2, int p, int s) {
	int x1, y1, x2, y2, x, y;
	int d, u, v, q1, q2, cnt, e, xx, yy, q;
	
	if (val[t1][t2][p1][p2][p]) return 0;
	x1 = p1 / 8, y1 = p1 % 8;
	x2 = p2 / 8, y2 = p2 % 8;
	x = p / 8, y = p % 8;
	for (d = st[t1]; d < en[t1]; d++) {
		u = x1, v = y1;
		while (1) {
			u += dx[d], v += dy[d];
			q1 = u * 8 + v;
			if (!in(u, v) || q1 == p2) break;
			cnt = 0;
			for (e = 0; e < 8; e++) {
				xx = x + dx[e], yy = y + dy[e];
				if (!in(xx, yy)) continue;
				q = xx * 8 + yy;
				if (chk[t1][q1][p2][q] || chk[t2][p2][q1][q]) continue;
				if (q == q1 || q == p2) break;
				cnt++;
				if (!val[t1][t2][q1][p2][q] || val[t1][t2][q1][p2][q] >= s) break;
			}
			if (e < 8) continue;
			if (!chk[t1][q1][p2][p] && !cnt) continue;
			return 1;
		}
	}
	for (d = st[t2]; d < en[t2]; d++) {
		u = x2, v = y2;
		while (1) {
			u += dx[d], v += dy[d];
			q2 = u * 8 + v;
			if (!in(u, v) || q2 == p1) break;
			cnt = 0;
			for (e = 0; e < 8; e++) {
				xx = x + dx[e], yy = y + dy[e];
				if (!in(xx, yy)) continue;
				q = xx * 8 + yy;
				if (q == q2) {
					if (chk[t1][p1][q2][q]) continue;
					break;
				}
				if (q == p1) {
					if (chk[t2][q2][p1][q]) continue;
					break;
				}
				if (chk[t1][p1][q2][q] || chk[t2][q2][p1][q]) continue;
				cnt++;
				if (!val[t1][t2][p1][q2][q] || val[t1][t2][p1][q2][q] >= s) break;
			}
			if (e < 8) continue;
			if (!chk[t2][q2][p1][p] && !cnt) continue;
			return 1;
		}
	}
	return 0;
}

void init_chk() {
	int t, a, b, c, d, x, y;
	
	for (t = 0; t < 3; t++) {
		for (a = 0; a < N; a++) {
			for (b = 0; b < N; b++) {
				for (c = 0; c < N; c++) {
					for (d = st[t]; d < en[t]; d++) {
						x = a / 8, y = a % 8;
						while (1) {
							x += dx[d], y += dy[d];
							if (!in(x, y)) break;
							if (x * 8 + y == b || x * 8 + y == c) break; 
						}
						if (!in(x, y)) continue;
						if (x * 8 + y == c) break;
					}
					chk[t][a][b][c] = (d < en[t]);
				}
			}
		}
	}
}

void init() {
	int a, b, c, s, flg;
	
	init_chk();
	for (t1 = 0; t1 < 3; t1++) {
		for (t2 = 0; t2 < 3; t2++) {
			for (a = 0; a < N; a++) {
				for (b = 0; b < N; b++) {
					for (c = 0; c < N; c++) {
						flg = 0;
						if (a == b || a == c || b == c) flg++;
						if (chk[t1][a][b][c] || chk[t2][b][a][c]) flg++;
						if (flg) val[t1][t2][a][b][c] = -1;
					}
				}
			}
		}
	}
	for (t1 = 0; t1 < 3; t1++) {
		t2 = t1;
		for (s = 1; ; s++) {
			flg = 0;
			for (a = 0; a < N; a++) {
				for (b = a + 1; b < N; b++) {
					for (c = 0; c < N; c++) {
						if (!go(a, b, c, s)) continue;
						val[t1][t2][a][b][c] = val[t2][t1][b][a][c] = s;
						flg++;
					}
				}
			}
			if (!flg) break;
		}
		
		for (t2 = t1 + 1; t2 < 3; t2++) {
			for (s = 1; ; s++) {
				flg = 0;
				for (a = 0; a < N; a++) {
					for (b = 0; b < N; b++) {
						for (c = 0; c < N; c++) {
							if (!go(a, b, c, s)) continue;
							val[t1][t2][a][b][c] = s;
							flg++;
						}
					}
				}
				if (!flg) break;
			}
			for (a = 0; a < N; a++) {
				for (b = 0; b < N; b++) {
					for (c = 0; c < N; c++) val[t2][t1][b][a][c] = val[t1][t2][a][b][c];
				}
			}
		}
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	
	int tc, a, b, c;
	char s[5], tp1[5], t[5], tp2[5], r[5];
	
	init();
	for (scanf("%d", &tc); tc--; ) {
		scanf("%s%s%s%s%s", s, tp1, t, tp2, r);
        c = (s[0] - 'a') * 8 + (s[1] - '1');
		t1 = strchr(typ, tp1[0]) - typ;
        a = (t[0] - 'a') * 8 + (t[1] - '1');
        t2 = strchr(typ, tp2[0]) - typ;
        b = (r[0] - 'a') * 8 + (r[1] - '1');
		printf("%d\n", val[t1][t2][a][b][c]);
	}
	return 0;
}
