#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,k,t1,t2;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> t1 >> t2;
	int m[n];
	for(int i=0;i<n;i++) cin >> m[i];
	int b[k],e[k];
	for(int i=0;i<k;i++) cin >> b[i] >> e[i];
	vector<pair<int,int> > v;
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			v.push_back({b[j] - m[i], e[j] - m[i]});
		}
	}
	sort(v.begin(),v.end());
	int cur = t1;
	int res = 0;
	for(int i=0;i<v.size();i++){
		if(v[i].first > t2) v[i].first = t2;
		if(v[i].first < t1) v[i].first = t1;
		if(v[i].second < t1) continue;		
		if(v[i].first > cur){
			res += v[i].first - cur;	
		}
		cur = max(cur, v[i].second);
	}
	if(cur < t2) res += t2 - cur;
	double result = (0.0 + res)/(0.0 + t2 - t1);
	cout << fixed << setprecision(10) << result << endl;
	return 0;
}
