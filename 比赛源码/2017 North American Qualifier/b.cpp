#include <bits/stdc++.h>

using namespace std;
#define int long long
int n,m,f,s,t;
vector<vector<pair<int,int> > > g(500001);
vector<pair<int,int> > fl(1001);
#define ii pair<int,int> 
#define vi vector<int> 
vector<int> dijkstra(int s){

 	vi D(n, 1e15); 
      // distance from start vertex to each vertex

      priority_queue<ii,vector<ii>, greater<ii> > Q; 
      // priority_queue with reverse comparison operator, 
      // so top() will return the least distance
      // initialize the start vertex, suppose it’s zero
      D[s] = 0;
      Q.push(ii(0,s));

      // iterate while queue is not empty
      while(!Q.empty()) {

            // fetch the nearest element
            ii top = Q.top();
            Q.pop();
                        
            // v is vertex index, d is the distance
            int v = top.second, d = top.first;

            // this check is very important
            // we analyze each vertex only once
            // the other occurrences of it on queue (added earlier) 
            // will have greater distance
            if(d <= D[v]) {
                  // iterate through all outcoming edges from v
                  for(vector<pair<int,int> > :: iterator it = g[v].begin();it != g[v].end(); it++){
				  
                        int v2 = it->first, cost = it->second;
                        if(D[v2] > D[v] + cost) {
                              // update distance if possible
                              D[v2] = D[v] + cost;
                              // add the vertex to queue
                              Q.push(ii(D[v2], v2));

                        }
                  }
            }
      }
      return D;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> f >> s >> t;
	int x,y,z;
	for(int i=0;i<m;i++){
		cin >> x >> y >> z;
		g[x].push_back({y,z}); 
		g[y].push_back({x,z});
	}
	for(int i=0;i<f;i++){
		cin >> x >> y;
		
		fl[i] = {x,y};
	}
	vector<int> v1 = dijkstra(s);
	vector<int> v2 = dijkstra(t);
	int ct = v1[t];
	for(int i=0;i<f;i++){
		ct = min(ct, v1[fl[i].first] + v2[fl[i].second]);	
	}
	cout << ct << endl;
	return 0;
}
