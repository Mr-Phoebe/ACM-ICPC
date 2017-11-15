#include <bits/stdc++.h>
#define int long long

using namespace std;

class pt{
public:
	int x,y;
	pt(int _x, int _y): x(_x), y(_y) {};
	pt operator - (const pt &p) {return pt(x-p.x, y-p.y);}
};

int cross(const pt &x, const pt &y){
	return (x.x*y.y - x.y*y.x);
}

int n;
vector<pt> points;

bool check(pt line_vector, pt o){
	vector<pt> remain;
	remain.clear();
	for (int i=0; i<n; i++) {
		if (cross(line_vector, points[i]-o)!=0) remain.push_back(points[i]);
	}
	if (remain.size() > 2){
		pt l1=remain[0];
		pt l2=remain[1];
		for (int i=2; i<remain.size(); i++){
			if (cross(l2-l1, remain[i]-l1) != 0){
				return false;
			}
		}
	}
	return true;
}

signed main() {
	cin >> n;
	if (n<=3) {
		cout << "success" << endl;
		return 0;
	}
	for (int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		points.push_back(pt(x,y));
	}
	pt o1 = points[0];
	pt o2 = points[1];
	pt o3 = points[2];
	if (cross(o2-o1, o3-o1) == 0) {
		if (check(o2-o1, o1)) cout << "success" << endl;
		else cout << "failure" << endl;
	}
	else{
		if (check(o2-o1, o1) || check(o3-o2, o2) || check(o1-o3, o3)) cout << "success" << endl;
		else cout << "failure" << endl;
	}
}

