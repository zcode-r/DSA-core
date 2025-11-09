
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int>v{2, 3, 5, 2, 9, 7, 1};
    int k=3;
    int m=0;
    int s=0;

    for(int i=0; i<k; ++i){
        s+=v[i];
    }
    m=s;

    for(int i=k; i<v.size()-1; ++i){
        s+=v[i]-v[i-k];
        m=max(m,s);
    }

    cout << m;
}