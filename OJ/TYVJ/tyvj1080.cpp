#include <stdio.h>
#include <stdlib.h>

static int NUM_OF_QUEENS;

#define TRUE 1
#define FALSE 0

class ChessBoard
{
public:
	ChessBoard();
	void Try(int);
	void PrintResult();
	int count;                    //所有路径总数
private:
	int *x;		//x[i]表示第i列上皇后的位置
	bool *a;	//a[i]为TRUE表第i行无皇后
	bool *b;	//b[i]为TRUE表第i条对角线(左斜)无皇后
	bool *c;	//c[i]为TRUE表第i条对角线(右斜)无皇后
};


ChessBoard::ChessBoard()
{
	int i;
	count = 0;
	x=(int *)malloc(NUM_OF_QUEENS*sizeof(int));
	a=(bool *)malloc(NUM_OF_QUEENS*sizeof(int));
	b=(bool *)malloc(2*NUM_OF_QUEENS*sizeof(int));
	c=(bool *)malloc(2*NUM_OF_QUEENS*sizeof(int));
	for (i=0;i<NUM_OF_QUEENS;i++)
		x[i] = 0;
	for (i=0;i<NUM_OF_QUEENS;i++)
		a[i] = TRUE;
	for (i=0;i<2*NUM_OF_QUEENS;i++)
		b[i] = TRUE;
	for (i=0;i<2*NUM_OF_QUEENS;i++)
		c[i] = TRUE;
}


void ChessBoard::PrintResult()
{
	int i;
	if(count<3)
	{
		for (i=0;i<NUM_OF_QUEENS;i++)
			printf("%d ",x[i]+1);
		printf("\n");
	}
	count++;
}



//进行第i次尝试
void ChessBoard::Try(int i)
{
	int j;
	for (j=0;j<NUM_OF_QUEENS;j++)
	{
		if ( a[j]&&b[i+j]&&c[i-j+NUM_OF_QUEENS] )
		{							//说明(i,j)点可以放
			x[i] = j;
			a[j] = FALSE;
			b[i+j] = FALSE;
			c[i-j+NUM_OF_QUEENS] = FALSE;
			if ( i < NUM_OF_QUEENS-1 )
				Try(i+1);
			else 
			{

				PrintResult();
			}
			a[j] = TRUE;
			b[i+j] = TRUE;
			c[i-j+NUM_OF_QUEENS] = TRUE;
		}
	}
}

int main()
{
	scanf("%d",&NUM_OF_QUEENS);
	ChessBoard a;
	a.Try(0);
	printf("%d\n",a.count);
	return 0;
}
