#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define maxlen 2000
using namespace std;
//#define LOCAL
long long k,maxw;
char str[maxlen];
long long w[30],sw[maxlen];
int main()
{
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif // LOCAL
    scanf("%s",str+1);
    scanf("%d",&k);
    for(long long i=0;i<26;i++)scanf("%d",&w[i]);
    long long len=strlen(str+1);long long sum=0;sw[0]=0;
    for(long long i=1;i<=len;i++){sum+=w[str[i]-'a']*i;sw[i]=sw[i-1]+w[str[i]-'a'];}
    maxw=w[0];
    for(long long i=1;i<26;i++)maxw=max(maxw,w[i]);
    //for(long long i=1;i<=len;i++){sw}
    //for(long long i=1;i<=len;i++)cout<<sw[i]<<' ';cout<<endl;
    //cout<<sum<<endl;
    //cout<<maxw<<endl;
    while(k--)
    {
        long long ans=0;
        for(long long s=0;s<=len;s++)
        {
            long long temp=sw[len]-sw[s]+(s+1)*maxw;
            if(ans==0)ans=temp;else ans=max(ans,temp);
        }
        len++;
        sum+=ans;
        //for(long long i=1;i<=)
    }
    printf("%d\n",sum);
    return 0;
}
