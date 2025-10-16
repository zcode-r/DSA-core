#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int main(){

    queue<int>q;
    stack<int>s;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    while(!q.empty()){
        s.push(q.front());
        cout << q.front() << " ";
        q.pop();
    }

    cout << "\n";

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}