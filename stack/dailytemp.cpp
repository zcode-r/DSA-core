#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;


vector<int> dailyTemperatures(vector<int>& T) {
    int n = T.size();
    stack<int>s;
    vector<int> ans(n, 0);

    for(int i=0; i<n; ++i){

        while(s.size()>0 && T[i]>T[s.top()]){
            ans[s.top()]=i-s.top();
            s.pop();
        }

        s.push(i);
    }
    return ans;
}

int main() {
    vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = dailyTemperatures(T);

    for(int x : ans) cout << x << " ";
    return 0;
}