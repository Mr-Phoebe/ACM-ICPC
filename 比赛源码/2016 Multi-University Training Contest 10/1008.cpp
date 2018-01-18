#include <bits/stdc++.h>
using namespace std;
/*
    0001
    0203
040506070809 2322
101112131415 2120
    1617
    1819
    2021
    2223
*/
int p[3][24]={
    1,3,1,3,0,0,1,3,4,4,0,0,1,3,4,4,1,3,1,3,1,3,1,3,
    0,0,0,0,1,1,1,1,1,1,3,3,3,3,3,3,4,4,4,4,3,3,1,1,
    3,3,1,1,3,1,0,0,1,3,3,1,0,0,1,3,1,1,3,3,4,4,4,4
};
int dist(int a,int b)
{
    int dx=p[0][a]-p[0][b];
    int dy=p[1][a]-p[1][b];
    int dz=p[2][a]-p[2][b];
    return dx*dx+dy*dy+dz*dz;
}
int cmp(vector<int>a,vector<int>b)
{
    for(int i=0;i<6;i++) {
        if(a[i]<b[i]) {
            return 1;
        }
        else if(a[i]>b[i]) {
            return 0;
        }
    }
    return 0;
}
long long gen()
{
    char s[15];
    vector<int>V;
    for(int i=0;i<8;i++) {
        if(scanf("%s",s)!=1)  exit(0);
        for(int j=0;s[j];j++) {
            if(s[j]!=' ') {
                V.push_back(s[j]-'0'-1);
            }
        }
    }
    vector<int>T[6];
    for(int i=0;i<24;i++) {
        T[V[i]].push_back(i);
    }
    vector<int>D[6];
    for(int i=0;i<6;i++) {
        for(int j=0;j<4;j++) {
            for(int k=j+1;k<4;k++) {
                D[i].push_back(dist(T[i][j],T[i][k]));
            }
        }
        sort(D[i].begin(),D[i].end());
    }
    sort(D,D+6,cmp);
    long long ans=0;
    for(int i=0;i<6;i++) {
        for(int j=0;j<6;j++) {
            ans=ans*131+D[i][j];
        }
    }
    return ans;
}
int main()
{
    while(1) {
        long long v1=gen();
        long long v2=gen();
        printf("%s\n",v1==v2?"yes":"no");
    }
    return 0;
}
