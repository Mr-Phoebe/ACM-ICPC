#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAX_N 100005
using namespace std;
typedef long long LL;
const int sib=100;
int N,M;
LL A[100005],B[1000],Bhead[1000],Bdif[1000];
void add(int a,int b,LL x,LL d)
{
    int i,j;
    int bl=a/sib,br=b/sib;
//  a=a%sib;
//  b=b%sib;
    LL res=0;
    for(i=a; i<bl*sib+sib&&i<=b; i++)
    {
        A[i]=A[i]+x+(i-a)*d;
        B[i/sib]+=x+(i-a)*d;
        res+=d;
    }
//   printf("%d %d res:%lld\n",a,i-1,res);
    //printf("res:%lld\n",res);
    for(j=bl+1; j<br; j++)
    {
        Bhead[j]=Bhead[j]+x+res;
        Bdif[j]=Bdif[j]+d;
        B[j]+=(x+res)*sib+sib*(sib-1)/2*d;
        //   printf("%d %d\n",x+res,sib);
        // printf("add B[%d] :%lld\n",j,(x+res)*sib+sib*(sib-1)/2*d);
        res+=sib*d;
        //  printf("Bhead[%d]=%d ",j,Bhead[j]);
        //  printf("Bdif[%d]=%d\n",j,Bdif[j]);
    }
    // printf("tail:%d %d res:%d\n",br*sib,b,res);
    if(bl!=br)
        for(i=br*sib; i<=b; i++)
        {
            B[i/sib]+=x+d*(i-a);
            A[i]+=x+d*(i-a);
            //  printf("add:A[%d]=%lld\n",i,A[i]);
        }
}
LL sum(int a,int b)
{
    int i,j;
    int bl=a/sib,br=b/sib;
    LL res=0;
    for(i=a; i<(bl+1)*sib&&i<=b; i++)
    {
        // printf("A[%d]=%lld ",i,A[i]);
        res+=A[i];
        //  printf("B:%lld\n",Bhead[bl]+(i%sib)*Bdif[bl]);
        res+=Bhead[bl]+(i%sib)*Bdif[bl];
    }
    for(i=bl+1; i<br; i++)
    {
        // printf("B[%d]:%lld\n",i,B[i]);
        res+=B[i];
    }
    // printf("l:%d r:%d\n",bl,br);
    if(br!=bl)
        for(i=br*sib; i<=b; i++)
        {
            res+=A[i];
            //   printf("A[%d]=%lld ",i,A[i]);
            res+=Bhead[br]+(i%sib)*Bdif[br];
            //  printf("B:%lld\n",Bhead[br]+(i%sib)*Bdif[br]);
        }
    return res;
}
int main()
{
    int i,j,k,T,l,r,flag,x,d;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&M);
        memset(B,0,sizeof(B));
        memset(Bhead,0,sizeof(Bhead));
        memset(Bdif,0,sizeof(Bdif));
        for(i=0; i<N; i++)
        {
            scanf("%lld",&A[i]);
            B[i/sib]+=A[i];
        }
        for(i=0; i<M; i++)
        {
            scanf("%d %d %d",&flag,&l,&r);
            if(flag==1)
            {
                scanf("%d %d",&x,&d);
                add(l-1,r-1,(LL)x,(LL)d);
                /* for(j=0;j<N/sib;j++){
                       printf("B[%d]=%lld ",j,B[j]);
                   }
                   printf("\n");*/
            }
            else if(flag==2)
            {
                /*for(j=0;j<N/sib;j++){
                    printf("B[%d]=%lld ",j,B[j]);
                }
                printf("\n");*/
                printf("%lld\n",sum(l-1,r-1));
            }
            //  printf("flag:%d\n",flag);
        }
    }
    return 0;
}
