#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

int main(){

    vector<int>v{1,3,-1,-3,5,3,6,7};
    deque<int>dq;
    vector<int>ans;
    int k=4;

    for(int i=0; i<v.size(); ++i){

        while(!dq.empty() && v[dq.back()]<v[i]){
            dq.pop_back();
        }

        dq.push_back(i);

        if(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }

        if(!dq.empty() && i>=k-1){
            ans.push_back(v[dq.front()]);
        }
    }

    for(int i:ans) cout << i << " ";
}