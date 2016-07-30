#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<map>
#define pi acos(-1.0)
#define eps 1e-8
#define ll long long
#define L 1000050
#define N 1050
#define mod 1000000007
#define M 99999999999

using namespace std;
map<string,int>Map;
int main(){
    ios::sync_with_stdio(false);
    ll c,r,n,m,k,up;
    cin>>n>>m>>k;
    up=n+m-2;
    if(up<k)printf("-1\n");
    else{
        if(n>m)swap(n,m);
        if(k<n){
            if((n/(k+1)*m)>(m/(k+1)*n))printf("%I64d\n",n/(k+1)*m);
            else printf("%I64d\n",m/(k+1)*n);
        }else if(k>=n&&k<m){
            printf("%I64d\n",m/(k+1)*n);
        }else if(k>=m){
            if((n/(k-(m-1)+1))>(m/(k-(n-1)+1)))printf("%I64d\n",n/(k-(m-1)+1));
            else printf("%I64d\n",m/(k-(n-1)+1));
        }
    }
    return 0;
} 