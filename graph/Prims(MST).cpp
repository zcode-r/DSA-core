/*

class Solution {
  public:
    
    typedef pair<int,int> p;
  
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        
        unordered_map<int,vector<p>>mp;
        
        for(auto &e:edges){
            int u=e[0],v=e[1],w=e[2];
            
            mp[u].push_back({w,v});
            mp[v].push_back({w,u});
        }
        
        priority_queue<p,vector<p>,greater<p>>pq;
        vector<bool>vis(V,false);
        
        pq.push({0,0});
        int sum=0;
        
        while(!pq.empty()){
            
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            if(vis[node]) continue;
            
            vis[node]=true;
            sum+=wt;
            
            for(auto &i:mp[node]){
                
                int wtt=i.first;
                int nodee=i.second;
                
                if(!vis[nodee]){
                    pq.push({wtt,nodee});
                }
            }
        }
        
        return sum;
    }
};

*/