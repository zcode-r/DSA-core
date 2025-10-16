#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;


int main(){

    string s="level";
    unordered_map<char,int>m;
    queue<int>q;

    for(int i=0; i<s.size(); ++i){
        if(m.find(s[i])==m.end()){
            q.push(i);
        }

        m[s[i]]++;

        while(q.size()>0 && m[s[q.front()]]>1){
            q.pop();
        }
    }

    if(q.empty()){
        cout << -1;
    }
    else{
        cout << q.front();
    }
 
}
