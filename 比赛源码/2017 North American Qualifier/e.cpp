#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
double v[1001];
vector<vector<int> > g(1001);
pair<int, double> dp[1001][2];

void solve(int x,int p){
	dp[x][1] = {0,0};
	dp[x][0] = {0,0};
	for(int i=0;i<g[x].size();i++){
		if(g[x][i] == p) continue;
		solve(g[x][i],x);
	}
	pair<int,double> total = make_pair(0,0.0);
	for(int i=0;i<g[x].size();i++){
		if(g[x][i] == p) continue;
		total.first += max(dp[g[x][i]][0],dp[g[x][i]][1]).first;
		total.second += max(dp[g[x][i]][0],dp[g[x][i]][1]).second;
	}
	for(int i=0;i<g[x].size();i++){
		if(g[x][i] == p) continue;
		pair<int, double> temp = make_pair(0,0.0);
		if(dp[g[x][i]][0] > dp[g[x][i]][1]){
			temp.first = total.first - dp[g[x][i]][0].first + dp[g[x][i]][1].first;
			temp.second = total.second - dp[g[x][i]][0].second + dp[g[x][i]][1].second;
		}
		else temp = total;
		temp.first += 1;
		temp.second += min(v[x],v[g[x][i]]);
		dp[x][0] = max(dp[x][0], temp);
	}
	dp[x][1] = total;
	return;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	map<string,int> m;
	string a[n],c[n];
	double b[n];
	
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i] >> c[i];
		m[a[i]] = 1;
	}
	int ct = 0;
	for(map<string, int>::iterator it = m.begin();it!=m.end();it++){
		it->second = ct++;
	}
	int root = -1;
	for(int i=0;i<n;i++){
		v[m[a[i]]] = b[i];
		if(c[i] == "CEO"){
			root = m[a[i]];
		}
		else{
			g[m[a[i]]].push_back(m[c[i]]);
			g[m[c[i]]].push_back(m[a[i]]);
		}
	}
	solve(root, -1);
	pair<int, double> res = max(dp[root][0], dp[root][1]);
	cout << res.first << " " << fixed << setprecision(10) << res.second/res.first << endl;
	return 0;
}
