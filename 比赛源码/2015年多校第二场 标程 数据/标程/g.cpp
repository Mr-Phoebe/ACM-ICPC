#include <cstdio>
#include <algorithm>
#include <ctime>
#include <string.h>
using namespace std;

#define N 2100000


int n, m, t, x, y, z, a[N];

char *ch, *ch1, buf[40*1024000+5], buf1[40*1024000+5];

void read(int &x) {
	for (++ch; *ch <= 32; ++ch);
	for (x = 0; '0' <= *ch; ch++)	x = x * 10 + *ch - '0';
}

void out(int x) {
	if (!x)	*(++ch1) = '0';
	else {
		char *ch0 = ch1, *ch = ch1 + 1;
		while (x) {
			*(++ch0) = x % 10 + '0';
			x /= 10;
		}
		ch1 = ch0;
		while (ch <= ch0)	swap(*(ch++), *(ch0--));
	}
	*(++ch1) = '\n';
}

void out(long long x) {
	if (!x)	*(++ch1) = '0';
	else {
		char *ch0 = ch1, *ch = ch1 + 1;
		while (x) {
			*(++ch0) = x % 10 + '0';
			x /= 10;
		}
		ch1 = ch0;
		while (ch <= ch0)	swap(*(ch++), *(ch0--));
	}
	*(++ch1) = '\n';
}

struct T {
	int s, Tag, Max, MaxTag, cover;
	long long Sum;
} F[N];

T put(T c, int t) {
	// s1++;
	if (!t) return c;
	if (c.cover != c.s) c.Max = t;
	c.MaxTag = t;
	c.Sum += 1LL * (c.s - c.cover) * t;
	c.cover = c.s;
	return c;
}

T calc(T a, T b, int t) {
	// s2++;
	T c;
	c.Tag = t;
	c.s = a.s + b.s;
	c.Max = max(a.Max, b.Max);
	c.MaxTag = max(a.MaxTag, b.MaxTag);
	c.cover = a.cover + b.cover;
	c.Sum = a.Sum + b.Sum;
	return put(c, t);
}

void mkt(int k, int q, int h) {
	F[k].Tag = 0;
	F[k].s = h - q + 1;
	if (q < h) {
		mkt(k * 2, q, (q + h) / 2);
		mkt(k * 2 + 1, (q + h) / 2 + 1, h);
		F[k] = calc(F[k * 2], F[k * 2 + 1], 0);
	}else {
		F[k].Tag = F[k].MaxTag = F[k].Sum = F[k].Max = a[q];
		F[k].cover = 1;
	}
}

T query(int k, int q, int h, int l, int r) {
	if (l <= q && h <= r) return F[k];
	if (r <= (q + h) / 2) return put(query(k * 2, q, (q + h) / 2, l, r), F[k].Tag);
	if ((q + h) / 2 < l)  return put(query(k * 2 + 1, (q + h) / 2 + 1, h, l, r), F[k].Tag);
	return calc(query(k * 2, q, (q + h) / 2, l, r), query(k * 2 + 1, (q + h) / 2 + 1, h, l, r), F[k].Tag);
}

void Clear(int k, int t) {
	// printf("?? %d %d\n", k, t);
	if (F[k].MaxTag < t) return ;
	if (F[k].Tag >= t) {
		F[k].Tag = 0;
	}
	if (F[k].s > 1) {
		Clear(k * 2, t);
		Clear(k * 2 + 1, t);
	}
	if (F[k].s == 1) {
		F[k].MaxTag = F[k].Sum = F[k].Max = F[k].Tag;
		F[k].cover = (F[k].Tag > 0);
	}else {
		F[k] = calc(F[k * 2], F[k * 2 + 1], F[k].Tag);
	}
}

void modify(int k, int q, int h, int l, int r, int t) {
	if (F[k].Tag && t >= F[k].Tag) return ;
	if (l <= q && h <= r) {
		Clear(k, t);
		F[k].Tag = t;
		if (q == h) {
			F[k].Tag = F[k].MaxTag = F[k].Sum = F[k].Max = t;
			F[k].cover = (F[k].Tag > 0);
		} else {
			F[k] = calc(F[k * 2], F[k * 2 + 1], t);
		}
	}else {
		if (r <= (q + h) / 2) modify(k * 2, q, (q + h) / 2, l, r, t);
		else if ((q + h) / 2 < l) modify(k * 2 + 1, (q + h) / 2 + 1, h, l, r, t);
		else modify(k * 2, q, (q + h) / 2, l, r, t), modify(k * 2 + 1, (q + h) / 2 + 1, h, l, r, t);
		F[k] = calc(F[k * 2], F[k * 2 + 1], F[k].Tag);
	}
}

void output(int k, int q, int h) {
	printf("%d %d %d %d %d\n", q, h, F[k].Tag, F[k].Max, F[k].MaxTag);
	if (q < h)
		output(k * 2, q, (q + h) / 2), output(k * 2 + 1, (q + h) / 2 + 1, h);
}

int main() {
	// freopen("g.in", "r", stdin);
	// freopen("a.out", "w", stdout);
	int T;
	int ans1 = 1;
	ch = buf - 1;
	ch1 = buf1 - 1;
	fread(buf, 1, 1000 * 35 * 1024, stdin);
	read(T);
	while (T--) {
		read(n); read(m);
		for (int i = 1; i <= n; i++)
			read(a[i]), ans1 = min(ans1, a[i]);
		mkt(1, 1, n);
		// output(1, 1, n);
		// printf("\n");
		while (m--) {
			read(t); read(x); read(y);
			if (!t) {
				read(z);
				ans1 = min(ans1, z);
				modify(1, 1, n, x, y, z);
			}else if (t == 1) out(query(1, 1, n, x, y).Max);
			else out(query(1, 1, n, x, y).Sum);
			// output(1, 1, n);
			// printf("\n");
		}
	}
	printf("%d\n", ans1);
	// fwrite(buf1, 1, ch1 - buf1 + 1, stdout);
	// freopen("con", "w", stdout);
	// printf("%d %d %d\n", clock(), s1, s2);
}
