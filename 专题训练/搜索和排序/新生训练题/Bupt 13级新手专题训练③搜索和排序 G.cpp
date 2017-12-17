#include<iostream>
#include<string>
#include<map>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
	multimap <string,string> rela;
	map <string,string> ans;
	const string cmp("#");
	string t1,t2;
	
	while(cin>>t1,t1.compare(cmp)!=0)
	{
		char str[111];int i;
		for(i=0;i<t1.length();i++)
			str[i]=tolower(t1.at(i));
		str[i]='\0';
		sort(str,str+i);
		for(i=0;str[i]!='\0';i++)
			t2+=str[i];
		rela.insert(make_pair(t2,t1));
		t2.clear();
	}
	for (multimap<string,string>::iterator theIterator=rela.begin();theIterator!=rela.end();theIterator++)
		if(rela.count((*theIterator).first)==1)
			ans.insert(make_pair((*theIterator).second,(*theIterator).first));
	
	for (multimap<string,string>::iterator theIterator=ans.begin();theIterator!=ans.end();theIterator++)
			cout<<(*theIterator).first<<endl;

	return 0;
	
} 