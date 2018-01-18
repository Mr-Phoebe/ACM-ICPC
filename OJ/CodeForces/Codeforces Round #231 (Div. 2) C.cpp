#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 1100
typedef struct{
    char a[3];
}LNode;
LNode f[N][N];
void FF(int num,char a[3]);
void Print();
int i,j,flag;int n,m;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//    freopen("textout.txt", "w", stdout);
#endif
    while(scanf("%d %d",&n,&m)!=EOF){
        int num11=0,num10=0,num01=0,num00=0;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++){
                scanf("%s",f[i][j].a);
                if(f[i][j].a[0]=='1' && f[i][j].a[1]=='1') num11++;
                else if(f[i][j].a[0]=='1' && f[i][j].a[1]=='0') num10++;
                else if(f[i][j].a[0]=='0' && f[i][j].a[1]=='1') num01++;
                else num00++;

            }
        i=1;j=1;flag=1;
        FF(num11,"11");
        //FF(num10,i,j,flag,"10");
        //FF(num01,i,j,flag,"01");
        int ii,jj;num10=num10+num01;
        char aa[3]="10",bb[3]="01";
        ii=i;jj=j;
        while(num10--){
            if(num10==-1) break;
            if(ii==1 || f[ii-1][jj].a[0]=='0' ||(f[ii-1][jj].a[0]=='1' && f[ii-1][jj].a[1]=='1') )
                strcpy(f[ii][jj].a,aa);
            else strcpy(f[ii][jj].a,bb);
            if(flag==1){
                jj++;
                if(jj==(m+1)){ii++;jj=m;flag=2;}
            }
            else{
                jj--;
                if(jj==0){ii++;jj=1;flag=1;}
            }
        }
        i=ii;j=jj;
        FF(num00,"00");
        Print();
    }
    return 0;
}

void FF(int num,char a[3]){
    while(num--){
        strcpy(f[i][j].a,a);
        if(flag==1){
            j++;
            if(j==(m+1)){i++;j=m;flag=2;}
        }
        else{
            j--;
            if(j==0){i++;j=1;flag=1;}
        }
    }
}
void Print(){
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(j>1) printf(" ");
            printf("%s",f[i][j].a);
        }
        printf("\n");
    }
}