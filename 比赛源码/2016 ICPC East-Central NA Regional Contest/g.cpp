#include <bits/stdc++.h>

using namespace std;
#define int long long
#define inf 1e18

vector<int> v[3];

int get(int a, int b, int c, int i, int j, int k, int n){
	if(n == 0) return 0;
	if(i==v[a].size() || v[a][i] != n){
		if(k < v[c].size() && v[c][k] == n)
			return get(b,a,c,j,i,k+1, n-1);
		return -inf;
	}
	int res = get(a, c, b, i+1, k, j, n-1);
	if(res != -inf) return (1LL<<(n-1)) + res;
	return -inf;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int x;
	int m = 0;
	for(int j=0;j<3;j++){
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> x;
			m = max(m,x);
			v[j].push_back(x);
		}
	}
	int res = get(0,1,2,0,0,0,m);
	if(res >= 0) cout << res << endl;
	else cout << "No";
	return 0;
}
