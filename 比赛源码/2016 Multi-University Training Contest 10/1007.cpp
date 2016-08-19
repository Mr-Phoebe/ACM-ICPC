#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7.5;
const int MAXN=21;
struct Matrix {
    int n,Data[MAXN][MAXN];
    Matrix(){}
};
Matrix operator*(Matrix a,Matrix b)
{
    Matrix c;
    c.n=a.n;
    memset(c.Data,0,sizeof(c.Data));
    for(int i=0;i<c.n;i++) {
        for(int j=0;j<c.n;j++) {
            for(int k=0;k<c.n;k++) {
                c.Data[i][j]+=(long long)a.Data[i][k]*b.Data[k][j]%MOD;
                c.Data[i][j]%=MOD;
            }
        }
    }
    return c;
}
Matrix pow_mod(Matrix a,int b)
{
    Matrix c;
    c.n=a.n;
    memset(c.Data,0,sizeof(c.Data));
    for(int i=0;i<c.n;i++)  c.Data[i][i]=1;
    while(b) {
        if(b&1)  c=c*a,b--;
        else  a=a*a,b>>=1;
    }
    return c;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--) {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        Matrix A;
        A.n=2*m+1;
        memset(A.Data,0,sizeof(A.Data));
        A.Data[0][0]=1;
        Matrix B;
        B.n=2*m+1;
        memset(B.Data,0,sizeof(B.Data));
        for(int i=0;i<2*m+1;i++) {
            if(i<m) {
                B.Data[i][0]=k*k-k;
                B.Data[i][i==m-1?2*m:i+1]=k;
            }
            else {
                B.Data[i][m]=k*k-k;
                if(i!=2*m)
                    B.Data[i][i+1]=k;
            }
        }
        Matrix C=A*pow_mod(B,n);
        int ans=0;
        for(int i=m;i<=2*m;i++) {
            ans+=C.Data[0][i];
            ans%=MOD;
        }
        printf("%d\n",ans);
    }
    return 0;
}
