#include <iostream>
#include <cstdio>
#define max(a,b) ((a)>(b))?(a):(b)
#define min(a,b) ((a)>(b))?(b):(a)
#define rep(i,initial_n,end_n) for(int (i)=(initial_n);(i)<(end_n);i++)
#define repp(i,initial_n,end_n) for(int (i)=(initial_n);(i)<=(end_n);(i)++)
#define reep(i,initial_n,end_n) for((i)=(initial_n);(i)<(end_n);i++)
#define reepp(i,initial_n,end_n) for((i)=(initial_n);(i)<=(end_n);(i)++)
#define eps 1.0E-9
#define MAX_N

using namespace std;

typedef __int64 ll;
typedef unsigned __int64 ull;

int d[6] = { 12, 6, 4, 3, 2, 1 };
int cmp[6] = { 1, 2, 3, 4, 6, 12 };

int main() {
    int n;
//    freopen("data.txt","r",stdin);
    scanf("%d", &n);
    char a[13];
    while(n--) {
        int flag[6][12] = { { false } }, sum[6] = { 0 }, ans = 0;
        scanf("%s", a);
        rep(i, 0, 12) {
            if(a[i] == 'O'){
                rep(j, 0, 6) {
                    if(!flag[j][i%d[j]]) sum[j]++, flag[j][i%d[j]] = true;
                }
            }
        }
        rep(i, 0, 6) {
            if(sum[i] < d[i]) ans++, sum[i] = -1;
        }
        if(ans == 0) puts("0");
        else {
            printf("%d", ans);
            rep(i, 0, 6) {
                if(sum[i] == -1)
                    printf(" %dx%d", 12/d[i], d[i]);
            }
            puts("");
        }
    }
    return 0;
}
