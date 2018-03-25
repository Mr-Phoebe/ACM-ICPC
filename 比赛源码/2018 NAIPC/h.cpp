#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007


signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string a,b;
	cin >> a >> b;
	int n = a.length();
	int m = b.length();
	int g[n][m];
	int s1 = 0, s2 = 0;
	for(int i=0;i<n;i++){
		s1 += a[i]-'0';
	}
	for(int j=0;j<m;j++){
		s2 += b[j]-'0';
	}
	if((s1&1) != (s2&1)){
		cout << "-1";
		return 0;
	}
	s1 = s1&1;
	s2 = s2&1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			g[i][j] = 0;
	}
	int r = -1, c = -1;
	if(s1 == 1){
		for(int i=0;i<n;i++){
			if(a[i] == '1'){
				r = i;
				break;
			}
		}
		for(int i=0;i<m;i++){
			if(b[i] == '1'){
				c = i;
				break;
			}
		}
	}
	else{
		for(int i=0;i<n;i++){
			if(a[i] == '0'){
				r = i;
				break;
			}
		}
		for(int i=0;i<m;i++){
			if(b[i] == '0'){
				c = i;
				break;
			}
		}
		if(r == -1 && c == -1){
			for(int i=1;i<n;i++) g[i][0] = 1;
			for(int j=1;j<m;j++) g[0][j] = 1;
		}
		else if(r == -1){
			r = 0;
			for(int j=0;j<m;j++){
				if(b[j] == '0') c = j;
			}
		}
		else if(c == -1){
			c = 0;
			for(int j=0;j<n;j++){
				if(a[j] == '0') r = j;
			}
		}
	}

	if(r != -1 && c != -1){
		for(int i=0;i<m;i++){
			g[r][i] = b[i]-'0';
		}
		for(int i=0;i<n;i++){
			g[i][c] = max(g[i][c], a[i]-'0');
		}
	}

	/*cout << "------------------\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout << g[i][j] ;
		}
		cout << "\n";
	}
	cout << "------------------\n";*/

	for(int i=0;i<n;i++){
		int sum = 0;
		for(int j=0;j<m;j++){
			sum += g[i][j];
		}
		sum = sum&1;
		assert(sum == (a[i]-'0'));
	}

	for(int i=0;i<m;i++){
		int sum = 0;
		for(int j=0;j<n;j++){
			sum += g[j][i];
		}
		sum = sum&1;
		assert(sum == (b[i]-'0'));
	}

	int change = 1;
	while(change != 0){
		change = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				for(int k=i+1;k<n;k++){
					for(int l=j+1;l<m;l++){
						if(g[i][j] + g[i][l] + g[k][j] + g[k][l] < 2){
							g[i][j] = 1 - g[i][j];
							g[i][l] = 1 - g[i][l];
							g[k][j] = 1 - g[k][j];
							g[k][l] = 1 - g[k][l];
							change = 1;
						}
						else if(g[i][j] + g[i][l] + g[k][j] + g[k][l] == 2 && g[i][j]==1){
							g[i][j] = 1 - g[i][j];
							g[i][l] = 1 - g[i][l];
							g[k][j] = 1 - g[k][j];
							g[k][l] = 1 - g[k][l];
							change = 1;
						}
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout << g[i][j] ;
		}
		cout << "\n";
	}
	return 0;
}