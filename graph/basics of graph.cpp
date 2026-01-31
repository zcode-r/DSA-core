#include <iostream>
#include <list>
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
        
        void print(){
            for(int i=0; i<V; ++i){
                cout << i << ":";
                for(int j:l[i]){
                    cout << j << " ";
                }
                cout << "\n";
            }
        }
};

int main(){
    Graph g(5);

    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(1,3);
    g.addedge(2,3);
    g.addedge(2,4);

    g.print();

}