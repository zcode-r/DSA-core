//DFS

/*
class Solution {
public:

    bool dfs(vector<vector<int>>&g,vector<int>&vis,int cur,int newcur){
        vis[cur]=newcur;

        for(int v:g[cur]){
            if(vis[v]==vis[cur]){
                return false;
            }
            else if(vis[v]==-1){
                int n=1-vis[cur];

                if(!dfs(g,vis,v,n)){
                    return false;
                }
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>g(n+1);

        for(auto &i:dislikes){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }

        vector<int>vis(n+1,-1);

        for(int i=1; i<=n; ++i){
            if(vis[i]==-1){
                if(!dfs(g,vis,i,1)){
                    return false;
                }
            }
        }

        return true;
    }
};


///////////////////////////////////////////////////////////////////////////////////

//BFS

class Solution {
public:

    bool bfs(vector<vector<int>>&graph,int cur,vector<int>&col,int colour){

        queue<int>q;
        q.push(cur);
        col[cur]=colour;

        while(!q.empty()){
            int c=q.front();
            q.pop();

            for(int v:graph[c]){
                if(col[v]==col[c]){
                    return false;
                }
                else if(col[v]==-1){
                    col[v]=1-col[c];
                    q.push(v);
                }
            }

        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>col(n,-1);

        for(int i=0; i<n; ++i){
            if(col[i]==-1){
                if(!bfs(graph,i,col,1)){
                    return false;
                }
            }
        }

        return true;
    }
};

*/