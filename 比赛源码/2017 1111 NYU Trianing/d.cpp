#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > card[4][2];
vector<int> real;
vector<int> cur;

int val(char c)
{
	if(isdigit(c))
		return c - '0';
	else if(c == 'T')
		return 10;
	else if(c == 'J')
		return 11;
	else if(c == 'Q')
		return 12;
	else if(c == 'K')
		return 13;
	else if(c == 'A')
		return 14;
}

int suit(char c)
{
	//s, h, d, c
	if(c == 's')
		return 0;
	else if(c == 'h')
		return 1;
	else if(c == 'd')
		return 2;
	return 3;
}

bool vis[4];
int ans, n;
int tmp[55], len;


int getdp()
{
	memset(tmp, -1, sizeof(tmp));
	len = 1;
	
	for(int i = 0; i < n; i++)
	{
		if(cur[i] > tmp[len-1])
			tmp[len++] = cur[i];
		else
		{
			int pos = lower_bound(tmp, tmp+len, cur[i]) - tmp;
			tmp[pos] = cur[i];
		}
	}
	return n - len + 1;
}

void dfs(int num)
{
	if(num == 4)
	{
		ans = min(ans, getdp());
		return;
	}
	else
	{
		for(int i = 0; i < 4; i++)
			if(!vis[i])
			{
				vis[i] = 1;
				for(int j = 0; j < card[i][0].size(); j++)
					cur.push_back(card[i][0][j].second);
				dfs(num+1);
				for(int j = 0; j < card[i][0].size(); j++)
					cur.pop_back();
				for(int j = 0; j < card[i][1].size(); j++)
					cur.push_back(card[i][1][j].second);
				dfs(num+1);
				for(int j = 0; j < card[i][1].size(); j++)
					cur.pop_back();
				vis[i] = 0;
			}
	}
}

int main()
{

	char s[11];
	memset(vis, 0, sizeof(4));
	scanf("%d", &n);
	ans = n;
	for(int i = 0; i < n ;i++)
	{
		scanf("%s", s);
		int pos = suit(s[1]);
		card[pos][0].push_back(make_pair(val(s[0]), i));
	}
	for(int i = 0; i < 4; i++)
	{
		sort(card[i][0].begin(), card[i][0].end());
		card[i][1] = card[i][0];
		reverse(card[i][1].begin(), card[i][1].end());
	}
	dfs(0);
	cout<<ans<<endl;
	return 0;
}
