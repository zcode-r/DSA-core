#include <iostream>
#include <cstdlib>
using namespace std;

class N{
    public:
    int d;
    N* next;
    N* pre;

    N(int d){
        this->d=d;
        next=pre=NULL;
    }
};

class Dl{
    public:

    N* head;
    N* tail;


    Dl(){
        head=tail=NULL;
    }

    void push_front(int val){
        N* node=new N(val);

        if(head==NULL){
            head=tail=node;
            return;
        }
        else{
            node->next=head;
            head->pre=node;
            head=node;
        }
    }

    void push_back(int val){
        N* node=new N(val);

        if(head==NULL){
            head=tail=node;
            return;
        }
        // else{
        //     N* t=head;

        //     while(t->next!=NULL){
        //         t=t->next;
        //     }

        //     t->next=node;
        //     node->pre=t;
        // }
        else{
            node->pre=tail;
            tail->next=node;
            tail=node;
        }
    }

    void pop_front(){

        if(head==NULL){
            return;
        }

        N* t=head;
        head=t->next;

        if(head!=NULL){
            head->pre=NULL;
        }

        t->next=NULL;
        delete t;
    }

    void pop_back(){

        if(head==NULL){
            return;
        }

        N* t=tail;
        tail=tail->pre;//new tail

        // if(head==NULL){
        //     return;
        // }

        // while(t->next!=NULL){
        //     t=t->next;
        // }

        // t->pre->next=NULL;
        // t->pre=NULL;

        if(head!=NULL){
            tail->next=NULL;
        }

        t->pre=NULL;
        delete t;

    }

    void insert(int val,int k){
        N* node=new N(val);
        int c=0;

        if(k==0){
            push_front(val);
            return;
        }

        N* t=head;
        
        while(c!=k-1){
            t=t->next;
            ++c;
        }

        N* n=t->next;
        t->next=node;
        node->pre=t;
        node->next=n;
    }

    void del(int k){

        if(k==0){
            pop_front();
            return;
        }

        N* t=head;
        int c=0;

        while(c!=k){
            t=t->next;
            ++c;
        }

        if(t->next==NULL){
            pop_back();
            return;
        }

        N* prv=t->pre;
        prv->next=t->next;
        t->next->pre=prv;
        t->next=t->pre=NULL;

        delete t;
    }

    void dis(){

        N* t=head;

        while(t!=NULL){
            cout << t->d << " ";
            t=t->next;
        }
    }

    void reverse(N* &h,N* &t){
        N* cur=h;

        while(cur){
            N* n=cur->next;
            cur->next=cur->pre;
            cur->pre=n;
            cur=n;
        }

        N* swp=t;
        t=h;
        h=swp;
    }
};

int main(){

Dl dl;

// dl.push_front(1);
// dl.push_front(2);
// dl.push_front(3);

dl.push_back(1);
dl.push_back(2);
dl.push_back(3);
dl.push_back(4);


dl.dis();

// dl.insert(5,0);
//dl.del(3);
dl.reverse(dl.head,dl.tail);

cout << "\n";

dl.dis();

}