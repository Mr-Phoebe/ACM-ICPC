#include<iostream>
#include<string>

using namespace std;

bool mirrored(string str)
{
	int i,j;
	for(i=0,j=str.length()-1;i<=j;i++,j--)
		switch(str[i])
		{
			case 'B':
			case 'C':
			case 'D':
			case 'F':
			case 'G':
			case 'K':
			case 'N':
			case 'P':
			case 'Q':
			case 'R':
			case '4':
			case '6':
			case '7':
			case '9':
				return false;
			case 'E':
				if(str[j]!='3')
					return false;
				break; 
			case 'J':
				if(str[j]!='L')
					return false;	
				break;
			case 'L':
				if(str[j]!='J')
					return false;		
				break;	
			case 'S':
				if(str[j]!='2')
					return false;	
				break;
			case '3':
				if(str[j]!='E')
					return false;
				break;
			case 'A':
			case 'H':
			case 'I':
			case 'M':
			case 'O': 
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case '8':
				if(str[j]!=str[i])
					return false;	
				break;
			case '2':
				if(str[j]!='S')
					return false;
				break;
			case 'Z':
				if(str[j]!='5')
					return false;
			case '5':
				if(str[j]!='Z')
					return false;
				break;
			default:
				return false;
		}
	return true;
}

bool palindrome(string str)
{
	int i,j;
	for(i=0,j=str.length()-1;i<j;i++,j--)
		if(str[i]!=str[j])
			return false;
	return true;
}




int main()
{
	string str;
	while(cin>>str)
	{
		bool pa=palindrome(str);
		bool mi=mirrored(str);
		if(!pa&&!mi)
			cout<<str<<" -- is not a palindrome."<<endl<<endl;
		else if(!pa&&mi)
			cout<<str<<" -- is a mirrored string."<<endl<<endl;
		else if(pa&&!mi)
			cout<<str<<" -- is a regular palindrome."<<endl<<endl;
		else if(pa&&mi)
			cout<<str<<" -- is a mirrored palindrome."<<endl<<endl;
		str.clear();
	}
	return 0;
} 