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

void sp(N* &h){

    if(h==NULL || h->adr==NULL){
        return;
    }

    N* pre=NULL;
    N* f=h;
    N* s=h->adr;

    while(f!=NULL && s!=NULL){
        N* t=s->adr;

        s->adr=f;
        f->adr=t;

        if(pre==NULL){
            h=s;
        }
        else{
            pre->adr=s;
        }

        pre=f;
        f=t;
        if(t!=NULL){
            s=t->adr;
        }
        else{
            s=NULL;
        }

    }

}

int main(){

    Ll l1;

    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);

    l1.dis();

    cout << "\n";

    sp(l1.head);

    l1.dis();


}

/*
N* sp1(N* &h){

    if(h==NULL || h->adr==NULL){
        return h;
    }

    N* sec=h->adr;
    h->adr=sp1(sec->adr);
    sec->adr=h;
    return sec;

}
*/