#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<ctype.h>
#include<algorithm>
#include<string>
#define PI acos(-1.0)
#define maxn 1000
#define INF 1<<25
using namespace std;
int main ()
{
    int n;
    char a[3005];
    int  b[3005]={0};
    int  c[3005];
    cin>>n;
    getchar();
    int j=1;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(a[i]!='.')
        {
            c[j]=i;
            j++;               //������c��¼���ֵķ�.��λ��
        }
    }


    for(int i=1; i<j-1; i++)   //���ҳ�R L��
    {
        if(a[c[i]]=='R'&&a[c[i+1]]=='L')
        {
            for(int ii=c[i];ii<=(c[i]+c[i+1])/2;ii++)
            {
                b[ii]=1; //xiang you
            }
            for(int ii=(c[i]+c[i+1])/2+1;ii<=c[i+1];ii++)
            {
                b[ii]=-1; //xiang zuo
            }
            if((c[i]+c[i+1])%2==0) b[(c[i]+c[i+1])/2]=0; //zhili
        }
    }

    int RR=n+1,LL=0;//ע��R��L�ĳ�ʼλ��
    //��¼R��L��λ��
    for(int i=1;i<=n;i++)
    {
        if(a[i]=='R'&&b[i]==0) {RR=i;break;}
    }

    for(int i=n;i>=1;i--)
    {
        if(a[i]=='L'&&b[i]==0) {LL=i;break;}
    }
    int ans=0;

    if(RR>LL)    //�жϹ�ϵ
    { for(int i=LL+1;i<RR;i++)
      if(b[i]==0) ans++;
      cout<<ans<<endl;
    }
    else
    {
        if((RR+LL)%2==0) cout<<n-(LL+1-RR)+1<<endl;
        else cout<<n-(LL+1-RR)<<endl;
    }


}
