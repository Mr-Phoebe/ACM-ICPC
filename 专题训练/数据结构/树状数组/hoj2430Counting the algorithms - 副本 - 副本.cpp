#include<iostream>  
#include<cstring> 
#include<cstdlib>
#define maxn 200020   
using namespace std;  


int f[maxn],s[maxn],a[maxn];  
long long c[maxn];  
int n;  

int lowbit(int x)  
{  
    return x&(-x);  
}  
void updata(int pos,int x)  
{  
    for(int i=pos;i<=2*n;i+=lowbit(i))  
        c[i]+=x; 
}  
int getsum(int pos)  
{  
    int sum=0;  
    for(int i=pos;i>0;i-=lowbit(i))  
        sum+=c[i];
    return sum;  
}  
int main()  
{  
	long long ans=0;
	freopen("data - ¸±±¾.txt","r",stdin);
	freopen("ans.txt","w",stdout);
    while(cin>>n)  
    {  
    	ans=0;
        memset(f,0,2*n+1);  
        memset(s,0,2*n+1);
        for(int i=1;i<=2*n;i++)  
        {  
            cin>>a[i];  
            f[a[i]]==0?f[a[i]]=i:s[a[i]]=i;  
            updata(i,1);
        }  
         
        for(int i=1;i<=2*n;i++)  
        if(getsum(i)-getsum(i-1)>0)  
        {  
            ans=ans+getsum(s[a[i]])-getsum(i-1)-1;  
            updata(i,-1);  
            updata(s[a[i]],-1);  
        }  
        cout<<ans<<endl;  
    }  
    return 0;  
}  