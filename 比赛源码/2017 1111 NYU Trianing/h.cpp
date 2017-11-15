#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	double x,y;
	int bad[n+1][3];
	for(int i=0;i<=n;i++) for(int j=0;j<3;j++) bad[i][j] = 0;
	for(int i=0;i<m;i++){
		cin >> x >> y;
		bad[(int)ceil(x)][(int)floor(y)] = 1;
	}
	int d[n+1][8];
	for(int i=0;i<=8;i++) d[0][i] = 0;
	d[0][7] = 1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<8;j++){
			int flag = 0;
			for(int k=0;k<3;k++){
				if(((j&(1<<k)) == 0) && bad[i][k]){
					d[i][j] = 0;
					flag = 1;
					break;
				}
			}
			if(flag) continue;
			d[i][j] = 0;
			for(int k=0;k<8;k++){
				if(d[i-1][k] == 0) continue;
				int f = 0;
				for(int l=0;l<3;l++){
					//cout << i << " " << j << " " << k << " " << l << " " << (int)(j&(1<<l)) << " " << (int)(k&(1<<l)) << endl;
					if(!(j&(1<<l)) && !(k&(1<<l))){
						f = 1;
						break;
					}
					if(bad[i][l] && !(k&(1<<l))){
						f = 1;
						break;
					}
				}
				if(f == 1) continue;
				int temp[3] = {0,0,0};
				for(int l=0;l<3;l++){
					temp[l] = bad[i][l];
					if((k&(1<<l))==0){
						temp[l] = 1;
					}
					if((j&(1<<l)) == 0) temp[l] = 1;
				}
				int lt = -2;
				int cur = 0;
				for(int l=0;l<3;l++){
					if(temp[l] == 0){
						if(lt == l-1) cur++;
						else cur = 1;
						lt = l;
					}
				}
				//cout << i << " " << j << " " << cur << endl;
				d[i][j] += d[i-1][k];
				if(cur == 3) d[i][j] += 2*d[i-1][k];
				if(cur == 2) d[i][j] += d[i-1][k];
				//cout << i << " " << j << " " << k << " " << d[i][j] << endl;
			}
		}
	}
	cout << d[n][7] << endl;
	return 0;
}
			
