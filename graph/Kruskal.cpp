/*

class Solution {
  public:
  
    vector<int>par,rank;
  
      int find(int x){
        if(par[x]==x){
            return x;
        }

        return par[x]=find(par[x]); 
    }

    void unite(int a,int b){
        int x=find(a);
        int y=find(b);

        if(x==y) return;

        if(rank[x]>rank[y]){
            par[y]=x;
        }
        else if(rank[y]>rank[x]){
            par[x]=y;
        }
        else{
            par[x]=y;
            rank[y]+=1;
        }
    }
  
    int Kruskal(vector<vector<int>>&arr){
        
        int sum=0;
        
        for(auto &e:arr){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            
            int parent_u=find(u);
            int parent_v=find(v);
            
            if(parent_u!=parent_v){
                unite(u,v);
                sum+=wt;
            }
        }
        
        return sum;
    }
  
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        
        auto compare=[&](vector<int>&v1,vector<int>&v2){
            return v1[2]<v2[2];
        };
        
        sort(begin(edges),end(edges),compare);
        
        par.resize(V);
        rank.resize(V,0);
        
        for(int i=0; i<V; ++i) par[i]=i;
        
        return Kruskal(edges);
    }
};

*/