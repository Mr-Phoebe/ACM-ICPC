#include<stdio.h>  
#include<string.h>  
#include<queue>  
#include<math.h>  
using namespace std;  
int n;  
int bound;  
int book[20];  
bool ans;  
int Min(int a,int b){  
    return a>b?b:a;  
}  
  
int h(int * book){  
    int i;  
    int sum=0;  
    if(book[1]!=1)  
        sum=1;  
    for(i=1;i<n;i++)  
        if(book[i]+1!=book[i+1])  
            sum++;  
    return ceil((double)(sum)/3);
}  
  
void change(int *book,int p,int q,int r){  
    int c[20],i,j;  
    for(i=q+1;i<=r;i++)  
        c[i]=book[i];  
    for(i=q,j=r;i>=p,j>=p+r-q;i--,j--)  
        book[j]=book[i];  
    for(i=p,j=q+1;j<=r;i++,j++)           //通过双下标形式不易出错  
        book[i]=c[j];  
}  
  
int dfs(int dep,int *nu){  
    int i,j,k,p,next_bound;  
    int tmp[20];  
  
    int hv=h(nu);  
    if(hv+dep>bound)  
        return hv+dep;  
    if(hv==0){  
        ans=true;  
        return dep;  
    }  
  
    int new_bound=1e7;  
    for(i=1;i<=n;i++)  
        for(j=i+1;j<=n;j++)  
            for(k=i;k<j;k++){  
  
                for(p=1;p<=n;p++)    
                    tmp[p]= nu[p];    
                change(tmp,i,k,j);  
  
                next_bound = dfs(dep+1,tmp);  
                if(!ans)  
                    new_bound=Min(new_bound,next_bound);  
                else  
                    return next_bound;  
            }  
      
    return new_bound;  
}  
  
void IDA_STAR(){  
    bound=h(book);  
    while(bound<5 && !ans){  
        bound=dfs(0,book);  
    }  
    if(ans)  
        printf("%d\n",bound);  
    else  
        printf("5 or more\n");  
}  
int main(){  
    int i,j,T,t;  
    scanf("%d",&T);  
    for(t=1;t<=T;t++){  
        scanf("%d",&n);  
        for(i=1;i<=n;i++)  
            scanf("%d",&book[i]);  
        ans=false;  
        IDA_STAR();  
    }  
}  