#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;

    public: 
        Graph(int V){
            this->V=V;
            l=new list<int> [V];
        }

        void addedge(int u,int v){
            l[u].push_back(v);
        }

        void topo(){
            vector<int>ans;

            vector<int>vis(V,0);

            for(int i=0; i<V; ++i){
                for(int v:l[i]){
                    vis[v]++;
                }
            }

            queue<int>q;

            for(int i=0; i<V; ++i){
                if(vis[i]==0){
                    q.push(i);
                }
            }

            while(q.size()>0){
                int cur=q.front();
                q.pop();
                ans.push_back(cur);

                for(int i:l[cur]){
                    vis[i]--;

                    if(vis[i]==0){
                        q.push(i);
                    }
                }

            }

            for(int i:ans) cout << i << " ";
        }


};

int main(){
    Graph g(6);

    g.addedge(3,1);
    g.addedge(2,3);
    g.addedge(4,0);
    g.addedge(4,1);
    g.addedge(5,0);
    g.addedge(5,2);

    g.topo();
}