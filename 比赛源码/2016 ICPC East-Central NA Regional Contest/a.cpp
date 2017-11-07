#include <bits/stdc++.h>

#define pi 3.14159265;

using namespace std;
struct cup{
	double x, y, z, r, remain;
	double in_speed = 0;
	double remain_t = 1000001;
	bool finished = false;
	cup(double xi, double yi, double zi, double ri, double li):	x(xi),y(yi),z(zi),r(ri),remain(li){};
};

bool cmp(cup x, cup y){
	return x.z>y.z;
}

bool cmp1(cup x, cup y){
	return x.remain_t < y.remain_t;
}

int n;
vector<cup> a;

bool check_intersect(cup x, cup y){
	double l= sqrt((x.x-y.x)*(x.x-y.x) + (x.y-y.y) * (x.y-y.y));
	return (abs(x.r-y.r) < l && l < x.r+y.r);
}

int main(){
	cin >> n;
	for (int i=0; i<n; i++) {
		double x, y, z, r, l;
		cin >> x >> y >> z >> r >> l;
		a.push_back(cup(x,y,z,r,l));
	}
	sort(a.begin(), a.end(), cmp);
	a[0].in_speed = 100;
	a[0].remain_t = a[0].remain / a[0].in_speed;
	int count = 0;
	while (count < n){
		sort(a.begin(), a.end(), cmp1);
		int i;
		while (a[i].finished) i++;
		a[i].finished = true;
		a[i].remain_t = 0;
		sort(a.begin(), a.end(), cmp);
		for (i=1; i<n; i++) {
			for (int j=0; j<i; j++) {
				if (a[i].z>a[j].z && a[i].finished && check_intersect(a[i], a[j])){
					double l= sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x) + (a[i].y-a[j].y) * (a[i].y-a[j].y));
					double theta = acos( (a[i].r*a[i].r + l*l - a[j].r*a[j].r)/ 2.0/a[i].r/l )'
					double percent = theta / pi;
					a[j].in_speed += a[i].in_speed * percent;
				}
			}
		}
		for (int i=0; i<n; i++) {
			if (!a[i].finished) a[i].remain = 
					
	
	
