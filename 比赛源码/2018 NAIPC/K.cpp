#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[100001][2];
int mm[100001];
pair<int,int> xmin[100001][20];
pair<int,int> xmax[100001][20];
pair<int,int> ymin[100001][20];
pair<int,int> ymax[100001][20];
int n,q;
pair<int, int> xb1, xb2, yb1, yb2, xs1, xs2, ys1, ys2;

pair<int, int> min(pair<int, int> x, pair<int, int> y){
	if (x.first < y.first) return x;
	if (x.first == y.first){
		if (a[x.second][1]==a[y.second][1] && a[x.second][2] < a[y.second][2]){
			return x;
		}
		if (a[x.second][2]==a[y.second][2] && a[x.second][1] < a[y.second][1]){
			return x;
		}
	}
	return y;
}

pair<int, int> max(pair<int, int> x, pair<int, int> y){
	if (x.first > y.first) return x;
	if (x.first == y.first){
		if (a[x.second][1]==a[y.second][1] && a[x.second][2] > a[y.second][2]){
			return x;
		}
		if (a[x.second][2]==a[y.second][2] && a[x.second][1] > a[y.second][1]){
			return x;
		}
	}
	return y;
}

pair<int, int> find_second_xmax(int l, int r, int pos){
	if (pos == l) {
		int k=mm[r-l];
		return max(xmax[pos+1][k], xmax[r-(1ll<<k)+1][k]);
	}
	if (pos == r){
		int k=mm[r-l];
		return max(xmax[l][k],xmax[pos-(1ll<<k)][k]);
	}
	int lp=pos-1, rp=pos+1;
	int k1=mm[lp-l+1], k2=mm[r-rp+1];
	pair<int, int> left_max = max(xmax[l][k1], xmax[lp-(1ll<<k1)+1][k1]);
	pair<int, int> right_max = max(xmax[rp][k2], xmax[r-(1ll<<k2)+1][k2]);
	return max(left_max, right_max);
}

pair<int, int> find_second_xmin(int l, int r, int pos){
	if (pos == l) {
		int k=mm[r-l];
		return min(xmin[pos+1][k], xmin[r-(1ll<<k)+1][k]);
	}
	if (pos == r){
		int k=mm[r-l];
		return min(xmin[l][k],xmin[pos-(1ll<<k)][k]);
	}
	int lp=pos-1, rp=pos+1;
	int k1=mm[lp-l+1], k2=mm[r-rp+1];
	pair<int, int> left_min = min(xmin[l][k1], xmin[lp-(1ll<<k1)+1][k1]);
	pair<int, int> right_min = min(xmin[rp][k2], xmin[r-(1ll<<k2)+1][k2]);
	return min(left_min, right_min);
}

pair<int, int> find_second_ymin(int l, int r, int pos){
	if (pos == l) {
		int k=mm[r-l];
		return min(ymin[pos+1][k], ymin[r-(1ll<<k)+1][k]);
	}
	if (pos == r){
		int k=mm[r-l];
		return min(ymin[l][k],ymin[pos-(1ll<<k)][k]);
	}
	int lp=pos-1, rp=pos+1;
	int k1=mm[lp-l+1], k2=mm[r-rp+1];
	pair<int, int> left_min = min(ymin[l][k1], ymin[lp-(1ll<<k1)+1][k1]);
	pair<int, int> right_min = min(ymin[rp][k2], ymin[r-(1ll<<k2)+1][k2]);
	return min(left_min, right_min);
}

pair<int, int> find_second_ymax(int l, int r, int pos){
	if (pos == l) {
		int k=mm[r-l];
		return max(ymax[pos+1][k], ymax[r-(1ll<<k)+1][k]);
	}
	if (pos == r){
		int k=mm[r-l];
		return max(ymax[l][k],ymax[pos-(1ll<<k)][k]);
	}
	int lp=pos-1, rp=pos+1;
	int k1=mm[lp-l+1], k2=mm[r-rp+1];
	pair<int, int> left_max = max(ymax[l][k1], ymax[lp-(1ll<<k1)+1][k1]);
	pair<int, int> right_max = max(ymax[rp][k2], ymax[r-(1ll<<k2)+1][k2]);
	return max(left_max, right_max);
}

int get_ans(){
	if(xb2.first-xs2.first > yb2.first-ys2.first)
			return xb2.first - xs2.first;
	else return yb2.first - ys2.first;
}

signed main(){
	cin >> n >> q;
	mm[0]=-1;
	for (int i=1; i<=n; i++){
		cin >> a[i][1] >> a[i][2];
		xmin[i][0]={a[i][1], i};
		xmax[i][0]={a[i][1], i};
		ymin[i][0]={a[i][2], i};
		ymax[i][0]={a[i][2], i};
		mm[i] = ((i&(i-1)) == 0)?mm[i-1]+1:mm[i-1];
	}
	for (int j=1; j<=mm[n]; j++){
		for (int i=1; i + (1<<j) -1 <= n; i++){
			xmin[i][j]=min(xmin[i][j-1], xmin[i+(1ll<<(j-1))][j-1]);
			xmax[i][j]=max(xmax[i][j-1], xmax[i+(1ll<<(j-1))][j-1]);
			ymin[i][j]=min(ymin[i][j-1], ymin[i+(1ll<<(j-1))][j-1]);
			ymax[i][j]=max(ymax[i][j-1], ymax[i+(1ll<<(j-1))][j-1]);
		}
	}
	while (q--){
		int l,r;
		cin >> l >> r;
		int k = mm[r-l+1];
		xb1=max(xmax[l][k], xmax[r-(1ll<<k)+1][k]);
		xs1=min(xmin[l][k], xmin[r-(1ll<<k)+1][k]);
		yb1=max(ymax[l][k], ymax[r-(1ll<<k)+1][k]);
		ys1=min(ymin[l][k], ymin[r-(1ll<<k)+1][k]);
		int xb1p=xb1.second, xs1p=xs1.second, yb1p=yb1.second, ys1p=ys1.second;
		int ans = 1e10;
		xb2 = find_second_xmax(l, r, xb1p);
		xs2 = find_second_xmin(l, r, xb1p);
		yb2 = find_second_ymax(l, r, xb1p);
		ys2 = find_second_ymin(l, r, xb1p);
		ans = min(ans, get_ans());
		xb2 = find_second_xmax(l, r, xs1p);
		xs2 = find_second_xmin(l, r, xs1p);
		yb2 = find_second_ymax(l, r, xs1p);
		ys2 = find_second_ymin(l, r, xs1p);
		ans = min(ans, get_ans());
		xb2 = find_second_xmax(l, r, yb1p);
		xs2 = find_second_xmin(l, r, yb1p);
		yb2 = find_second_ymax(l, r, yb1p);
		ys2 = find_second_ymin(l, r, yb1p);
		ans = min(ans, get_ans());
		xb2 = find_second_xmax(l, r, ys1p);
		xs2 = find_second_xmin(l, r, ys1p);
		yb2 = find_second_ymax(l, r, ys1p);
		ys2 = find_second_ymin(l, r, ys1p);
		ans = min(ans, get_ans());
		cout << ans << endl;
	}
}
