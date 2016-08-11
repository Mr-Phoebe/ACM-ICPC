#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100000 + 10;
const int M = 17;

char S[N];
int dict[M][N];
int sz[M];
int cnt[N], tmp1[N], tmp2[N];
vector<int> A[M][N];
int d, k, cn;

inline int mylog(int x)
{
	int i, j;
	for (i=1,j=0; i<x; i*=2,j++);
	return -- j;
}

inline int next(int d, const vector<int>& V, int x)
{
	int y;
	y = lower_bound(V.begin(), V.end(), x + 1) - V.begin();
	if (y < V.size())
	{
		y = V[y];
		if (y <= x + (1<<d)) return y;
	}
	return -1;
}

inline int prev(int d, const vector<int>& V, int x)
{
	int y;
	y = lower_bound(V.begin(), V.end(), x) - V.begin();
	if (y > 0)
	{
		y = V[y-1];
		if (y >= x - (1<<d)) return y;
	}
	return -1;
}

inline int intersect(const int A[], int n, const int B[], int m)
{
	int i, j;
	for (i=n-1; i>=0; i--) for (j=m-1; j>=0; j--) if (A[i] == B[j]) return A[i];
	return -1;
}

inline int intersect(const int A[], int n, int a, int d, int b)
{
	int i;
	for (i=n-1; i>=0; i--) if ((A[i] - a) % d == 0 && A[i] >= a && A[i] <= b) return A[i];
	return -1;
}

inline int intersect(int a1, int b1, int a2, int b2, int d)
{
	if (b1 < a2 || b2 < a1) return -1;
	return min(b1, b2);
}

inline void read_int(int& x)
{
	char c;
	while (c = getchar(), c < '0' || c > '9');
	x = c - '0';
	while (c = getchar(), c >= '0' && c <= '9') x = x * 10 + c - '0';
}

int main()
{
	int res, n, q, t, len, s, h, a, b, c, nxt, prv, n1, n2, i, j;
	int P[5], Q[5];
	scanf("%d", &t);
	cn = 0;
	while (t --)
	{
		printf("Case #%d:\n", ++ cn);
		scanf("%s", S);
		n = strlen(S);
		for (i=0; i<n; i++) 
		{
			dict[0][i] = S[i] - 'a' + 1;
			A[0][dict[0][i]].push_back(i);
		}
		sz[0] = 26;
		for (d=0,k=1; k*2<=n; d++,k*=2)
		{
			s = n - k * 2;
			memset(cnt, 0, sizeof(cnt[0]) * (sz[d] + 1));
			for (i=0; i<=s; i++) cnt[dict[d][i]] ++;
			for (i=2; i<=sz[d]; i++) cnt[i] += cnt[i-1];
			for (i=0; i<=s; i++) tmp1[cnt[dict[d][i]-1]++] = i;
			memset(cnt, 0, sizeof(cnt[0]) * (sz[d] + 1));
			for (i=0; i<=s; i++) cnt[dict[d][i+k]] ++;
			for (i=2; i<=sz[d]; i++) cnt[i] += cnt[i-1];
			for (i=0; i<=s; i++) tmp2[cnt[dict[d][tmp1[i]+k]-1]++] = tmp1[i];
			dict[d+1][tmp2[0]] = 1;
			A[d+1][dict[d+1][tmp2[0]]].push_back(tmp2[0]);
			for (i=1; i<=s; i++) 
			{
				dict[d+1][tmp2[i]] = dict[d+1][tmp2[i-1]] + (dict[d][tmp2[i]] != dict[d][tmp2[i-1]] || dict[d][tmp2[i]+k] != dict[d][tmp2[i-1]+k]);
				A[d+1][dict[d+1][tmp2[i]]].push_back(tmp2[i]);
			}
			sz[d+1] = dict[d+1][tmp2[s]];
		}
		h = d;
		scanf("%d", &q);
		while (q --)
		{
			read_int(a);
			read_int(b);
			a --;
			b --;
			len = b - a + 1;
			if (len == 1)
			{
				printf("1\n");
				continue;
			}
			d = mylog(len);
			nxt = next(d, A[d][dict[d][a]], a);
			if (nxt != -1 && nxt <= b - (1<<d) + 1)
			{
				prv = prev(d, A[d][dict[d][b-(1<<d)+1]], b - (1<<d) + 1);
				if (prv != -1 && prv >= a && nxt - a == b - (1<<d) + 1 - prv)
				{
					printf("%d\n", nxt - a);
					continue;
				}
			}
			res = 0;
			for (--d,k=(1<<d); d>=0; d--,k/=2)
			{
				c = b - k + 1;
				P[0] = a;
				for (n1=1; n1<=3; n1++)
				{
					P[n1] = next(d, A[d][dict[d][c]], P[n1-1]);
					if (P[n1] == -1 || P[n1] - P[0] > k) break;
				}
				n1 --;
				Q[0] = c;
				for (n2=1; n2<=3; n2++)
				{
					Q[n2] = prev(d, A[d][dict[d][a]], Q[n2-1]);
					if (Q[n2] == -1 || Q[0] - Q[n2] > k) break;
				}
				n2 --;
				if (n1 < 1 || n2 < 1) continue;
				for (j=1; j<=n1; j++) P[j] = P[j] - a + k;
				for (j=1; j<=n2; j++) Q[j] = b - Q[j] + 1;
				if (n1 > 2) 
				{
					P[n1+1] = prev(d, A[d][dict[d][c]], a + k + 1);
					P[n1+1] = P[n1+1] - a + k;
				}
				if (n2 > 2)
				{
					Q[n2+1] = next(d, A[d][dict[d][a]], b - 2 * k);
					Q[n2+1] = b - Q[n2+1] + 1;
				}
				if (n1 <= 2 && n2 <= 2) res = max(res, intersect(P + 1, n1, Q + 1, n2));
				else if (n1 <= 2 && n2 > 2) res = max(res, intersect(P + 1, n1, Q[1], Q[2] - Q[1], Q[n2+1]));
				else if (n1 > 2 && n2 <= 2) res = max(res, intersect(Q + 1, n2, P[1], P[2] - P[1], P[n1+1]));
				else res = max(res, intersect(P[1], P[n1+1], Q[1], Q[n2+1], P[2] - P[1]));
				if (res) break;
			}
			if (S[a] == S[b] && !res) res = 1;
			printf("%d\n", len - res);
		}
		for (i=0; i<=h; i++) for (j=0; j<=sz[i]; j++) A[i][j].clear();
	}
	return 0;
}
