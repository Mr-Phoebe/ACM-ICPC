//input : succ
//output dom_t and idom redfn
//notice that the index i in dom_t[i] and dom_t[i][j] is the vertex's timestamp in dfs
//hence you need redfn[i] to find the original vertex
//o(mlogm) where m is the number of edges
//UPD:new version is o(m¦Á(m, n)), the previous version is in comment


const int vector_num; //max number of vertices

vector<int> succ[vector_num+10], prod[vector_num+10], bucket[vector_num+10], dom_t[vector_num+10];
int semi[vector_num+10], anc[vector_num+10], idom[vector_num+10], best[vector_num+10], fa[vector_num+10];
int dfn[vector_num+10], redfn[vector_num+10];
int child[vector_num+10], size[vector_num+10];
int timestamp;

void dfs(int now) {
	dfn[now] = ++timestamp;
	redfn[timestamp] = now;
	anc[timestamp] = idom[timestamp] = child[timestamp] = size[timestamp] = 0;
	semi[timestamp] = best[timestamp] = timestamp;
	int sz = succ[now].size();
	for(int i = 0; i < sz; ++i) {
		if(dfn[succ[now][i]] == -1) {
			dfs(succ[now][i]);
			fa[dfn[succ[now][i]]] = dfn[now];
		}
		prod[dfn[succ[now][i]]].push_back(dfn[now]);
	}
}

void compress(int now) {
	if(anc[anc[now]] != 0) {
		compress(anc[now]);
		if(semi[best[now]] > semi[best[anc[now]]])
			best[now] = best[anc[now]];
		anc[now] = anc[anc[now]];
	}
}

//eval function of previous version
/*
int eval(int now) {
	if(anc[now] == 0)
		return now;
	compress(now);
	return best[now];
}
*/

inline int eval(int now) {
	if(anc[now] == 0)
		return now;
	else {
		compress(now);
		return semi[best[anc[now]]] >= semi[best[now]] ? best[now]
			: best[anc[now]];
	}
}

inline void link(int v, int w) {
	int s = w;
	while(semi[best[w]] < semi[best[child[w]]]) {
		if(size[s] + size[child[child[s]]] >= 2*size[child[s]]) {
			anc[child[s]] = s;
			child[s] = child[child[s]];
		} else {
			size[child[s]] = size[s];
			s = anc[s] = child[s];
		}
	}
	best[s] = best[w];
	size[v] += size[w];
	if(size[v] < 2*size[w])
		swap(s, child[v]);
	while(s != 0) {
		anc[s] = v;
		s = child[s];
	}
}

void lengauer_tarjan(int n) { // n is the vertices' number
	memset(dfn, -1, sizeof dfn);
	memset(fa, -1, sizeof fa);
	timestamp = 0;
	dfs(n);
	fa[1] = 0;
	for(int w = timestamp; w > 1; --w) {
		int sz = prod[w].size();
		for(int i = 0; i < sz; ++i) {
			int u = eval(prod[w][i]);
			if(semi[w] > semi[u])
				semi[w] = semi[u];
		}
		bucket[semi[w]].push_back(w);
		//anc[w] = fa[w]; link operation for o(mlogm) version
                link(fa[w], w);
		if(fa[w] == 0)
			continue;
		sz = bucket[fa[w]].size();
		for(int i = 0; i < sz; ++i) {
			int u = eval(bucket[fa[w]][i]);
			if(semi[u] < fa[w])
				idom[bucket[fa[w]][i]] = u;
			else
				idom[bucket[fa[w]][i]] = fa[w];
		}
		bucket[fa[w]].clear();
	}
	for(int w = 2; w <= timestamp; ++w) {
		if(idom[w] != semi[w])
			idom[w] = idom[idom[w]];
	}
	idom[1] = 0;
	for(int i = timestamp; i > 1; --i) {
		if(fa[i] == -1)
			continue;
		dom_t[idom[i]].push_back(i);
	}
}
