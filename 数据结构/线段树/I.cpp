#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define STOP puts("Stop here~");
#define FF(i,n) for(int i=0; i<(n); ++i)
#define FOR(i,s,t) for(int i=(s); i<(t); ++i)
#define mid ((left+right)>>1)
#define lson rt<<1, left, m
#define rson rt<<1|1, m+1, right
const int MAXN = 100000;

int col[MAXN],arr[MAXN<<1];
int A[MAXN],B[MAXN];
char C[MAXN];
int vis[MAXN];


void update(int rt,int left,int right,int l,int r,int data)
{
    if(l<=left && right<=r)
    {
        col[rt] = data;
        return;
    }
    if(col[rt] == data) return;
    if(col[rt] != -1)
    {
        col[rt<<1] = col[rt<<1|1] = col[rt];
        col[rt] = -1;
    }
    int m = mid;
    if(l <= m) update(lson,l,r,data);
    if(r > m) update(rson,l,r,data);
}
void query(int rt,int left,int right)
{
    if(col[rt] >= 0)
    {
        FOR(i,left,right+1) vis[i]=col[rt];
        return;
    }
    if(left!=right && col[rt]==-1)
    {
        int m = mid;
        query(lson);
        query(rson);
    }
}

int binary(int left,int right,int x)
{
    while(left < right)
    {
        int m = (left+right)>>1;
        if(arr[m] >= x) right=m;
        else left=m+1;
    }
    return left;
}
int main()
{
    int n;
    char ch[3];
    while(~scanf("%d",&n))
    {
        int kk=0;
        arr[kk++] = 0;
        arr[kk++] = 1e9;
        FF(i,n)
        {
            scanf("%d%d%s",&A[i],&B[i],ch);
            C[i] = ch[0];
            arr[kk++]=A[i];
            arr[kk++]=B[i];
        }
        sort(arr,arr+kk);
        int end = kk;
        kk = 1;
        FOR(i,1,end)
        {
            if(arr[i]!=arr[i-1])arr[kk++]=arr[i];
        }
        end = kk;
        FOR(i,1,end)
        {
            if(arr[i]>arr[i-1]+1) arr[kk++]=arr[i-1]+1;
        }

        sort(arr,arr+kk);

        memset(col,-1,sizeof(col));
        col[1] = 0;
        cout<<kk<<endl;
        FF(i,n)
        {
            int a=binary(0,kk,A[i]);
            int b=binary(0,kk,B[i]);
            if(C[i]=='b')
            {
                update(1,1,kk-1,a+1,b,1);

            }
            else
            {
                update(1,1,kk-1,a+1,b,0);
            }
        }

        int i=1,maxx=-1,ans_x=0,ans_y=kk-1;

        query(1,1,kk-1);
        memcpy(col,vis,sizeof(vis));
//        for(int i=0; i<kk; i++)
//            cout<<col[i]<<" ";
//        cout<<endl;
        while(i<kk)
        {
            if(col[i]==0)
            {
                int j = i+1;
                while(col[j]==0 && j<kk)++j;
                --j;
                int ll=arr[j]-arr[i-1];
                if(ll > maxx)
                {
                    maxx=ll;
                    ans_x=i-1;
                    ans_y=j;
                }
                i = j;
            }
            ++i;
        }
        printf("%d %d\n",arr[ans_x], arr[ans_y]);
    }
    return 0;
}
