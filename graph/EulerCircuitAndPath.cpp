/*

class Solution {
  public:
  
  void dfs(int u,vector<bool>&vis,vector<int>adj[]){
      vis[u]=true;
      
      for(auto &v:adj[u]){
          if(!vis[v]){
              dfs(v,vis,adj);
          }
      }
  }
  
    bool isconnected(int V, vector<int> adj[]){
        
        int non0degree=-1;
        
        for(int i=0; i<V; ++i){
            if(adj[i].size()>0){
                non0degree=i;
                break;
            }
        }
        
        vector<bool>vis(V,false);
        
        dfs(non0degree,vis,adj);
        
        for(int i=0; i<V; ++i){
            if(!vis[i] && adj[i].size()>0){
                return false;
            }
        }
        
        return true;
    }
  
    int isEulerCircuit(int V, vector<int> adj[]) {
        
    //CHECKING ALL THE VERTEX WITH DEGREE > 0 IS IN ONE COMPONENT
        if(!isconnected(V,adj)){
            return 0;
        }
        
        int oddcount=0;
        
        for(int i=0; i<V; ++i){
            if(adj[i].size()%2!=0) oddcount++; //CALCULATING THE DEGREE
        }
        
        //IT HAS EULER PATH (THE ODD'S ARE ONE IS STARTING NODE AND THE OTHER IS ENDING NODE)
        if(oddcount==2) return 1;

        //IT HAS EULER CIRCUIT (ALL THE NODES HAVE EVEN DEGREE)
        if(oddcount==0) return 2;
        
        return 0;
    }
};

*/

/*
for directed graph

there will be indegree -> incoming to the node
there will be outdegree -> outgoing from the node

if outdegree[node]-indegree[node]==1 then it is a start node or source node
if indegree[node]-outdegree[node]==1 then it is a end node or destination node
for othenodes indegree[node]==outdegree[node]




To find EP 
find the start node using the above formula then check it 

To find EC
the nodes will have equal indegree and outdegree 
*/