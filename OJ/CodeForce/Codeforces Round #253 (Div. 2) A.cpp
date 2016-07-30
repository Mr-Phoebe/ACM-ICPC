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

int main()
{
	int ch,ans=0;
	int a[30]={0};
	while((ch=getchar())!='\n') 
	{
		if(ch<='z'&&ch>='a')
			a[ch-'a']=1;
	}
	for(int i=0;i<30;i++)
		if(a[i])
			ans++;
	printf("%d\n",ans);
	return 0;
} 