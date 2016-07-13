#include<stdio.h>
#include<string.h>

	char a[2001],b[2001];
	int c[2001][2001];

int lcs_len( char *a, char *b, int c[][2001] )
{
    int m = strlen( a ),n = strlen( b ),i,j;
    
    for( i = 0; i <= m; i++ )
		c[ i ][ 0 ] = 0;/*j==0表示b串长度为0，无论a串多长，两者的公共子序列长度为0*/
    for( j = 1; j <= n; j++ )
		c[ 0 ][ j ] = 0;/*根据上一个类推*/
    for( i = 1; i <= m; i++ )/*开始递推*/
        for( j = 1; j <= n; j++ )/*若两序列的最后一个字符相同，那么公共子序列长度为去掉这最后一个字符后新生成的两个串的公共子序列长度+1*/
            if( a[ i - 1 ] == b[ j - 1 ])
                 c[ i ][ j ] = c[ i - 1 ][ j - 1 ] + 1;
            else if( c[ i - 1 ][ j ] >= c[ i ][ j -1 ] )
                     c[ i ][ j ] = c[ i - 1 ][ j ]; /*若两序列最后一个字符不同，那么他们最大子序列的长度为c[ i - 1][j]和c[i][j-1]中较大的一个*/
                 else 
                    c[ i ][ j ] = c[ i ][ j -1 ];
                

    return c[ m ][ n ];/*结果：a与b的最大子序列长度存在c[m][n]中*/
}



/*测试程序*/
int	 main()
{

    scanf("%s%s",a,b);
    printf("%d\n",lcs_len(a,b,c));
    return 0;
}

