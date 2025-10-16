#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

int main(){

    vector<int>v{1,3,-1,-3,5,3,6,7},ans;
    deque<int>dq;
    int k=3,n=v.size();

    for(int i=0; i<k; ++i){

        while(dq.size()>0 && v[dq.back()]<=v[i]){
            dq.pop_back();
        }

        dq.push_back(i);
    }

    for(int i=k; i<n; ++i){

        ans.push_back(v[dq.front()]);

        //checking for current window
        while(dq.size()>0 && dq.front()<=i-k){
            dq.pop_front();
        }

        //removing the smaller values form the window 
        while(dq.size()>0 && v[dq.back()]<=v[i]){
            dq.pop_back();
        }

        dq.push_back(i);
    }

    ans.push_back(v[dq.front()]);

    for(int i:ans) cout << i << " ";

}