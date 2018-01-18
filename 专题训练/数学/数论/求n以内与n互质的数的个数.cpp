//2107----求n以内与n互质的数的个数
#include<stdio.h>
#include<string.h>
#define N 60000
/*
本题我用的是容斥原理，找出n的各个素因子p1p2...pm，于是便是求{!p1&!p2&!p3...!pm}=n-...
*/
bool isPrime[N];
long prime[N];
long primeYinZi[N]; 
void producePrime(){
memset(isPrime, 1, sizeof(isPrime));
memset(prime,0,sizeof(prime));
    int num = 0, i, j;
    for(i = 2; i < N; ++i) {
        if(isPrime[i]) prime[num++] = i;
        for(j = 0; (j<num && i*prime[j]<N); ++j) {
            isPrime[i*prime[j]] = 0;
            if(!(i%prime[j])) break;
        }
    } 
}
int main(){
long n;
producePrime();
while (scanf("%d",&n)!=EOF,n!=0){
   long ans=n;
   memset(primeYinZi,0,sizeof(primeYinZi));
   long count=0;
   for (long i=0;i<n&&prime[i]<n;i++)//n=p1^e1*p2^e2*p3^e3...pm^em
    if (!(n%prime[i])){
     primeYinZi[count++]=prime[i];
     do
      n/=prime[i];
     while (!(n%prime[i]));//n/pi^ei
    }
   if (isPrime[n])
    ans=n-1;
   for (long j=0;j<count;j++)
    ans*=(1-1.0/primeYinZi[j]);
   printf("%ld\n",ans);
}
return 0;
}