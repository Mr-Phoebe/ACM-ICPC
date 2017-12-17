#include <bits/stdc++.h>

using namespace std;

int main(){
    string m, s;
    cin >> m;
    cin >> s;
    int i=0;
    int lenm = m.length();
    while (i <  lenm){
		char temp = m[i] - s[i] + 65;
		if (temp <65) temp = temp+26;
		m[i] = temp;
		s = s+temp;
		i++;
    }
    cout << m << endl;
}
