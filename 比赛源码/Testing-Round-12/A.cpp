#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long a,b,c;
    cin>>c>>a>>b;
    long long ans = 0;
    if(a<=0 && b<=0)
    {
        swap(a,b);
        a=-a,b=-b;
    }
    if(a<=0 && b>=0)
    {
        ans=(-a)/c+b/c;
        ans++;
    }
    else
    {
        ans=(b/c)-(a-1)/c;
    }
    cout<<ans<<endl;
    return 0;
}
