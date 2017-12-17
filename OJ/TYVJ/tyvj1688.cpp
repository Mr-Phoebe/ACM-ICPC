#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	char str[15];
	gets(str);
	if(str[0]=='-')
		cout<<'-';
	int i=strlen(str)-1;
	for(;str[i]=='0';i--)
		str[i]='\0';
	for(i=strlen(str)-1;i>=1;i--)
		cout<<str[i];
	if(str[i]=='-')
		cout<<endl;
	else
		cout<<str[i]<<endl;
	return 0;
}

