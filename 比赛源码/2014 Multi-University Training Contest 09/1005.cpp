//By Lin
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>

#define X first
#define Y second
#define mp make_pair
#define sqr(x) ((x) * (x))
#define Rep(i, n) for(int i = 0; i<(n); i++)
#define foreach(it, n) for(__typeof(n.begin()) it = n.begin(); it != n.end(); it++)

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

#define esp 1e-8
#define N 100010

char str[100], ans[10010];
int len;

int getmatch(int l) {
	int p = 1;
	for (int r = l + 1; ; r++) {
		if (str[r] == '(') p++;
		else if (str[r] == ')') p--;
		if (p == 0) return r;
	}
}

string getStr(int &w) {
	string ret = "";
	while (islower(str[w]) or isupper(str[w]) or isdigit(str[w])) 
		ret += str[w++];
	return ret;
}

void getHtmltag(int &w, string &s1, string &s2) {
	string name = "", id = "", cla = "";
	name = getStr(w);
	while (str[w] == '#' || str[w] == '.') {
		if (str[w] == '#') id = getStr(++w);
		else {
			if (cla != "") cla += ' ';
			cla += getStr(++w);
		}
	}
	s1 = "<" + name;
	if (id != "")
		s1 += " id=\""+ id + "\"";
	if (cla != "")
		s1 += " class=\""+ cla + "\"";
	s1 += ">";
	s2 = "</" + name + ">";
}

string solve(int l, int r) {
	if (l > r) return "";
	if (str[l] == '(') {
		int k = getmatch(l);
		return solve(l + 1, k - 1) + solve(k + 1, r);
	}
	else {
		string s1, s2, s3, ret;
		getHtmltag(l, s1, s2);
		int k = 0;
		if (str[l] == '*') {
			l++;
			while (isdigit(str[l])) 
				k = k * 10 + str[l++] - '0';
		}
		else k = 1;
		s3 = solve(l + 1, r);
		ret = "";
		while (k--)
			ret += s1 + s3 + s2;
		return ret;
	}
}

int main() {
	int cas;
	scanf("%d", &cas);
	while (cas --) {
		scanf("%s", str);
		cout<<solve(0, strlen(str) - 1)<<endl;
	}
	return 0;
}
