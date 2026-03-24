#include <iostream>
#include <list>
#include <vector>
using namespace std;

class DSU{

    vector<int>par,rank,size;

public:

    DSU(int n){
        par.resize(n);
        rank.resize(n,0);
        size.resize(n,1);

        for(int i=0; i<n; ++i){
            par[i]=i;
            rank[i]=0;
        }
    }

    int find(int x){
        if(par[x]==x){
            return x;
        }

        return par[x]=find(par[x]); //path compression
    }

    // void unite(int a,int b){
    //     int x=find(a);
    //     int y=find(b);

    //     if(x!=y){
    //         par[y]=x;
    //     }
    // }

    //IF FIND(X)==FIND(Y) THEN THERE IS A CYCLE IN THE IT

    // void unite(int a,int b){
    //     int x=find(a);
    //     int y=find(b);

    //     if(x==y) return;

    //     if(rank[x]>rank[y]){
    //         par[y]=x;
    //     }
    //     else if(rank[y]>rank[x]){
    //         par[x]=y;
    //     }
    //     else{
    //         par[x]=y;
    //         rank[y]+=1;
    //     }
    // }

        void unite(int a,int b){
        int x=find(a);
        int y=find(b);

        if(x==y) return;

        if(size[x]>size[y]){
            par[y]=x;
            size[x]+=size[y];
        }
        else if(size[y]>size[x]){
            par[x]=y;
            size[y]+=size[x];
        }
        else{
            par[x]=y;
            size[y]+=size[x];

        }
    }
};

int main(){
    DSU dsu(6);

    dsu.unite(1,2);
    dsu.unite(1,3);
    dsu.unite(3,4);
    dsu.unite(0,5);

    cout << dsu.find(5);
}