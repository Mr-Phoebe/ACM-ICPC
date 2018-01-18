#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
const int maxn = 200010;

int n, m, w[maxn], sumv[maxn];
vector<int> G[maxn];
map<int, int> M;
map<int, int>::iterator it;

void ins(int x, int c)
{
	for(int i = x; i < maxn; i += i&(-i))
		sumv[i] += c;
}

int getsum(int x)
{
	int ans = 0;
	for(int i = x; i; i -= i&(-i))
		ans += sumv[i];
	return ans;
}

int main()
{
	int u, v;
	while(cin >> n >> m)
	{
		for(int i = 0; i <= n; i++)
			G[i].clear();
		memset(sumv, 0, sizeof sumv);
		M.clear();
		
		for(int i = 2; i <= n; i++)
			scanf("%d", w+i);

		for(int i = 1; i <= m; i++) {
			scanf("%d%d", &u, &v);
			if(u > v) swap(u, v);
			G[u].push_back(i);
			G[v].push_back(-i);
		}

		for(int i = 0; i < G[1].size(); i++)
			M[G[1][i]] = 1;
		for(int i = 2; i <= n; i++) {
			int x, y;
			if(!M.empty()) {
				it = M.begin(); x = it->first;
				it = M.end(); y = (--it)->first;
				ins(x, w[i]);
				ins(y+1, -w[i]);
			}
			for(int j = 0; j < G[i].size(); j++) {
				v = G[i][j];
				if(v > 0) M[v] = 1;
				else M.erase(-v);
			}
		}
		for(int i = 1; i <= m; i++)
			printf("%d\n", getsum(i));
	}
	return 0;
}