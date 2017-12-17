/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        UndirectedGraphNode* copy = new UndirectedGraphNode(node -> label);
        mp[node] = copy;
        queue<UndirectedGraphNode*> que;
        que.push(node);
        while(!que.empty())
        {
            auto cur = que.front();
            que.pop();
            for(auto neigh : cur -> neighbors)
            {
                if(mp.find(neigh) == mp.end())
                {
                    UndirectedGraphNode* neigh_copy = new UndirectedGraphNode(neigh -> label);
                    mp[neigh] = neigh_copy;
                    que.push(neigh);
                }
                mp[cur]->neighbors.push_back(mp[neigh]);
            }
        }
        return copy; 
    }
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
};
