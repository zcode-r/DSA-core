/*

class Solution {
  public:
  
    void dfs(int u,vector<vector<int>>&adj,vector<bool>&vis,stack<int>&st){
        vis[u]=true;
        
        for(auto &v:adj[u]){
            if(!vis[v]){
                dfs(v,adj,vis,st);
            }
        }
        
        st.push(u);
    } 
    
    void dfstravel(int u,vector<vector<int>>&rev,vector<bool>&vis){
        vis[u]=true;
        
        for(auto &v:rev[u]){
            if(!vis[v]){
                dfstravel(v,rev,vis);
            }
        }
    }
    
    int kosaraju(int V, vector<vector<int>> &edges) {
        // code here
        stack<int>st;
        
        vector<bool>vis(V,false);
        vector<vector<int>>adj(V);
        vector<vector<int>>rev(V);
        
        for(auto &i:edges){
            int u=i[0];
            int v=i[1];
            
            adj[u].push_back(v);
        }
        
        //step 1 to build a stack using topo
        
        for(int i=0; i<V; ++i){
            
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        
        //step 2 reverse the edges
        
        for(int u=0; u<V; ++u){
            for(auto &v:adj[u]){
                rev[v].push_back(u);
            }
        }
        
        //step 3 call dfs according to stack order
        
        int count=0;
        
        vis=vector<bool>(V,false);
        
        while(!st.empty()){
            int x=st.top();
            st.pop();
            
            if(!vis[x]){
                dfstravel(x,rev,vis);
                ++count;
            }
        }
        
        return count;
    }
};

*/