#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 100010;

struct Seg {
	int a, b, c;
	Seg() {}
	Seg(int a, int b, int c): a(a), b(b), c(c) {}
	bool operator < (const Seg &rhs) const {
		return a == rhs.a ? c < rhs.c : a < rhs.a;
	}
}v[maxn], h[maxn], tmp[maxn*4];

int n, val[maxn*4], cnt, cv, ch, ct;
int sum[maxn*4], num[maxn*4];

inline int idx(int a)
{
	return lower_bound(val, val+cnt, a) - val + 1;
}

void ins(int x, int c)
{
	for(int i = x; i < maxn*4; i += i&(-i))
		sum[i] += c;
}

int getsum(int x)
{
	int ans = 0;
	for(int i = x; i > 0; i -= i&(-i))
		ans += sum[i];
	return ans;
}

int main()
{
	int T_T, x1, x2, y1, y2;
	cin >> T_T;
	while(T_T--)
	{
		scanf("%d", &n);
		cnt = 0; cv = 0; ch = 0; ct = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			val[cnt++] = x1;
			val[cnt++] = x2;
			val[cnt++] = y1;
			val[cnt++] = y2;
			if(x1 == x2) {
				v[cv].a = x1;
				v[cv].b = min(y1, y2);
				v[cv].c = max(y1, y2);
				cv++;
			} else {
				h[ch].a = y1;
				h[ch].b = min(x1, x2);
				h[ch].c = max(x1, x2);
				ch++;
			}
		}
		sort(val, val+cnt);
		cnt = unique(val, val+cnt) - val;

		for(int i = 0; i < cv; i++) {
			v[i].a = idx(v[i].a);
			v[i].b = idx(v[i].b);
			v[i].c = idx(v[i].c);
			tmp[ct++] = Seg(v[i].a, i, 1);
		}
		for(int i = 0; i < ch; i++) {
			h[i].a = idx(h[i].a);
			h[i].b = idx(h[i].b);
			h[i].c = idx(h[i].c);
			tmp[ct++] = Seg(h[i].b, i, 0);
			tmp[ct++] = Seg(h[i].c, i, 2);
		}
		sort(tmp, tmp+ct);

		long long ans = 0;
		for(int i = 0; i < ct; i++) {
			if(tmp[i].c == 1) {
				ans += getsum(v[tmp[i].b].c) - getsum(v[tmp[i].b].b-1);
			} else if(tmp[i].c == 0) {
				ins(h[tmp[i].b].a, 1);
			} else {
				ins(h[tmp[i].b].a, -1);
			}
		}
		cout << ans << endl;
	}
	return 0;
}