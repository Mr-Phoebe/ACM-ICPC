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

int sum,lim;

int low_bit(int x)
{
    return x&(-x);
}

int main()
{
    int i,now;
    vector <int> ans;
    cin>>sum>>lim;
    for (i=lim;i>=1;i--)
    {
        now=low_bit(i);
        if (sum>=now)
        {
            ans.push_back(i);
            sum-=now;
        }
    }
    if (sum==0)
    {
        int len;
        len=ans.size();
        cout<<len<<endl;
        for (i=0;i<len;i++)
			cout<<ans[i]<<" "; cout<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
    return 0;
}