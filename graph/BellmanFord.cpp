/*

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        
        vector<int>ans(V,1e8);
        ans[src]=0;

        //EDGE RELAXATION
        
        for(int i=1; i<=V-1; ++i){
            
            for(auto &e:edges){
                int u=e[0];
                int v=e[1];
                int w=e[2];
                
                if(ans[u]!=1e8 && ans[u]+w<ans[v]){
                    ans[v]=ans[u]+w;
                }
            }
        }

        //DETECTION OF NEGATIVE CYCLE
        
        for(auto &e:edges){
                int u=e[0];
                int v=e[1];
                int w=e[2];
                
                if(ans[u]!=1e8 && ans[u]+w<ans[v]){
                    return {-1};
                }
        }
        
        return ans;
    }
};

*/