#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
pair <int, int> a[2005];
int a1[2005],a2[2005],a3[2005];
int main()
{
    //freopen("i.txt","r",stdin);
    int n;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a,a+n);
    for (int i=0; i<n; i++)
        a1[i]=a2[i]=a3[i]=a[i].second;
    int f=0;
    for (int i=0; i<n; i++)
    {
        if (a[i].first==a[i+1].first)
        {
            if (f==0) swap(a2[i],a2[i+1]);
            if (f==1) swap(a3[i],a3[i+1]);
            f++;
        }
        if (f==2) break;
    }

    if (f<2)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    for (int i=0; i<n; i++) cout<<a1[i]+1<<" ";
    cout<<endl;
    for (int i=0; i<n; i++) cout<<a2[i]+1<<" ";
    cout<<endl;
    for (int i=0; i<n; i++) cout<<a3[i]+1<<" ";
    cout<<endl;
    return 0;
}
