#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int a[100];
int u[100];
int n;

void cipher() {
	memset(u, 0, sizeof(u));
	u[0] = a[0];
	for (int i=1; i<n; i++) {
		u[i] = (u[i-1] + a[i]) % 27;
	}
	for (int i=0; i<n; i++) {
		if (u[i] == 0) cout << " ";
		else {
			char ch = u[i] + 96;
			cout << ch;
		}
	}
	cout << endl;
}

void decipher() {
	for (int i=1; i<n; i++)
		while (a[i] < a[i-1]) a[i] += 27;
	for (int i=n-1; i>0; i--) a[i] = a[i] - a[i-1];
	for (int i=0; i<n; i++) {
		if (a[i] == 0) cout << " ";
		else {
			char ch = a[i] + 96;
			cout << ch;
		}
	}
	cout << endl;
}

int main () {
	int t;
	scanf("%d", &t);
	getchar();
	while (t--) {
		char op=getchar();
		getchar();
		char ch;
		n=0;
		while ((ch=getchar()) != '\n') {
			if (ch == ' ') a[n++] = 0;
			else a[n++] = ch - 96;
		}
		if (op == 'e') cipher();
		else if (op == 'd') decipher();
	}
}
