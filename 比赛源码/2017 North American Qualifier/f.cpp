#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int fx[4] = {0,1,0,-1};
int fy[4] = {1,0,-1,0};
int a[100];
int changed_pos, changed_op;
int n;
int xi,yi;

int dfs(int pos, bool changed, int x, int y, int face) {
	if (pos == n && x==xi && y==yi && changed) return -1;
	if (pos > n) return 0;
	if (!changed) {
		for (int i=-1; i<2; i++) {
			if (i!=a[pos]) {
				if (i == 0) {
					changed_pos = pos; changed_op = i;
					if (dfs(pos+1, true, x+fx[face], y+fy[face], face) == -1) return -1;
				}
				else{
					changed_pos = pos; changed_op = i;
					int temp_face = (face + i + 4) % 4;
					if (dfs(pos+1, true, x, y, temp_face) == -1) return -1;
				}
			}
		}
	}
	if (a[pos] == 0) {
		if (dfs(pos+1, changed, x+fx[face], y+fy[face], face) == -1) return -1;
	}
	else{
		int temp_face = (face + a[pos] + 4) % 4;
		if (dfs(pos+1, changed, x, y, temp_face) == -1) return -1;
	}
	return 0;
}

int main() {
	scanf("%d %d", &xi, &yi);
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		string str;
		cin >> str;
		if (str == "Forward") a[i]=0;
		else if (str == "Right") a[i]=1;
		else if (str == "Left") a[i]=-1;
	}
	dfs(0, false, 0, 0, 0);
	printf("%d ", changed_pos+1);
	if (changed_op == -1) printf("Left\n");
	else if (changed_op == 0) printf("Forward\n");
	else if (changed_op == 1) printf("Right\n");
	return 0;
}
