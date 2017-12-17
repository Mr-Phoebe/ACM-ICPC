#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n1, n2, m1, m2;
	cin >> n1 >> n2 >> m1 >> m2;
	set<int> s1[n1];
	set<int> s2[n2];
	vector<vector<int> > g1(n1);
	vector<vector<int> > g2(n2);
	int ind1[n1],ind2[n2];
	for(int i=0;i<n1;i++){
		ind1[i] = 0;
		g1[i].clear();
		s1[i].clear();
	}
	for(int i=0;i<n2;i++){
		g2[i].clear();
		s2[i].clear();
		ind2[i] = 0;
	}
	int x,y;
	for(int i=0;i<m1;i++){
		cin >> x >> y;
		x--; y--;
		g1[x].push_back(y);
		ind1[y]++;
	}
	for(int i=0;i<m2;i++){
		cin >> x >>y;
		x--; y--;
		//cout << x << " " << y << endl;
		g2[x].push_back(y);
		ind2[y]++;
	}
	s1[0].insert(0);
	s2[0].insert(0);
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int f = q.front();
		q.pop();
		for(int i=0;i<g1[f].size();i++){
			x = g1[f][i];
			ind1[x]--;
			for(auto it = s1[f].begin();it!=s1[f].end();it++){
				s1[x].insert(*it + 1);
			}
			if(ind1[x] == 0){
				q.push(x);
			}
		}
	}
	q.push(0);
	while(!q.empty()){
		int f = q.front();
		q.pop();
		for(int i=0;i<g2[f].size();i++){
			x = g2[f][i];
			//cout << f << " " << x << " " << g2[f].size() << endl;
			ind2[x]--;
			for(auto it = s2[f].begin();it!=s2[f].end();it++){
				s2[x].insert(*it + 1);
			}
			if(ind2[x] == 0){
				q.push(x);
			}
		}
	}
	int res[4004];
	for(int i=0;i<4004;i++) res[i] = 0;
	for(auto it = s1[n1-1].begin();it!=s1[n1-1].end();it++){
		for(auto jt = s2[n2-1].begin();jt!=s2[n2-1].end();jt++){
			res[*it + *jt] = 1;
		}
	}
	int qq;
	cin >> qq;
	for(int i=0;i<qq;i++){
		cin >> x;
		if(res[x] == 0){
			cout << "No\n";
		}
		else cout << "Yes\n";
	}
	return 0;
}