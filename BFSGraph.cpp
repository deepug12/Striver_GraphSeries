#include<bits/stdc++.h>
using namespace std;
class graph{
public:
	vector<int> bfsOfGraph(int V, vector<int> adj[]){
      vector<int> bfs;
      vector<int> vis(V, 0);
      queue<int> q;
      q.push(0);
      vis[0] = 1;
      while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it: adj[node]) {
          if (!vis[it]) {
            q.push(it);
            vis[it] = 1;
          }
        }
      }

      return bfs;
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
	for(int i = 0;i<m;i++) {
	    int u, v; 
	    cin >> u >> v;
	    adj[u].push_back(v); 
	    adj[v].push_back(u); 
	}
	graph obj;
	vector<int> ans = obj.bfsOfGraph(n, adj);
	printAns(ans);


	return 0;
}