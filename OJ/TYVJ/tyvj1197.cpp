#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	char a[200],b[100];
	int t[100];
	int i,j,k=0,temp=0;
	int befa=0,lena,befb=0,lenb,befc;
	cin>>a>>b;
	lena=strlen(a);lenb=strlen(b);
	for(i=0;i<lena;i++,befa++)
		if(a[i]=='.')
		{
			befa=i;
			break;
		}
	for(i=0;i<lenb;i++,befb++)
			if(b[i]=='.')
		{
			befb=i;
			break;
		}
	for(i=befa-1,j=befb-1;i>=0 || j>=0;i--,j--)
	{
		if(j<=0)
			while(i)
			{
				t[k++]=(int)a[i--]-'0'+temp;
				temp=t[k]/2;
				t[k]%=2;
			}
		else if(i<=0)
			while(j)
			{
				t[k++]=(int)b[j--]-'0'+temp;
				temp=t[k]/2;
				t[k]%=2;
			}
		else
		{
			t[k]=(int)a[i]+(int)b[j]+tempp-'0'*2;
			temp=t[k]/2;
			t[k++]%=2;
		}
	}
	if(temp)
		t[k++]=temp;
	befc=k;
	for(i=befc;i>=0;i--)
		cout<<t[i];
	for(i=befa+1,j=befb+1;i<lena || j<lenb;i++,j++)
	{
		if(j<lenb)
			while(i<lena)
			{
				t[k++]=a[i]-'0'+temp;
				temp=t[k]/2;
				t[k]%=2;
			}
		else if(i<lena)
			while(j<lenb)
			{
				t[k++]=(int)b[j++]-'0'+temp;
				temp=t[k]/2;
				t[k]%=2;
			}
		else
		{
			t[k]=a[i]+b[j]-'0'*2+temp;
			temp=t[k]/2;
			t[k++]%=2;
		}
	}
	if(befb!=lenb || befa!=lena)
	{
		cout<<".";
		for(i=befc+1;i<=k;i++)
			cout<<t[i];
	}
	cout<<endl;
	return 0;


} 