#include <bits/stdc++.h>
using namespace std;

#define int long long
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	map<pair<int,int>,int> m;
	int res = 0;
	int n;
	cin >> n;
	int x,y;
	for(int i=0;i<n;i++){
		cin >> x >> y;
		m[{x,y}] += 1;
		res += m[{x-2018,y}];
		res += m[{x+2018,y}];
		res += m[{x,y-2018}];
		res += m[{x,y+2018}];
		res += m[{x-1118,y-1680}];
		res += m[{x+1118,y-1680}];
		res += m[{x-1118,y+1680}];
		res += m[{x+1118,y+1680}];
		res += m[{x-1680,y-1118}];
		res += m[{x+1680,y-1118}];
		res += m[{x-1680,y+1118}];
		res += m[{x+1680,y+1118}];
	}
	cout << res << endl;
	return 0;
}
