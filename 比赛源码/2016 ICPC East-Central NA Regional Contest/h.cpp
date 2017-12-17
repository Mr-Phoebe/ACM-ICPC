#include <bits/stdc++.h>

using namespace std;

#define int long long

int n,m;
char g[101][101];
int o1[4] = {1,-1,0,0};
int o2[4] = {0,0,1,-1};

bool check(int i , int j){
	if(i >= 0 && i < n && j >=0 && j < m) return true;
	return false;
}

void dfs(int x,int y, int p, int q, char c){
	int options = 0;
	for(int i=0;i<4;i++){
		int xx = x + o1[i];
		int yy = y + o2[i];
		if(check(xx,yy) && g[xx][yy]!='.') options++;
	}
	if(options == 2){
		for(int i=0;i<4;i++){
			int xx = x + o1[i];
			int yy = y + o2[i];
			if(check(xx,yy) && g[xx][yy]!='.'){
				if(g[xx][yy] == 'X'){
					g[xx][yy]= c;
					dfs(xx,yy,x,y,c);
				}
				else if(g[xx][yy] != c){
					g[xx][yy] = 'C';
					dfs(xx,yy,x,y,c);
				}
			}
		}
	}
	else{
		int xx = x + x - p;
		int yy = y + y - q;
		if(!check(xx,yy) || g[xx][yy] == c) return;
		g[xx][yy] = c;
		dfs(xx,yy,x,y,c);
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> g[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(g[i][j] == 'A') dfs(i,j,-1,-1,'A');
			if(g[i][j] == 'B') dfs(i,j,-1,-1,'B');
		}
	}

	int aa[n][m];
	int bb[n][m];

	int total = 0;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(g[i][j] == '.') total += 1;

	queue<pair<int,int> > q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			aa[i][j] = 0;
			bb[i][j] = 0;
		}
	}
	for(int i=0;i<n;i++){

	}
	for(int i=0;i<n;i++){
		int la = 0, lb = 0;
		for(int j=0;j<m;j++){
			if(g[i][j] == 'A' || g[i][j] == 'C'){
				int ct = 0;
				int dir = 0;
				if(check(i-1, j) && (g[i-1][j] == 'A' || g[i-1][j] == 'C')) dir = 1;
				while(g[i][j] == 'A' || g[i][j] == 'C'){
					aa[i][j] = 0;
					j++;
					ct++;
				}
				if(ct == 1) la = 1 - la;
				else{
					int dir2 = 0;
					if(check(i-1,j-1) && (g[i-1][j-1] == 'A' || g[i-1][j-1]=='C')) dir2 = 1;
					if(dir != dir2) la = 1 - la;
				}
			}
			aa[i][j] = la;
		}
		for(int j=0;j<m;j++){
			if(g[i][j] == 'B' || g[i][j] == 'C'){
				int ct = 0;
				int dir = 0;
				if(check(i-1, j) && (g[i-1][j] == 'B' || g[i-1][j] == 'C')) dir = 1;
				while(g[i][j] == 'B' || g[i][j] == 'C'){
					aa[i][j] = 0;
					j++;
					ct++;
				}
				if(ct == 1) lb = 1 - lb;
				else{
					int dir2 = 0;
					if(check(i-1,j-1) && (g[i-1][j-1] == 'B' || g[i-1][j-1]=='C')) dir2 = 1;
					if(dir != dir2) lb = 1 - lb;
				}
			}
			bb[i][j] = lb;
		}
	}
	int c1 = 0, c2 = 0, c3 = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(g[i][j] == '.'){
				if(aa[i][j] == 1 && bb[i][j] == 1) c3++;
				else if(aa[i][j] == 1) c1++;
				else if(bb[i][j] == 1) c2++;
			}
		}
	}
	cout << c1 << " " << c2 << " " << c3 << endl;
	return 0;
}