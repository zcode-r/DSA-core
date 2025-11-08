#include <iostream>
#include <vector>
using namespace std;


void sum(vector<int>&a,int n){

    if(n==0 || n==1){
        return;
    }

    for(int i=0; i<n-1; ++i){
        if(a[i]>a[i+1]){
            swap(a[i],a[i+1]);
        }
    }

    sum(a,n-1);
}

int main(){


    vector<int>a{3,4,1,5,2};
    sum(a,a.size());
    for(int i:a) cout << i << " ";


}