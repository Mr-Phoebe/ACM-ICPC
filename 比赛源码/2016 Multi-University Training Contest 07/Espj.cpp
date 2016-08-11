#include <stdio.h>
#include <string.h>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

char ans[][20] = {"Case #1: No\n", "Case #2: Yes\n", "Case #3: Yes\n", "Case #4: No\n", "Case #5: Yes\n", "Case #6: Yes\n", "Case #7: No\n", "Case #8: Yes\n", "Case #9: Yes\n", "Case #10: Yes\n"};

const int MAXN = 1010;
char buf1[100000], buf2[100000];
int n, m;
int a[MAXN];
vector<int> e[MAXN];
bitset<MAXN> mask[MAXN];
int d[MAXN], p[MAXN];

void assert(bool v)
{
	if (!v)
	{
		printf("WA\n");
		exit(0);
	}
}

void init(FILE *in)
{
    assert(fscanf(in, "%d", &n) == 1);
    for (int i = 1; i <= n; ++i) {
        assert(fscanf(in, "%d", &a[i]) == 1);
        assert(0 <= a[i] && a[i] < n);
    }
}

void readgraph(FILE *out)
{
    assert(fscanf(out, "%d\n", &m) == 1);
    assert(0 <= m && m <= n * (n - 1) / 2);
    for (int i = 1; i <= n; ++i) {
        e[i].clear(), mask[i].reset(), d[i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        assert(fscanf(out, "%d %d\n", &u, &v) == 2);
        assert(1 <= u && u <= n);
        assert(1 <= v && v <= n);
        assert(u != v);
        e[u].push_back(v);
        ++d[v];
    }
    for (int i = 1; i <= n; ++i) {
        sort(e[i].begin(), e[i].end());
        assert(unique(e[i].begin(), e[i].end()) == e[i].end());
    }
}

void topsort()
{
    int tail = 0;
    for (int i = 1; i <= n; ++i) {
        if (d[i] == 0) p[++tail] = i;
    }
    for (int head = 1; head <= tail; ++head) {
        int u = p[head];
        for (int i = 0; i < (int)e[u].size(); ++i) {
            int v = e[u][i];
            if (--d[v] == 0) p[++tail] = v;
        }
    }
    assert(tail == n);
}

void check()
{
    for (int i = n; i; --i) {
        int u = p[i];
        for (int j = 0; j < (int)e[u].size(); ++j) {
            int v = e[u][j];
            mask[u] |= mask[v];
        }
        assert((int)mask[u].count() == a[u]);
        mask[u].set(u);
    }
}

int main(int argc, char *argv[])
{
    FILE *in = fopen(argv[1], "r");
    int dat;
    fscanf(in, "%d", &dat);
    for (int cas = 1; cas <= dat; ++cas) {
        init(in);
        assert(fgets(buf1, sizeof(buf1), stdin) == buf1);
//        assert(fgets(buf2, sizeof(buf2), ans) == buf2);
        assert(strcmp(buf1, ans[cas-1]) == 0);
        int len = strlen(buf1);
        if (buf1[len - 2] == 's') { // "Yes"
            readgraph(stdin);
            topsort();
            check();
        }
    }
    assert(fgetc(stdin) == EOF);
    printf("AC!\n");
}
