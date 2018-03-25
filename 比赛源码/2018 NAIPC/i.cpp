#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define int long long

vector<vector<int> > g;
vector<int> red;

vector<int> reds;

vector<vector<int> > res;
int sz[200005];

void dfs(int x,int p){
	sz[x] = 0;
	reds[x] = 0;
	for(int i=0;i<g[x].size();i++){
		if(g[x][i] == p) continue;
		dfs(g[x][i],x);
		sz[x] += sz[g[x][i]];
		reds[x] += reds[g[x][i]];
	}
	if(red[x]) reds[x] += 1;
	sz[x] = max(sz[x], 1LL);
	return;
}

void solve(int x, int p){
	res[x].resize(min(sz[x], reds[x])+1);
	for(int i=0;i<res[x].size();i++) res[x][i] = 0;
	res[x][0] = 1;
	for(int i=0;i<g[x].size();i++){
		if(g[x][i] == p) continue;
		solve(g[x][i],x);
		int ss = res[g[x][i]].size();
		vector<int> vv = res[x];
		vector<int> temp = res[x];
		for(int i=0;i<temp.size();i++) temp[i] = 0;
		for(int j=0;j<ss;j++){
			for(int k=0;k<res[x].size();k++){
				if(j+k >= res[x].size()) continue;
				temp[j+k] += vv[k]*res[g[x][i]][j];
				temp[j+k] %= MOD;
			}
		}
		res[x] = temp;
	}
	if(red[x]){
		res[x][1] += 1;
	}
	else{
		res[x][0] += 1;
	}
	return;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	g.resize(n);
	int x;
	for(int i=0;i<n-1;i++){
		cin >> x;
		x--;
		g[x].push_back(i+1);
	}
	red.resize(n);
	reds.resize(n);
	res.resize(n);
	for(int i=0;i<m;i++){
		cin >> x;
		red[x-1] = 1;
	}
	dfs(0,-1);
	solve(0,-1);
	for(int i=0;i<res[0].size();i++){
		cout << res[0][i] << "\n";
	}
	for(int i=res[0].size();i<=m;i++) cout << "0\n";
}