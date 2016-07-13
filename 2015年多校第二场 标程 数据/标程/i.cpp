#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int n;
int main(){
//	freopen("data.in","r",stdin);
//	freopen("dataa.out","w",stdout);
	while (scanf("%d",&n)!=EOF){
		if (n>=15){
			printf("1 + 2\n"); printf("3 + 4\n"); printf("5 + 6\n"); printf("7 + 8\n"); printf("%d + 9\n",n+1);
			printf("%d / 10\n",n+2); printf("%d / 11\n",n+3); printf("%d / 12\n",n+4); printf("%d / 13\n",n+5);
			printf("%d * %d\n",n+6,n+7); printf("%d * %d\n",n+8,n+9); printf("%d * %d\n",n+10,n+11); printf("14 - 15\n");
			int now=n+13; for (int i=16;i<=n;i++){printf("%d * %d\n",i,now); now++;} printf("%d + %d\n",n+12,now); continue;
		}
		if (n>=12){
			printf("1 + 2\n");
			for (int i=1;i<=n*2-24;i++) printf("%d / %d\n",i*2+1,i*2+2); int num=n*4-46;
			int now=n+1+n*2-24;
			if (n!=12){
				printf("%d - %d\n",n+1,n+2); now++;
				for (int i=2;i<=n*2-24;i++){printf("%d - %d\n",now,n+1+i); now++;} 
			}
			int k1=now;
			printf("%d - %d\n",num+1,num+2); num+=3; now++;
			for (int i=num;i<=n;i++){printf("%d * %d\n",i,now); now++;}
			printf("%d + %d\n",k1,now); continue;
		}
		if (n>=10){
			printf("1 + 2\n");
			for (int i=1;i<=24-n*2;i++) printf("%d / %d\n",1+2*i,2+2*i);
			printf("%d + %d\n",n+1,n+2); int now=n+26-n*2;
			for (int i=2;i<=24-n*2;i++) {printf("%d + %d\n",n+1+i,now); now++;}
			if (n==10) continue;
			printf("7 - 8\n"); printf("17 * 9\n"); printf("18 * 10\n"); printf("19 * 11\n"); printf("20 + 16\n"); continue;
		}
		if (n==9){
			printf("1 + 2\n"); printf("3 + 10\n"); printf("4 / 5\n"); printf("6 / 7\n"); printf("8 / 9\n");
			printf("11 - 12\n"); printf("15 - 13\n"); printf("16 - 14\n"); continue;
		}
		if (n==8){
			printf("1 + 2\n"); printf("3 + 9\n"); printf("4 - 5\n"); printf("6 * 11\n"); printf("7 * 12\n");
			printf("8 * 13\n"); printf("10 + 14\n"); continue;
		}
		if (n==7){
			printf("1 * 2\n"); printf("3 / 4\n"); printf("5 + 6\n"); printf("8 - 9\n"); printf("11 / 10\n"); printf("12 * 7\n"); continue;
		}
		if (n<=3){printf("-1\n"); continue;}
		if (n==6){
			printf("1 * 2\n"); printf("7 - 3\n"); printf("8 - 4\n"); printf("9 - 5\n"); printf("10 + 6\n"); continue;
		}
		if (n==5){
			printf("1 / 2\n"); printf("6 / 3\n"); printf("4 - 7\n"); printf("5 * 8\n"); continue;
		}
		if (n==4){
			printf("1 * 2\n"); printf("3 + 5\n"); printf("4 + 6\n"); continue;
		}
	}
	return 0;
}
