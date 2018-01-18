#include <bits/stdc++.h>

using namespace std;
deque<int> a, x, y;

int main() {
	char ch;
	int n=0;
	while ((ch=getchar())!='\n') {
		a.push_front(ch-48);
		n++;
	}
	int m=0;
	while ((ch=getchar() != '\n')) m++;
	if (n<m) {
		for (int i=0; i<n; i++) {
			y.push_front(a[i]);
		}
		for (int i=n+1; i<m; i++) y.push_front(0);
		while (y[y.size()-1] == 0) y.pop_back();
		cout << "0.";
		for (int i=0; i<y.size();i++) cout << y[i];
		cout << endl;
	}
	else {
		for (int i=0; i<m-1; i++) {
			y.push_front(a[0]);
			a.pop_front();
		}
		while (y.size()>0 && y[y.size()-1] == 0) y.pop_back();
		for (int i=a.size()-1; i>=0 ;i--) cout << a[i];
		if (y.size() !=0) {
			cout << ".";
			for (int i=0; i<y.size(); i++) cout << y[i];
			cout << endl;
		}
	}
}
