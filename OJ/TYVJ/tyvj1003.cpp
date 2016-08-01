#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
	unsigned long M,T,U,F,D;
	int i;
	cin>>M>>T>>U>>F>>D;
	char s_i[100000];
	for(i=0;i<T;i++)
	{getchar();s_i[i]=getchar();}
	for(i=0;M>0 && i<T;i++)
		switch(s_i[i])
	{
		case 'u':
			M-=U+D;break;
		case 'f':
			M-=2*F;break;
		case 'd':
			M-=U+D;break;
	}
	if(M>0)
		cout<<T<<endl;
	else
		cout<<i-1<<endl;
	

	return 0;
}