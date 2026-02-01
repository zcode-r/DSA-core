#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph{
    int V;
    list<int>*l;

    public:
        Graph(int V){
            this->V=V;
            l=new list<int> [V];
        }


        void addedge(int u,int v){
            l[u].push_back(v);
            l[v].push_back(u);
        }

        void bfs(){
            queue<int>q;
            vector<int>vis(V,false);

            q.push(0);
            vis[0]=true;

            while(q.size()>0){
                int u=q.front();
                q.pop();

                cout << u << " ";

                for(int v:l[u]){
                    if(!vis[v]){
                        vis[v]=true;
                        q.push(v);
                    }
                }
            }
        }


        void dfshelper(int u,vector<int>&vis){
            cout << u << " ";
            vis[u]=true;

            for(int v:l[u]){
                if(!vis[v]){
                    dfshelper(v,vis);
                }
            }
        }

        void dfs(){
            int u=0;
            vector<int>vis(V,false);

            dfshelper(u,vis);
        }

        

};

int main(){
    Graph g(5);

    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(1,3);
    g.addedge(2,3);
    g.addedge(2,4);

    g.bfs();
}