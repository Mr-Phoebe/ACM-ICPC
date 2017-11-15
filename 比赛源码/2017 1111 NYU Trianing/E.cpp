#include <bits/stdc++.h>

using namespace std;
#define int long long
#define EPS 1e-8

class pt2{
public:
	double x,y;
	pt2(){};
	pt2(double _x, double _y) { x = _x; y = _y;}
	pt2 vec2(const pt2 &p){ return pt2(p.x - x, p.y - y); }
	double len(){ return sqrt(x*x + y*y); };
	double dist(const pt2 &p){
		double dx = x - p.x;
		double dy = y - p.y;
		return sqrt(dx*dx + dy *dy);
	}
	double cross(const pt2 &p) { return x*p.y - y*p.x;}
	pt2 operator + (const pt2 &p) {return pt2(x + p.x, y + p.y); }
	pt2 operator - (const pt2 &p) {return pt2(x - p.x, y - p.y); }
	double dot(const pt2 &p){ return x*p.x+y*p.y;}
};

vector<pt2> a,b;

double fdist(double alpha, pt2 a1, pt2 a2, pt2 b1, pt2 b2){
	double diffx1 = a1.x-b1.x;
	double diffx2 = a2.x-b2.x;
	double diffy1 = a1.y-b1.y;
	double diffy2 = a2.y-b2.y;
	return (1.0-alpha)*(1.0-alpha)*diffx1*diffx1 + 2.0*alpha*(1.0-alpha)*diffx1*diffx2 + alpha*alpha*diffx2*diffx2
	+(1.0-alpha)*(1.0-alpha)*diffy1*diffy1 + 2.0*alpha*(1.0-alpha)*diffy1*diffy2 + alpha*alpha*diffy2*diffy2;
}

double check_min(pt2 a_s, pt2 a_e, pt2 b_s, pt2 b_e){
	double l = 0, r = 1;
	for (int i=0; i<100; i++) {
		double mid = (l+r)/2.0;
		double mmid = (mid+r)/2.0;
		if (fdist(mid, a_s, a_e, b_s, b_e) < fdist(mmid, a_s, a_e, b_s, b_e)) r= mmid;
		else l=mid;
	}
	return sqrt(fdist(l, a_s, a_e, b_s, b_e));
}

signed main(){
	a.clear();
	b.clear();
	int n,m;
	cin >> n;
	for (int i=0; i<n; i++) {
		double x,y;
		cin >> x >> y;
		a.push_back(pt2(x,y));
	}
	cin >> m;
	for (int i=0; i<m; i++){
		double x,y;
		cin >> x >> y;
		b.push_back(pt2(x,y));
	}
	//cout << "-----" << endl;
	pt2 a1 = a[0];
	pt2 a2 = a[1];
	pt2 b1 = b[0];
	pt2 b2 = b[1];
	int i=1, j=1;
	double ans = 100000;
	if (a1.dist(b1) < ans) ans = a1.dist(b1);
	while (i<n && j<m){
		double la=a1.dist(a2);
		double lb=b1.dist(b2);
		if (la == lb) {
			double new_min = check_min(a1,a2,b1,b2);
			if (new_min < ans) {
				ans = new_min;
				/*cout << ans << endl;
				cout << a1.x << " " << a1.y << endl;
				cout << a2.x << " " << a2.y << endl;
				cout << b1.x << " " << b1.y << endl;
				cout << b2.x << " " << b2.y << endl;
				cout << "----" << endl; */
			}
			a1 = a2;
			a2 = a[++i];
			b1 = b2;
			b2 = b[++j];
			//cout << a1.x << " " << a1.y << endl;
			//cout << b1.x << " " << b1.y << endl;
		}
		else if (la < lb) {
			double ratio = la/lb;
			pt2 temp = pt2((1-ratio)*b1.x+ratio*b2.x, (1-ratio)*b1.y+ratio*b2.y);
			double new_min = check_min(a1,a2,b1,temp);
			if (new_min < ans) {
				ans = new_min;
				/*cout << ans << endl;
				
				cout << a1.x << " " << a1.y << endl;
				cout << a2.x << " " << a2.y << endl;
				cout << b1.x << " " << b1.y << endl;
				cout << temp.x << " " << temp.y << endl;
				cout << "----" << endl; */
			}
			a1 = a2;
			a2 = a[++i];
			b1 = temp;
			//cout << a1.x << " " << a1.y << endl;
			//cout << b1.x << " " << b1.y << endl;
		}
		else {
			double ratio = lb/la;
			pt2 temp = pt2((1-ratio)*a1.x+ratio*a2.x, (1-ratio)*a1.y+ratio*a2.y);
			double new_min = check_min(a1,temp,b1,b2);
			if (new_min < ans) {
				ans = new_min;
				/*cout << ans << endl;
				cout << a1.x << " " << a1.y << endl;
				cout << temp.x << " " << temp.y << endl;
				cout << b1.x << " " << b1.y << endl;
				cout << b2.x << " " << b2.y << endl;
				cout << "----" << endl; */
			}
			b1 = b2;
			b2 = b[++j];
			a1 = temp;
			//cout << a1.x << " " << a1.y << endl;
			//cout << b1.x << " " << b1.y << endl;
		}
	}
	printf("%.6lf\n", ans);
}
	
	
