#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <utility>
#include <cctype>
#include <list>

using namespace std;

#define FORALL(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORB(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef long double ld;
typedef complex<ld> vec;
typedef unsigned int uint;

typedef pair<int,int> pii;
typedef map<int,int> mii;

#define pb push_back
#define mp make_pair

#define INF 2000005000
#define MAXN 55
struct edge { int b; int cap,f,cost; int rev_id; };
vector<edge> E[MAXN];
int dist[MAXN];
int from[MAXN], from_edge[MAXN];
int res[MAXN];

struct sf{
	bool operator()(const int& a, const int& b) const {
		return dist[a] > dist[b];
	}
};

int find_aug(int s, int t) {
	FORALL(i,s,t) dist[i] = INF, res[i] = 0;
	priority_queue<int, vector<int>, sf> Q;
	dist[s] = 0; res[s] = INF;
	Q.push(s);
	while(!Q.empty()) {
		int i = Q.top(); Q.pop();
		if (i==t) return res[t];
		int numE = E[i].size();
		FOR(x,numE) {
			int j = E[i][x].b;
			int c = min(E[i][x].cap-E[i][x].f, res[i]);
			int newdist = dist[i] + E[i][x].cost;
			if (c && (newdist < dist[j])) {
				dist[j] = newdist;
				res[j] = c, from[j] = i, from_edge[j] = x;
				Q.push(j);
			}
		}
	}
	return res[t];
}

#warning add sanity check
// modified min-cost-max-flow to solve this problem
unsigned int min_cost_max_flow(int N, int K) {
	int ans=0,flow=0,tmp=0,cst=0;
	while((tmp=find_aug(0,N-1))) {
		//assert(dist[N-1] >= 0);
		//cout << cst << " " << ans << endl;
		//cout << tmp << endl;
		//cout << cst << endl << dist[N-1] << " " << flow << " " << ans << endl;
		if (dist[N-1] > 0) tmp = min(tmp,1); 
		for(int j = N-1, i = from[j]; j != 0; j = i, i = from[j]) {
			int x = from_edge[j];
			int y = E[i][x].rev_id;
			E[i][x].f += tmp;
			E[j][y].f -= tmp;
			assert(E[j][y].rev_id == x);
			assert(E[i][x].f <= E[i][x].cap);
			assert(E[j][y].f <= E[j][y].cap);
		}
		
		cst += tmp*dist[N-1];
		flow += tmp;
		if (cst <= K) ans = max(ans,flow);
		else break;
	}
	
	return ans;
}

void add_edge(int a, int b, int cap, int cost) {
	edge x = {b,cap,0,cost,(int)E[b].size()};
	edge y = {a,0,0,-cost,(int)E[a].size()};
	E[a].pb(x); E[b].pb(y);
}

int main () {
	int N,K,c;
	cin >> N >> K;
	FOR(i,N) FOR(j,N) {
		//c = rand()%1000000;
		cin >> c;
		if (!c) continue;
		add_edge(i,j,c,0);
		add_edge(i,j,K,1);
	}
	
	int ans = min_cost_max_flow(N,K);
	cout << ans << endl;
}