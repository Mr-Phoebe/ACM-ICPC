class Solution {
public:
    static const int maxn = 15;

    int n;

    static const int maxCol = maxn * maxn * 4;
    static const int maxNode = maxCol + maxn * maxn * maxn * 4;

    int ID;
    int h, S[maxCol], N[maxCol];
    int U[maxNode], D[maxNode], L[maxNode], R[maxNode], C[maxNode], V[maxNode];

    char str[maxn*maxn];

    bool succ;
    void DL(int c, bool uncover = false)
    {
        if (!uncover) {R[L[c]] = R[c], L[R[c]] = L[c];}
        else {R[L[c]] = L[R[c]] = c;}
        for (int i = D[c]; i != c; i = D[i]) {
            for (int j = R[i]; j != i; j = R[j]) {
                if (!uncover) {U[D[j]]=U[j], D[U[j]]=D[j], --S[C[j]];}
                else {U[D[j]] = D[U[j]] = j, ++S[C[j]];}
            }
        }
    }
    void dfs(int dep)
    {
        if (succ || R[h] == h) {
            succ = true;
            return ;
        }
        int c = R[h];
        for (int i = R[h]; i != h; i = R[i]) {
            if (!S[i]) return ;
            if (S[i] < S[c]) c = i;
        }
        DL(c);
        for (int i = D[c]; i != c; i = D[i]) {
            N[c] = V[i];
            for (int j = R[i]; j != i; j = R[j]) {
                DL(C[j]), N[C[j]] = V[j];
            }
            dfs(dep+1);
            if (succ) return ;
            for (int j = L[i]; j != i; j = L[j]) {
                DL(C[j], true);
            }
        }
        DL(c, true);
    }
    int add(int c, int v)
    {
        ++S[c];
        L[ID] = R[ID] = ID;
        U[ID] = U[c], D[ID]  = c;
        D[U[ID]] = U[D[ID]] = ID;
        V[ID] = v;
        C[ID] = c;
        return ID++;
    }
    # define INSR(x, y) do{ L[y]=x,R[y]=R[x];R[L[y]]=L[R[y]]=y; }while(0)
    void solveSudoku(std::vector<std::vector<char> > &board) {
        n = 9;

        char str[maxn*maxn];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                str[i*9+j] = board[i][j];
            }
        }
        str[n*n] = 0;

        h = 4*n*n;
        for (int c = 0; c <= h; ++c) {
            S[c] = 0;
            C[c] = D[c] = U[c] = c;
            L[c] = (c ? c-1:h), R[c] = (c==h ? 0:c+1);
        }
        ID = h + 1;
        for (int i = 0; str[i]; ++i) {
            int x = i / 9, y = i % 9;
            int lo = 1, hi = n;
            if ('1'<=str[i]&&str[i]<='0'+n) {
                lo = hi = str[i] - '0';
                V[i] = str[i] - '0';
            }
            for (int j = lo; j <= hi; ++j) {
                int a = add(i, j);
                int b = add(n*n+x*9+j-1, j);
                int c = add(2*n*n+y*9+j-1, j);
                int d = add(3*n*n+(x/3*3+y/3)*9+j-1, j);
                INSR(a, b);
                INSR(b, c);
                INSR(c, d);
            }
        }
        for (int i = R[h]; i != h; i = R[i]) {
            if (S[i] == 0) return;
            if (S[i] == 1) {
                N[i] = V[i];
                DL(i);
                for (int j = D[i]; j != i; j = D[j]) {
                    for (int k = R[j]; k != j; k = R[k]) DL(C[k]), N[C[k]] = V[k];
                }
            }
        }
        succ = false;
        dfs(0);
        if (succ) {
            for (int i = 0; i < n*n; ++i) {
                board[i/9][i%9] = N[i] + '0';
            }
        }
    }
};