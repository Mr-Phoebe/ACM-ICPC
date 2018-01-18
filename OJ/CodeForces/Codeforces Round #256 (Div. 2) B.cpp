#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int n,i,j,l1,l2,a[26],b[26];
char s[101],t[101];

int main()
{
    scanf("%s",s);
    scanf("%s",t);
    l1=strlen(s);
    l2=strlen(t);
    for(i=0;i<l1;i++)
		a[s[i]-'a']++;
    for(i=0;i<l2;i++)
		b[t[i]-'a']++;
    for(i=0;i<26;i++)
		if(a[i]<b[i])
			break;
    if(i<26)
        printf("need tree\n");
    else
	{
        for(i=j=0;i<l2&&j<l1;i++,j++)
			while(j<l1&&s[j]!=t[i])
				j++;
        printf("%s\n",i<l2?(l1==l2?"array":"both"):"automaton");
    }
    return 0;
}