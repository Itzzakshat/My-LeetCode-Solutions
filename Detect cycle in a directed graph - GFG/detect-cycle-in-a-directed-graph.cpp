//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int node,int V,vector<int>adj[],vector<int>&vis){
        vis[node] = 2; //pathvisited
        
        for(auto it:adj[node]){
            if(vis[it]==0){
                vis[it] = 2;
                if(dfs(it,V,adj,vis)) return true;
            }else if(vis[it]==2){
                return true;
            }
        }
        vis[node] = 1;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        // vector<bool>pathvis(V,false);
        for(int i = 0; i < V;i++){
            if(!vis[i]){
                if(dfs(i,V,adj,vis)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends