#include <iostream>  
#define N 222  

using namespace std;  

int father[N],num[N]; 

int Find(int u)  
{  
    if(father[u]!=u)  
        return father[u]=Find(father[u]);  
    else  
        return father[u];  
}  

void Merge(int a,int b)  
{  
    a=Find(a);  
    b=Find(b);  
    if(a!=b)  
    {  
        if(num[a]>num[b])  
        {  
            father[b]=a;  
            num[a]+=num[b];
            num[b]=0;
        }  
        else  
        {  
            father[a]=b;  
            num[b]+=num[a];
			num[a]=0;  
        }  
    }  
    return;  
}  
int main()  
{  
    int n;
//    freopen("data.txt","r",stdin);
    while(~scanf("%d",&n))  
    {  
        int i;  
        for(i=1;i<=n;i++) 
        {  
            father[i]=i;  
            num[i]=1; 
        }  
        i=1;
        while(i<=n)  
        {  
            int a;  
            while(scanf("%d",&a)&&a) 
				Merge(i,a); 
           	i++;
        }  
        int ans=0;  
        for(i=1;i<=n;i++)  
            if(num[i]!=0)  
                ans++;   
        printf("%d\n",ans); 
    }  
    return 0;  
}  