#include <bits/stdc++.h>

using namespace std;

struct Node{
	int arr_t, num;
	Node(int t, int i): arr_t(t), num(i){};
};

int n;
map<int, string> index2name;

pair<int, int> white, black;
queue<int> q;
Node white_of=Node(1,0);
Node white_df=Node(3,0);
Node black_of=Node(2,0);
Node black_df=Node(4,0);

bool cmp(Node x, Node y) {
	return (x.num > y.num);
}

int ans=0;
vector<pair<int, int> > a;

int main(){
	cin >> n;
	for (int i=1; i<=n; i++){
		string s;
		cin >> s;
		index2name[i] = s;
	}
	white.first = 1; black.first = 2;
	white.second = 3; black.second = 4;
	for (int i=5; i<=n; i++) q.push(i);
	char ch;
	int i = 5;
	ch = getchar();
	while ((ch=getchar()) == 'W' || ch =='B') {
		if (ch == 'W') {
			int temp1=white.first; white.first=white.second; white.second=temp1;
			Node temp2=white_df; white_df=white_of; white_of=temp2;
			white_df.num++; white_of.num++;
			
			if (black_of.num > ans){
				ans = black_of.num;
				a.clear();
				if (black_of.arr_t < black_df.arr_t) a.push_back(black);
				else a.push_back({black.second, black.first});
			}
			else if (black_of.num == ans) {
				if (black_of.arr_t < black_df.arr_t) a.push_back(black);
				else a.push_back({black.second, black.first});
			}
				
			
			q.push(black.second);
			black.second = black.first;
			black_df = black_of;
			black_df.num = 0;
			int x = q.front();
			q.pop();
			black.first = x;
			black_of = Node(i, 0);
		}
		else {
			int temp1=black.first; black.first=black.second; black.second=temp1;
			Node temp2=black_df; black_df=black_of; black_of=temp2;
			black_df.num++; black_of.num++;
			
			if (white_of.num > ans){
				ans = white_of.num;
				a.clear();
				if (white_of.arr_t < white_df.arr_t) a.push_back(white);
				else a.push_back({white.second, white.first});
			}
			else if (white_of.num == ans) {
				if (white_of.arr_t < white_df.arr_t) a.push_back(white);
				else a.push_back({white.second, white.first});
			}		
			
			q.push(white.second);
			white.second = white.first;
			white_df = white_of;
			white_df.num = 0;
			int x = q.front();
			q.pop();
			white.first = x;
			white_of = Node(i, 0);
		}
		i++;
	}
	if (white_of.num > ans){
		ans = white_of.num;
		a.clear();
		if (white_of.arr_t < white_df.arr_t) a.push_back(white);
		else a.push_back({white.second, white.first});
	}
	else if (white_of.num == ans) {
		if (white_of.arr_t < white_df.arr_t) a.push_back(white);
		else a.push_back({white.second, white.first});
	}
	
	if (black_of.num > ans){
		ans = black_of.num;
		a.clear();
		if (black_of.arr_t < black_df.arr_t) a.push_back(black);
		else a.push_back({black.second, black.first});
	}
	else if (black_of.num == ans) {
		if (black_of.arr_t < black_df.arr_t) a.push_back(black);
		else a.push_back({black.second, black.first});
	}
	
	for (int i=0; i<a.size(); i++) {
		cout << index2name[a[i].first] << " " << index2name[a[i].second] << endl;
	}
}
			
