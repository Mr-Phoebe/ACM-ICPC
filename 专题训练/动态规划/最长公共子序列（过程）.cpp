# include <stdio.h>
# include <string.h>
# include <stdlib.h>

#define N 100/*字符串的最大长度限制*/

char a[ N ],/*第一个字符串*/
     b[ N ],/*第二个字符串*/
     str[ N ];/*用于存放a 与 b的公共子序列*/

/*计算两个序列的最长公共子序列的长度*/
int lcs_len( char *a, char *b, int c[][ N ] ){
    int m = strlen( a ),/*计算两个序列的长度*/
        n = strlen( b ),
        i,/*行指针*/
            j;/*列指针*/
    
    for( i = 0; i <= m; i++ ) c[ i ][ 0 ] = 0;/*j==0表示b串长度为0，无论a串多长，两者的公共子序列长度为0*/
    for( j = 1; j <= n; j++ ) c[ 0 ][ j ] = 0;/*根据上一个类推*/
    for( i = 1; i <= m; i++ )/*开始递推*/
        for( j = 1; j <= n; j++ )/*若两序列的最后一个字符相同，那么公共子序列长度为去掉这最后一个字符后新生成的两个串的公共子序列长度+1*/
            if( a[ i - 1 ] == b[ j - 1 ])
                { c[ i ][ j ] = c[ i - 1 ][ j - 1 ] + 1;
//                  printf("\nc[ %d ][ %d ] = c[ %d - 1 ][ %d - 1 ] + 1\n", i, j, i, j );
				}/**/
            else if( c[ i - 1 ][ j ] >= c[ i ][ j -1 ] )
                    { c[ i ][ j ] = c[ i - 1 ][ j ];
                //      printf("\nc[ %d ][ %d ] = c[ %d - 1 ][ %d ]\n", i, j, i, j );
                    }/*若两序列最后一个字符不同，那么他们最大子序列的长度为c[ i - 1][j]和c[i][j-1]中较大的一个*/
                 else 
                    {c[ i ][ j ] = c[ i ][ j -1 ];
              //   printf("\nc[ %d ][ %d ] = c[ %d ][ %d - 1]\n", i, j, i, j);
                }
    /*调试：将生成的数组方阵显示出来,m行，n列*/
 //   printf("\n");
 //   printf("  ");
 //   for( j = 0; j <= n; j++ )printf("%d, ", j );/*显示列标号*/
//    printf("\n");
//    for( i = 0; i <= m; i++ )
 //       {
 //        printf("%d: ", i );/*显示行标号*/
//            for( j = 0; j <= n; j++ )
 //           printf("%d, ", c[ i ][ j ] );
//             printf("\n");/*一行显示完，换下一行*/

//        }

    return c[ m ][ n ];/*结果：a与b的最大子序列长度存在c[m][n]中*/
}

/*构造最长子序列函数*/
char *build_lcs( char s[], char *a, char *b ){/*根据lcs_len(）函数计算的结果，倒推出最长子序列，结果放在s[]中*/
    int k,/*a与b最长子序列的长度*/
        i = strlen( a ),/*a串长度*/
        j = strlen( b ),/*b*/
        c[ N ][ N ];/*存放全部的计算过程，动态规划，体现在这个地方，中间计算结果都在这里*/
    k = lcs_len( a, b, c );/*将c［］［］传给lcs_len()计算并求出长度，将中间结果放在c[][]中*/
    s[ k ] = '\0';/*s串的结束标记*/
    while( k > 0 )/*开始倒推*/
        if( c[ i ][ j ] == c[ i - 1 ][ j ] ) i --;
        else if( c[ i ][ j ] == c[ i ][ j -1 ]) j--;
                else 
                {    s[ --k ] = a[ i - 1 ];/*将一个公共字符存入s中*/
                     i--;
                     j--;
                }
                printf("%d\n",c[i][j]);
    return s;
}

/*测试程序*/
int	 main(){
    printf("Enter two string(<%d)!\n", N );
    scanf( "%s%s", a,b );
//    printf("LCS = %s\n", build_lcs( str, a, b ));
    return 0;
}

