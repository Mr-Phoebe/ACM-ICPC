#include <bits/stdc++.h>

using namespace std;

#define int long long

int d[2000001];

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	d[0] = 0;
	int cur = 0;
	int flag = 0;
	for(int i=1;i<=2*a[n-1];i++){
		if(cur < (n-1) && a[cur+1]==i) cur++;
		d[i] = 1 + d[i-a[cur]];
		for(int j=cur-1;j>=0;j--){
			if(d[i-a[j]] + 1 < d[i]){
				flag = 1;
				break;
			}
		}
		if(flag == 1) break;
	}
	if(flag == 1) cout << "non-canonical";
	else cout << "canonical";
	return 0;
}
