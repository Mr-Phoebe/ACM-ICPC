#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	map<string, int> mp;
	vector<vector<pair<int,int> > > g1(9001), g2(9001);
	string s[n];
	for(int i=0;i<n;i++){
		cin >> s[i];
		mp[s[i]] = 1;
	}
	string s1[m],s2[m];
	int c[m];
	for(int i=0;i<m;i++){
		cin >> s1[i] >> s2[i] >> c[i];
		mp[s1[i]] = 1; mp[s2[i]] = 1;
	}
	mp["English"] = 1;
	int counter = 0;
	for(auto it = mp.begin();it!=mp.end();it++){
		it->second = counter++;
	}
	for(int i=0;i<m;i++){
		g1[mp[s1[i]]].push_back({mp[s2[i]],1});
		g1[mp[s2[i]]].push_back({mp[s1[i]],1});
	}
	vector<int> dist(counter+1, 987654321); 
	priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > Q; 
	dist[mp["English"]] = 0;
	Q.push(pair<int,int>(0,mp["English"]));

	while(!Q.empty()) {

		pair<int,int> top = Q.top();
		Q.pop();
					
		int v = top.second, d = top.first;

		if(d <= dist[v]) {
			  for(auto it = g1[v].begin();it!=g1[v].end();it++){
					int v2 = it->first, cost = it->second;
					if(dist[v2] > dist[v] + cost) {
						  dist[v2] = dist[v] + cost;
						  Q.push(pair<int,int>(dist[v2], v2));

					}
			  }
		}
	}
	int indeg[9001];
	memset(indeg, 0, sizeof(indeg));
	int result[9001];
	result[mp["English"]] = 0;
	for(int i=0;i<=counter  + 5;i++) result[i] = 1e15;
	for(int i=0;i<m;i++){
		if(dist[mp[s1[i]]] + 1 <= dist[mp[s2[i]]]){
		//	cout << mp[s1[i]] << " " << mp[s2[i]] << " " << c[i] << endl;
			result[mp[s2[i]]] = min(result[mp[s2[i]]], c[i]);
		}
		if(dist[mp[s2[i]]] + 1 <= dist[mp[s1[i]]]){
		//	cout << mp[s1[i]] << " " << mp[s2[i]] << " " << c[i] << endl;
			result[mp[s1[i]]] = min(result[mp[s1[i]]], c[i]);
		}
	}
	int res = 0;
	for(int i=0;i<n;i++){
		if(result[mp[s[i]]] == 1e15){
			cout << "Impossible\n";
			return 0;
		}
		res += result[mp[s[i]]];
	}
	//for(auto it = ss.begin();it!=ss.end();it++) res += it->second.second;
	cout << res;
	return 0;
}

