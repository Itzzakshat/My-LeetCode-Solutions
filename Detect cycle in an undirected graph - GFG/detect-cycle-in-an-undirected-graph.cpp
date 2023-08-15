//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DSU{
private:
    
    vector<int>parent;
    vector<int>rank;
    int components;

public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1);

        for(int i = 0; i <=n;i++){
            parent[i] = i;
            rank[i] = 0;
        }

        components = n;
    }
    int find(int i){
        if(i==parent[i]) return i;

        return parent[i] = find(parent[i]);
    }

    void Union(int x,int y){
        int par_x = find(x);
        int par_y = find(y);

        if(par_x == par_y) return; //they r already in same set
        
        if(rank[par_x]<rank[par_y]){
            parent[par_x] = par_y;   //join with higher rank
        }
        else if(rank[par_x]>rank[par_y]){
            parent[par_y] = par_x;
        }else{
            parent[par_y] = par_x;
            rank[par_x]++;
        }
        components--;
    }
    bool isSingle(){
        return components==1;
    }
};
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool isCycle(int V, vector<int> adj[]) {
        DSU d1(V);
        for(int u = 0; u < V;u++){
            for(auto v:adj[u]){
                if(u < v){
                    if(d1.find(v)==d1.find(u)) return true;
                    else d1.Union(u,v);
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends