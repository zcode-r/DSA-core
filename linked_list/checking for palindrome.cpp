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

bool palindrome(N* h){

    N* s=h;
    N* f=h;

    //to find middle
    while(f!=NULL && f->adr!=NULL){
        s=s->adr;
        f=f->adr->adr;
    }

    N* cur=s->adr;
    N* prv=s;
    s->adr=NULL;

    //to reverse the second half of the list
    while(cur!=NULL){
        N* nxt=cur->adr;

        cur->adr=prv;
        prv=cur;
        cur=nxt;
        
    }

    N* h1=h;
    N* h2=prv;

    while(h2!=NULL){
        if(h1->d!=h2->d){
            return false;
        }

        h1=h1->adr;
        h2=h2->adr;
    }

    return true;

}

int main(){

    Ll l1,l2;

    l1.insert(1);
    l1.insert(2);
    //l1.insert(3);
    l1.insert(2);
    l1.insert(1);

    cout << palindrome(l1.head);
}