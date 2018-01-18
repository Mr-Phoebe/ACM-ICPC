#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int acc[3000010] = {0};
int pos[3000010] = {0};
int res[3000010][2] = {{0}}; //round, index

int main()
{
    int total, k;
    int i = 0, j = 0, maxacc = 0;
	int T,Q,x;
	scanf("%d",&T);
    while (T--){
        scanf("%d %d %d", &total, &k,&Q);
        memset(acc, 0, sizeof(acc));
        maxacc = 0;

        res[0][0] = 1;
        res[0][1] = 0;
        acc[1] = 1;

        for ( i = 1; i<total; i++ ){
            if (i%k == 0){
                res[i][0] = 1;
                res[i][1] = i;
                acc[1]++;
            }else{
                j = i - (i/k+1);
                res[i][0] = res[j][0]+1;
                res[i][1] = res[j][1];
                acc[res[i][0]]++;
                if (res[i][0]>maxacc)
                    maxacc = res[i][0];
            }
        }

        for ( i = 1; i<=maxacc; i++){
            acc[i] += acc[i-1];
        }

        for ( i = 1; i<=total; i++){
            pos[acc[res[i-1][0]-1] + (res[i-1][1]/k+1)] = i;
        }
		for( i=1; i<=Q; i++){
			scanf("%d",&x);
			printf("%d\n",pos[x]);
		}
        //~ printf("%d", pos[1]);
        //~ for ( i = 2; i<=total; i++){
            //~ printf(" %d",pos[i]);
        //~ }
        //~ printf("\n");
    }
    return 0;
}
