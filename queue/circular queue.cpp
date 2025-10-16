#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Circular{
    int *arr;
    int cursize,capacity;
    int front,r;

public:

    Circular(int size){
        capacity=size;
        arr = new int(capacity);
        cursize=0;
        front=0,r=-1;
    }

    void push(int data){
        if(cursize==capacity){
            cout << "queue is full";
            return;
        }

        r=(r+1)%capacity;
        arr[r]=data;
        cursize++;
    }

    void pop(){
        if(empty()){
            cout << "its emtpty";
            return;
        }

        front=(front+1)%capacity;
        cursize--;
    }

    int front(){
        if(empty()){
            cout << "its emtpty";
        }

        return arr[front];
    }

    bool empty(){
        return cursize==0;
    }
};

int main(){
    Circular cq(3);

    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);
}