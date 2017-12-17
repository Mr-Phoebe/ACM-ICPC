#include<stdio.h>
#include<time.h>
#include<malloc.h>
#include<stdlib.h>  

typedef struct node
{
    int num;
    struct node *prior,  *next;
} stud; 						/*˫����Ľṹ����*/

stud *creat(int n)
{
    stud *p,  *h,  *s;
    int i;
    h = (stud*)malloc(sizeof(stud));			/*������ռ�*/
    h->num = 0;
    h->prior = NULL;
    h->next = NULL;
    p = h;
    for (i = 0; i < n; i++)
    {
        s = (stud*)malloc(sizeof(stud));
        p->next = s;						/*ָ����̽��*/
        s->num=n-i;
        s->prior = p;						/*ָ��ǰ�����*/
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
 //   scanf("%d", &number);					/*������������*/
    head = creat(number);					/*��������*/
    sp = head->next;
    for(sp=head->next;sp;sp=sp->next) 							/*�������������*/
		for(sl=sp->prior;sl;sl=sl->prior)
			if(sl->num>sp->num)
				k++;
	printf("%d\n",k);
	time(&start_time);
	printf("%f",difftime(current_time,start_time));
	return 0;
}

