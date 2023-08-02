//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//kosaraju
//find topo order
//reverse graph
//do dfs in topo order only
class Solution
{
	public:
	
	void dfs(int node, vector<vector<int>>& adj, stack<int>&st, vector<bool>&vis){
	    vis[node] = true;
	    
	    for(auto child:adj[node]){
	        if(!vis[child]){
	            dfs(child,adj,st,vis);
	        }
	    }
	    
	    st.push(node);
	}
	void dfsT(int node,vector<vector<int>>&g,vector<bool>&vis){
	    vis[node] = true;
	    
	    for(auto child:g[node]){
	        if(!vis[child]){
	            dfsT(child,g,vis);
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int>st;
	    vector<bool>vis(V,false);
	    
	    for(int i = 0; i < V; i++){
	        if(!vis[i]){
	            dfs(i,adj,st,vis);
	        }
	    }
	    
	    vector<vector<int>>g(V);
	    
	    for(int u = 0; u < V;u++){
	        for(int &v:adj[u]){
	            g[v].push_back(u);
	        }
	    }
	    
	    vis = vector<bool>(V,false);
	    
	    int cntScc = 0;
	    
	    while(!st.empty()){
	        int node = st.top();
	        st.pop();
	        
	        if(!vis[node]){
	            cntScc++;
	            dfsT(node,g,vis);
	        }
	    }
	    return cntScc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends