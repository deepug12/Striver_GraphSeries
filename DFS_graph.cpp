#include<bits/stdc++.h>
using namespace std;

class graph{
	void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs){
		storeDfs.push_back(node);
		vis[node] = 1;
		for (auto it : adj[node])
		{
			if(!vis[it]){
				dfs(it, vis, adj, storeDfs);
			}
		}
	}
public:
	vector<int> dfsOfGraph(int V, vector<int> adj[]){
      vector<int> storeDfs;
      vector<int> vis(V+1, 0);

        for (int i = 0; i < V; i++) {
        	if (!vis[i]) {
          		dfs(i, vis, adj, storeDfs);
          	}
        }

      	return storeDfs;
    }


};
void printAns(vector < int > & ans) {
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
}

int main(){
	int n;
	cin >> n;

	int m;
	cin >> m;

	// declare the adjacent matrix 
	vector<int> adj[n+1]; 
	
	// take edges as input 
	for(int i = 0; i<m;i++) {
	    int u, v; 
	    cin >> u >> v;
	    adj[u].push_back(v); 
	    adj[v].push_back(u); 
	}
	graph obj;
	vector<int> ans = obj.dfsOfGraph(n, adj);
	printAns(ans);


	return 0;
}