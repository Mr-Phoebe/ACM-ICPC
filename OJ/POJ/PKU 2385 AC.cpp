#include<iostream>
using namespace std;
int a[1005];
int d[1005][33];
int main()
{
    int t, w;
    cin>>t>>w;
    for(int i=1; i<=t; i++) cin>>a[i];
    if(a[1]==1) {d[1][0]=1; d[1][1]=0;}
    if(a[1]==2) {d[1][0]=0; d[1][1]=1;}
    for(int i=2; i<=t; i++) {
        for(int j=0; j<=w; j++) {
            if(j==0) {d[i][j]=d[i-1][j]+a[i]%2; continue;}
            d[i][j]=max(d[i-1][j],d[i-1][j-1]);
            if(j%2+1==a[i]) d[i][j]++;
        }
    }
    int m=d[t][0];
    for(int i=1; i<=w; i++) {
        if(d[t][i]>m) m=d[t][i];
    }
    cout<<m<<endl;
    return 0;
}