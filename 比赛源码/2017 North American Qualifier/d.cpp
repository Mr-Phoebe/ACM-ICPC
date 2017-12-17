#include <bits/stdc++.h>

using namespace std;

int n;
int a[16][3];
double dp[50000][16];
double alpha;

double dist(int i, int j){
	return sqrt((a[i][1] - a[j][1])*(a[i][1] - a[j][1]) + (a[i][0] - a[j][0])*(a[i][0] - a[j][0]));
}

int main(){
	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d %d %d", &a[i][0],&a[i][1],&a[i][2]);
	a[0][0] = 0; a[0][1] = 0; a[0][2] = 0;
	scanf("%lf", &alpha);
	
	double l = 0, h = 1000000;
	for(int ii=0;ii<100;ii++){
		double vel = (l+h)/2;
		if(h - l < 1e-8) break;
		for(int j=0;j<50000;j++) for(int i=0;i<n;i++) dp[j][i] = 1e15;
		dp[0][0] = 0;
		for(int i=0;i<n;i++){
			dp[1<<i][i] = dist(0,i+1)/vel;
		}
		for(int i=1;i<(1<<(n));i++){
			for(int j=0;j<n;j++){
				if(i&(1<<(j))){
					for(int k=0;k<n;k++){
						if((i&(1<<k)) && (j!=k)){
							dp[i][j] = min(dp[i][j], dp[i^(1<<j)][k] + dist(j+1,k+1)/(vel*pow(alpha,__builtin_popcount(i^(1<<j)))));
						}	
					}
					if(dp[i][j] > a[j+1][2]) dp[i][j] = 1e15;
				}
			}	
		}
		double res = 1e15;
		for(int i=0;i<n;i++){
			res = min(res,dp[(1<<n)-1][i]);
		}
		if(res < 1e15) h = vel;
		else l = vel;
	}
	cout << fixed << setprecision(10) << l << endl;
}
