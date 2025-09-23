#include <iostream>
using namespace std;

class N{
    public:
    int d;
    N* adr;

    N(int d){
        this->d=d;
        adr=NULL;
    }
};

class Ll{
    public:
    N* head;

    Ll(){
        head=NULL;
    }

    void insert(int v){
        N* node=new N(v);

        if(head==NULL){
            head=node;
            return;
        }

        N* t=head;

        while(t->adr!=NULL){
            t=t->adr;
        }

        t->adr=node;
    }

    void dis(){

        N* t=head;

        while(t!=NULL){
            cout << t->d << " ";
            t=t->adr;
        }
    }
};

int len(N* h){

    int c=0;
    while(h!=NULL){
        h=h->adr;
        ++c;
    }

    return c;
}

 N* intersection(N* h1,N* h2){
    N* p1=h1;
    N* p2=h2;

    int len1=len(h1);
    int len2=len(h2);

    if(len1>len2){
        int k=len1-len2;

        while(k--){
            p1=p1->adr;
        }

    }
    else{
        int k=len2-len1;

        while(k--){
            p2=p2->adr;
        }

    }

    while(p1!=NULL && p2!=NULL){
        if(p1==p2){
            return p1;
        }
        p1=p1->adr;
        p2=p2->adr;
    }

    return NULL;

}

int main(){

    Ll l1,l2;

    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);

    l2.insert(6);
    l2.insert(7);
    
    l2.head->adr->adr=l1.head->adr->adr;

    cout << intersection(l1.head,l2.head);

}