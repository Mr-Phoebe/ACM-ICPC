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
	int count;                    //����·������
private:
	int *x;		//x[i]��ʾ��i���ϻʺ��λ��
	bool *a;	//a[i]ΪTRUE���i���޻ʺ�
	bool *b;	//b[i]ΪTRUE���i���Խ���(��б)�޻ʺ�
	bool *c;	//c[i]ΪTRUE���i���Խ���(��б)�޻ʺ�
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



//���е�i�γ���
void ChessBoard::Try(int i)
{
	int j;
	for (j=0;j<NUM_OF_QUEENS;j++)
	{
		if ( a[j]&&b[i+j]&&c[i-j+NUM_OF_QUEENS] )
		{							//˵��(i,j)����Է�
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
