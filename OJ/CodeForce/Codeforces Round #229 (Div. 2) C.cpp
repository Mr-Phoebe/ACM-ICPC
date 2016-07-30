#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n,k,w;
string cmd;
int tang[110000],bian[11][110000];

int main()
{
    cin>>n>>k>>w;cin>>cmd;
    for(int i=0;i<n;i++) if(cmd[i]=='1') tang[i+1]=1;
    for(int i=0;i<k;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            bian[i][j]=bian[i][j-1];
            if(((j-i)%k==0)&&tang[j]!=1) bian[i][j]++;
            else if(((j-i)%k)&&tang[j]!=0) bian[i][j]++;
        }
    }

    while(w--)
    {
        int a,b,S;
        cin>>a>>b;
        S=(a-1)%k;
        printf("%d\n",bian[S][b]-bian[S][a-1]);
    }

    return 0;
}