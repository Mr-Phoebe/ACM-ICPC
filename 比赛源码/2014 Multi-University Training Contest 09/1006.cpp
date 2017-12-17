#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
int N,K;
vector <vector<int> > A, B, D, ans, mid, ans2;

bool init(){
	scanf("%d%d", &N, &K);
	if (N == 0 && K == 0){
		return false;
	}
	vector <int> vtmp;
	int tmp;
	
	A.clear();
	for (int i = 0; i < N; i++){
		vtmp.clear();
		for (int j = 0; j < K; j++){
			scanf("%d",&tmp);
			vtmp.push_back(tmp);	
		}
		A.push_back(vtmp);
	}
	
	B.clear();
	for (int i = 0; i < K; i++){
		vtmp.clear();
		for (int j = 0; j < N; j++){
			scanf("%d",&tmp);
			vtmp.push_back(tmp);	
		}
		B.push_back(vtmp);
	}
	return true;
}

vector <vector <int> > multiply(const vector <vector<int> > &X,const vector <vector<int> > &Y){
	int r = X.size();
	int l = X[0].size(); 
	int c = Y[0].size();
	int tmp;
	vector <vector<int> > ans(r);
	for (int i = 0; i < r; i++){
		ans[i].clear();
		for (int j = 0; j < c; j++){
			tmp = 0;
			for (int k = 0; k < l; k++){
				tmp += X[i][k] * Y[k][j];
			}
			tmp %= 6;
			ans[i].push_back(tmp);
		}
	}
	return ans;
}

vector <vector <int> > powd(int step){
	if (step == 1)
		return D;
	vector <vector<int> > ans = powd(step / 2);
	ans = multiply(ans, ans);
	if (step % 2)
		ans = multiply(D, ans);
	return ans;
	
}




int main(){
	while (init()){
		D = multiply(B, A);
		mid = powd(N * N - 1);	
		ans = multiply(A, mid);
		ans = multiply(ans, B);
		int r = ans.size();
		int c = ans[0].size();/*
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c - 1; j++){
				putchar(ans[i][j]+48);
				putchar(32);
			}
			putchar(ans[i][c - 1]+48);
			putchar('\n');
		}
		putchar('\n');*/
		int myans = 0;
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c ; j++){
				myans += ans[i][j];
			}
		}
		printf("%d\n", myans);
		
		/*
		D = multiply(A, B);
		ans2 = D;
		for (int i = 1; i < N * N; i++){
			ans2 = multiply(D, ans2);
		}
		for (int i = 0; i < ans.size(); i++){
			for (int j = 0; j < ans[i].size() - 1; j++)
			 	printf("%d ", ans2[i][j]-ans[i][j]);
			printf("%d\n", ans2[i][ans2[i].size() - 1]-ans[i][ans[i].size() - 1]);
		}
		*/
		
	} 
	return 0;
}
