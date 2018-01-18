#include <bits/stdc++.h>

using namespace std;

const int zero = 45;
int dp[10][100][10][10][10];
int digit[10];

int count(int pos, int sum, int first_pos, int lb, int ub, bool limit) {
	if(pos == -1)
		return sum != zero && sum - lb <= zero && sum + ub >= zero;
	if(!limit && dp[pos][sum][first_pos][lb][ub] != -1)
		return dp[pos][sum][first_pos][lb][ub];
	int upper = limit ? digit[pos] : 9;
	int ret = 0;
	for(int i = first_pos == pos; i <= upper; ++i){
		int new_lb, new_ub;
		if(pos > first_pos/2)
			new_lb = max(lb, i - (pos == first_pos)), new_ub = max(ub, 9 - i);
		else
			new_lb = max(lb, 9 - i), new_ub = max(ub, i);
		ret += count(pos-1, sum + (pos > first_pos/2 ? i : -i), first_pos, new_lb, new_ub, limit && i == upper);
	}
	if(!limit)
		dp[pos][sum][first_pos][lb][ub] = ret;
	return ret;
}

int calc(int num) {
	int len = 0;
	while(num) {
		digit[len++] = num %10;
		num /= 10;
	}
	int ret = 0;
	for(int i = 1; i < len; i += 2)
		ret += count(i, zero, i, 0, 0, i == len-1);
	return ret;
}

int main() {
	memset(dp, -1, sizeof dp);
	int l, r;
	scanf("%d%d", &l, &r);
	printf("%d\n", calc(r) - calc(l-1));
	return 0;
}

