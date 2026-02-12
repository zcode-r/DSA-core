#include <iostream>
#include <list>
#include <vector>
#include <stack>
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

        void topo(int u,vector<bool>&vis,stack<int>&s){
            vis[u]=true;

            for(int v:l[u]){
                if(!vis[v]){
                    topo(v,vis,s);
                }
            }

            s.push(u);
        }

        void toposort(){
            vector<bool>vis(V,false);
            stack<int>s;

            for(int i=0; i<V; ++i){
                if(!vis[i]){
                    topo(i,vis,s);
                }
            }

            while(!s.empty()){
                cout << s.top() << " ";
                s.pop();
            }
        }
};

int main(){
    Graph g(6);

    g.addedge(3,1);
    g.addedge(2,3);
    g.addedge(4,0);
    g.addedge(4,1);
    g.addedge(5,0);
    g.addedge(5,3);

    g.toposort();
}