#include<bits/stdc++.h>
using namespace std;

int tc = 0;
int sol(){
  static int a[102400],b[102400],n; ++ tc;
  scanf("%d",&n);
  long long s=0;
  int mx=numeric_limits<int>::min(),
    mn=numeric_limits<int>::max();
  for(int i=0;i<n;++i){
    scanf("%d",a+i);
    s+=a[i];
    mx=max(mx,a[i]);
    mn=min(mx,a[i]);
  }
  int avg=s/n;
  if(s%n !=0 || mx > avg+2 || mn < avg-2)return puts("NO");
  if(avg==mx)return puts("YES\n0");
  a[n]=a[0];
  for(int s=-1;s<=1;++s){
    b[0]=s;
    bool ok=true;
    int cnt=0;
    for(int j=1;j<=n && ok;++j){
      b[j]=a[j]+b[j-1]-avg;
      ok = (abs(b[j]) <= 1);
      if(b[j]) ++ cnt;
    }
    if(ok &= (b[0]==b[n])){
      printf("YES\n%d\n",cnt);
      for(int j=0;j<n;++j)if(b[j]){
        int x=j-min(b[j],0),y=j+max(b[j],0);
        printf("%d %d\n",x%n+1,y%n+1);
      }
      return 0;
    }
  }
  //fprintf(stderr, "cas: %d\n", tc);
  /*fprintf(stderr, "%d\n", n);
  for (int i = 0; i < n; ++ i) fprintf(stderr, "%d ", a[i]);
  fprintf(stderr, "\n");*/
  return puts("NO");
}
int main(){
  int T; tc = 0;
  for(scanf("%d",&T);T--;sol());
}