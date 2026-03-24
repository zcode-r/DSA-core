#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Edge{

public:
    int v;
    int wt;

    Edge(int v,int wt){
        this->v=v;
        this->wt=wt;
    }

};

void dijkstra(int src,vector<vector<Edge>>g,int V){
    vector<int>dis(V,INT_MAX);
    dis[src]=0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});

    while(pq.size()>0){
        int u=pq.top().second;
        pq.pop();

        //Edge relaxation
        for(Edge edge:g[u]){
            int v  = edge.v;
            int wt = edge.wt;

            int newDist = dis[u] + wt;

            if(newDist < dis[v]) {
                dis[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }

    for(int i:dis) cout << i << " ";
}

int main(){
    int V=6;
    vector<vector<Edge>> g(V);

    g[0].push_back(Edge(1,2));
    g[0].push_back(Edge(2,4));

    g[1].push_back(Edge(2,1));
    g[1].push_back(Edge(3,7));

    g[2].push_back(Edge(4,3));

    g[3].push_back(Edge(5,1));

    g[4].push_back(Edge(3,2));
    g[4].push_back(Edge(5,5));

    dijkstra(0,g,V);

}



//////////////////////////////////////////////////////////////////

//USING PQ

/*
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto &e : edges){
            int u=e[0], v=e[1], w=e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w}); 
        }

        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>ans(V,INT_MAX);
        ans[src]=0;
        
        pq.push({0,src});
        
        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto &i:adj[node]){
                int n=i.first;
                int d=i.second;
                
                if(d+dist<ans[n]){
                    ans[n]=d+dist;
                    pq.push({d+dist,n});
                }
            }
        }
        
        return ans;
    }
};
*/


//////////////////////////////////////////////////////////////

//USING SET

/*
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto &e : edges){
            int u=e[0], v=e[1], w=e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w}); 
        }

        
        set<pair<int,int>>s;
        
        vector<int>ans(V,INT_MAX);
        ans[src]=0;
        
        s.insert({0,src});
        
        while(!s.empty()){

            auto &it=*s.begin();
            int dist=it.first;
            int node=it.second;
            s.erase(it);
            
            for(auto &i:adj[node]){
                int n=i.first;
                int d=i.second;
                
                if(d+dist<ans[n]){

                    if(ans[n]!=INT_MAX){
                        s.erase({ans[n],n});
                    }

                    ans[n]=d+dist;
                    s.insert({d+dist,n});
                }
            }
        }
        
        return ans;
    }
};
*/