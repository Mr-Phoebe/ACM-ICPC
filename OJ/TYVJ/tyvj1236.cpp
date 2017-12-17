#include <stdio.h>
int main()
{
    int n;
    int i,j,iC;
    scanf("%d",&n);
    iC=0;
    for(i=3;i<=n;i++)
        for(j=0;j<20;j++)
            if( (i&(1<<j)) && (i&(1<<(j+1))) )
                iC++;
    printf("%d\n",iC);
    return 0;   
}