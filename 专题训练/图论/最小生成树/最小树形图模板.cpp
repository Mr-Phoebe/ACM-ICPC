typedef int type;
const int inf = 1000;

struct node {
	int s, e;
	type l;
};

int sum[55];
node ed[500*50+2000+10];

int num;
void add(int s, int e, type l) {
	ed[num].s = s;
	ed[num].e = e;
	ed[num].l = l;
	num++;
}

void init() {
	num = 0;
	sum[0] = 0;
}

int n, S;
int pre[50*500+10], id[50*500+10], vis[50*500+10];
type in[50*500+10];

type Directed_MST(int root ,int NV , int NE){
    type ret = 0 ;
    while(1){
        for (int i = 0 ; i < NV ; i ++ )in[i] = inf ;
        for (int i = 0 ; i < NE ; i ++ ){
            int s = ed[i].s ;
            int e = ed[i].e ;
            if(ed[i].l < in[e] && s != e){
                pre[e] = s ;
                in[e] = ed[i].l ;
            }
        }
        for (int i = 0 ; i < NV ; i ++ ){
            if(i == root)continue ;
//			printf("in[%d] = %d\n", i, in[i]);
            if(in[i] == inf)return -1 ;
        }
        int cntnode = 0 ;
        memset(vis ,-1, sizeof vis) ;
        memset(id ,-1, sizeof vis) ;
        in[root] = 0 ;
        for (int i = 0 ; i < NV ; i ++ ){
            ret += in[i] ;
            int v = i ;
            while(vis[v] != i && id[v] == -1 && v != root){
                vis[v] = i ;
                v = pre[v] ;
            }
            if(v != root && id[v] == -1){
                for (int u = pre[v] ; u != v ; u = pre[u]){
                    id[u] = cntnode ;
                }
                id[v] = cntnode ++ ;
            }
        }

        if(cntnode == 0)break ;
        for (int i = 0 ; i < NV ; i ++ ){
            if(id[i] == -1)id[i] = cntnode ++ ;
        }
        for (int i = 0 ; i < NE ; i ++ ){
            int s = ed[i].s ;
            int e = ed[i].e ;
            ed[i].s = id[s] ;
            ed[i].e = id[e] ;
            if(ed[i].s != ed[i].e){
                ed[i].l -= in[e] ;
            }
        }
        NV = cntnode ;
        root = id[root] ;
    }
    return ret ;
}