#include<stdio.h>
#include<string.h>

	char a[2001],b[2001];
	int c[2001][2001];

int lcs_len( char *a, char *b, int c[][2001] )
{
    int m = strlen( a ),n = strlen( b ),i,j;
    
    for( i = 0; i <= m; i++ )
		c[ i ][ 0 ] = 0;/*j==0��ʾb������Ϊ0������a���೤�����ߵĹ��������г���Ϊ0*/
    for( j = 1; j <= n; j++ )
		c[ 0 ][ j ] = 0;/*������һ������*/
    for( i = 1; i <= m; i++ )/*��ʼ����*/
        for( j = 1; j <= n; j++ )/*�������е����һ���ַ���ͬ����ô���������г���Ϊȥ�������һ���ַ��������ɵ��������Ĺ��������г���+1*/
            if( a[ i - 1 ] == b[ j - 1 ])
                 c[ i ][ j ] = c[ i - 1 ][ j - 1 ] + 1;
            else if( c[ i - 1 ][ j ] >= c[ i ][ j -1 ] )
                     c[ i ][ j ] = c[ i - 1 ][ j ]; /*�����������һ���ַ���ͬ����ô������������еĳ���Ϊc[ i - 1][j]��c[i][j-1]�нϴ��һ��*/
                 else 
                    c[ i ][ j ] = c[ i ][ j -1 ];
                

    return c[ m ][ n ];/*�����a��b����������г��ȴ���c[m][n]��*/
}



/*���Գ���*/
int	 main()
{

    scanf("%s%s",a,b);
    printf("%d\n",lcs_len(a,b,c));
    return 0;
}

