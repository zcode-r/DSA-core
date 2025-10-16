//BASICS OF QUEUE

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;


int main(){

    //queue<int>q; // first in first out (uses front function)

   priority_queue<int>q; //uses top function (it will be sorted according to the priority of the element (largest))

   //priority_queue<int, vector<int>, greater<int>>q;  used for sorted queue


    q.push(2);
    q.push(4);
    q.push(8);

    while(!q.empty()){
        cout << q.top() << " ";
        q.pop();
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////

//IMPLEMENTING QUEUE USING LL

#include <iostream>
#include <algorithm>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        next=NULL;
    }
};

class Queue{
    Node* head;
    Node* tail;

public:
    Queue(){
        head=tail=NULL;
    }

    void push(int val){
        Node* node=new Node(val);
        if(empty()){
            head=tail=node;
        }
        else{
            tail->next=node;
            tail=node;
        }
    }

    void pop(){
        if(empty()){
            cout << "ll is empty";
        }

        Node* t=head;
        head=head->next;
        delete t;
    }

    int front(){
        return head->data;
    }

    bool empty(){
        return head==NULL;
    }
};

int main(){

    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}
///////////////////////////////////////////////////////

//DEQUEUE

#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main(){

    deque<int>d;

    d.push_back(1);
    d.push_front(2);
    d.pop_front();
    d.pop_back();

}