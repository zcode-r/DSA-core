#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int>v{12, -1, -7, 8, -15, 30, 16, 28};
    int k=3;
    vector<int>ans;
    deque<int>dq;

    int i=0,j=0;
    int n=v.size();

    while(j<n){

        if(v[j]<0){
            dq.push_back(j);
        }

        if(j-i+1<k){
            ++j;
        }
        else if(j-i+1==k){
            
            if(!dq.empty()){
                ans.push_back(v[dq.front()]);
            }
            else{
                ans.push_back(0);
            }

            if(!dq.empty() && dq.front()==i){
                dq.pop_front();
            }
            ++i,++j;
        }
    }

    for(int i:ans) cout << i << " ";
}
