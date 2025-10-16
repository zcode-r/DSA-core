/*

class LRUCache {
public:

    class Node{
    public:

        int key,val;
        Node* next;
        Node* pre;

        Node(int key,int val){
            this->key=key;
            this->val=val;

            pre=next=nullptr;
        }
    };

    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);

    unordered_map<int,Node*>m;

    int limit;

    void addnode(Node* newnode){
        Node* oldnext=head->next;

        head->next=newnode;
        oldnext->pre=newnode;

        newnode->next=oldnext;
        newnode->pre=head;
    }

    void delnode(Node* oldnode){
        Node* oldpre=oldnode->pre;
        Node* oldnext=oldnode->next;

        oldnext->pre=oldpre;
        oldpre->next=oldnext;
    }

    LRUCache(int capacity) {
        limit=capacity;
        head->next=tail;
        tail->pre=head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }

        Node* ansnode=m[key];
        int ans=ansnode->val;

        m.erase(key);
        delnode(ansnode);

        addnode(ansnode);
        m[key]=ansnode;

        return ansnode->val;
    }
    
    void put(int key, int value) {

        if(m.find(key)!=m.end()){
            Node* oldnode=m[key];
            delnode(oldnode);
            m.erase(key);
        }

        if(m.size()==limit){
            m.erase(tail->pre->key);
            delnode(tail->pre);
        }

        Node* newnode=new Node(key,value);

        addnode(newnode);
        m[key]=newnode;
    }
};

*/