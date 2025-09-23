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

N* rotate(N* &h,int k){

    N* temp=h;
    int c=1;

    while(temp->adr!=NULL){
        temp=temp->adr;
        ++c;
    }
    k%=c;

    temp->adr=h;

    int a=c-k;c=1;

    while(c!=a){
        h=h->adr;
        ++c;
    }

    N* n=h->adr;
    h->adr=NULL;

    return n;

}

int main(){

    Ll l1,l2;

    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);

    l1.dis();

    cout << "\n";

    l2.head=rotate(l1.head,3);

    l2.dis();

}