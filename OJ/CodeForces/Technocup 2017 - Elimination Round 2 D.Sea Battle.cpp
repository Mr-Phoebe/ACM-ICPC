#include <cstdio>  
#include <cstring>  
#include <algorithm>  
using namespace std;  
const int maxn = 2*1e5+10;  
char str[maxn];  
int ans[maxn];  
int main()  
{  
    int n,a,b,k;  
    while(scanf("%d%d%d%d",&n,&a,&b,&k)!=EOF)  
    {  
        scanf("%s",str+1);  
        int m=0,cnt=0;  
        for(int i=1;i<=n;++i)  
        {  
            if(str[i]=='0')  
            {  
                cnt++;  
                if(cnt==b)  
                {  
                    ans[m++]=i;  
                    cnt=0;  
                }  
            }  
            if(str[i]=='1')  
                cnt=0;  
        }  
        printf("%d\n",m+1-a);   
        printf("%d",ans[0]);   
        for(int i=1;i<=m-a;++i)  
            printf(" %d",ans[i]);   
        printf("\n");  
    }  
    return 0;   
}   