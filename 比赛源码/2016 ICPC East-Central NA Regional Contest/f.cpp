#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	while(n != 0){
		int a[2*n+1];
		for(int i=0;i<n;i++) cin >> a[i];
		for(int i=n;i<2*n;i++) a[i] = a[i-n];
		int N = 2*n;
		int d[N + 2][N+2];
		for(int i=0;i<N-2;i++){
			d[i][i+2] = __gcd(a[i],a[i+2]);
		}
		for(int i=0;i<N-1;i++) d[i][i+1] = 0;
		for(int i=3;i<n;i++){
			for(int j=0;j<N-i;j++){
				d[j][i+j] = 1e9;
				for(int k=j+1;k<i+j;k++){
					d[j][i+j] = min(d[j][j+i], d[j][k] + d[k][i+j] + __gcd(a[j], a[i+j]));
				}
			}
		}
		int result = 1e9;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				//cout << i << " " << j << " " << d[i][j] + d[j][n+i] + __gcd(a[i], a[j]) << endl;
				result = min(result, d[i][j] + d[j][n+i] + __gcd(a[i], a[j]));
			}
		}
		cout << result << endl;
		cin >> n;
	}
	return 0;
}
