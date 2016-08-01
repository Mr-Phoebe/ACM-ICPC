#include<stdio.h>
#include<time.h>
#include<malloc.h>
#include<stdlib.h>  

typedef struct node
{
    int num;
    struct node *prior,  *next;
} stud; 						/*双链表的结构定义*/

stud *creat(int n)
{
    stud *p,  *h,  *s;
    int i;
    h = (stud*)malloc(sizeof(stud));			/*申请结点空间*/
    h->num = 0;
    h->prior = NULL;
    h->next = NULL;
    p = h;
    for (i = 0; i < n; i++)
    {
        s = (stud*)malloc(sizeof(stud));
        p->next = s;						/*指定后继结点*/
        s->num=n-i;
        s->prior = p;						/*指定前驱结点*/
        s->next = NULL;
        p = s;
    }
    p->next = NULL;
    return (h);
}

int main()
{
	time_t current_time,start_time;
	time(&current_time);
    int number=100000;
	int k=0;
    stud *head,*sp,*sl;
 //   scanf("%d", &number);					/*输入链表结点数*/
    head = creat(number);					/*创建链表*/
    sp = head->next;
    for(sp=head->next;sp;sp=sp->next) 							/*输出链表中数据*/
		for(sl=sp->prior;sl;sl=sl->prior)
			if(sl->num>sp->num)
				k++;
	printf("%d\n",k);
	time(&start_time);
	printf("%f",difftime(current_time,start_time));
	return 0;
}

