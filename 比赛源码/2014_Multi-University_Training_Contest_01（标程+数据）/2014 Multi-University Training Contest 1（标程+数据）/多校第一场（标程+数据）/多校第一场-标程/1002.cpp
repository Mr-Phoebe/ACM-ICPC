#include <queue>
#include <limits>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

template<int MAXN, typename T = int, typename S = T>
struct MinCostMaxFlow {
	struct NegativeCostCircuitExistsException {
	};

	struct Edge {
		int v;
		T c;
		S w;
		int b;
		Edge(int v, T c, S w, int b) :
			v(v), c(c), w(w), b(b) {
		}
	};

	int n, source, sink;
	vector<Edge> e[MAXN];

	void init(int n, int source, int sink) {
		this->n = n;
		this->source = source;
		this->sink = sink;
		for (int i = 0; i < n; ++i) {
			e[i].clear();
		}
	}

	void addEdge(int a, int b, T c, S w) {
		e[a].push_back(Edge(b, c, w, e[b].size()));
		e[b].push_back(Edge(a, 0, -w, e[a].size() - 1));
	}

	bool mark[MAXN];
	T maxc[MAXN];
	S minw[MAXN];
	int dist[MAXN];
	Edge* prev[MAXN];

	bool _spfa() {
		queue<int> q;
		fill(mark, mark + n, false);
		fill(maxc, maxc + n, 0);
		fill(minw, minw + n, numeric_limits<S>::max());
		fill(dist, dist + n, 0);
		fill(prev, prev + n, (Edge*) NULL);
		mark[source] = true;
		maxc[source] = numeric_limits<S>::max();
		minw[source] = 0;

		q.push(source);
		while (!q.empty()) {
			int cur = q.front();
			mark[cur] = false;
			q.pop();
			for (typename vector<Edge>::iterator it = e[cur].begin(); it
					!= e[cur].end(); ++it) {
				T c = min(maxc[cur], it->c);
				if (c == 0) {
					continue;
				}

				int v = it->v;
				S w = minw[cur] + it->w;
				if (minw[v] > w || (minw[v] == w && maxc[v] < c)) { // TODO
					maxc[v] = c;
					minw[v] = w;
					dist[v] = dist[cur] + 1;
					if (dist[v] >= n) {
						return false;
					}
					prev[v] = &*it;
					if (!mark[v]) {
						mark[v] = true;
						q.push(v);
					}
				}
			}
		}
		return true;
	}

	pair<T, S> gao() {
		T sumc = 0;
		S sumw = 0;
		while (true) {
			if (!_spfa()) {
				throw NegativeCostCircuitExistsException();
			} else if (maxc[sink] == 0) {
				break;
			} else {
				T c = maxc[sink];
				sumc += c;
				sumw += c * minw[sink];

				int cur = sink;
				while (cur != source) {
					Edge* e1 = prev[cur];
					e1->c -= c;
					Edge* e2 = &e[e1->v][e1->b];
					e2->c += c;
					cur = e2->v;
				}
			}
		}
		return make_pair(sumc, sumw);
	}
};

const int MAXN = 150 * 2 + 2;

MinCostMaxFlow<MAXN> mcmf;

int n, m;

char s[15][15];
int id[15][15];
int cnt;
pair<int, int> gao(int mid) {
	mcmf.init(2 * cnt + 3, 2 * cnt, 2 * cnt + 1);
	mcmf.addEdge(2 * cnt, 2 * cnt + 2, mid, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int x = i + 1; x < n; ++x) {
				int tmp = x - i-1;
				if (s[i][j] == s[x][j])
					tmp -= (s[i][j] - '0');
				mcmf.addEdge(id[i][j], n * m + id[x][j], 1, tmp);
			}
			for (int x = j + 1; x < m; ++x) {
				int tmp = x - j-1;
				if (s[i][j] == s[i][x])
					tmp -= (s[i][j] - '0');
				mcmf.addEdge(id[i][j], n * m + id[i][x], 1, tmp);
			}
			mcmf.addEdge(2 * cnt, id[i][j], 1, 0);
			mcmf.addEdge(n * m + id[i][j], 2 * cnt + 1, 1, 0);
			mcmf.addEdge(2 * cnt + 2, n * m + id[i][j], 1, 0);
		}
	}
	pair<int, int> a = mcmf.gao();
	return a;

}
int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int ri = 0, tt, k;
	scanf("%d", &tt);
	while (tt--) {
		scanf("%d%d%d", &n, &m, &k);
		cnt = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%s", s[i]);
			for (int j = 0; j < m; ++j)
				id[i][j] = cnt++;
		}
		//constuct graph...

		pair<int, int> ans = gao(k);
		if (ans.first == n * m) {
			printf("Case %d : %d\n", ++ri, -ans.second);
		} else {
			printf("Case %d : -1\n", ++ri);
		}
	}
	return 0;
}
