#include <stdio.h>
#define MAX 1005

int n;
int num[MAX][MAX];

int main() {
    int q,k;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                    scanf("%d",&num[i][j]);

    k = num[1][1];
    for(int i = 2;i <= n;i++) k = k ^ num[i][i];

    scanf("%d",&q);
    while(q--) {
            int kind;
            scanf("%d",&kind);
            if (kind == 1 || kind == 2) {
                    int ans;
                    scanf("%d",&ans);
                    k = !k;
            } else printf("%d",k);
    }

    printf("\n");
    return 0;
}
