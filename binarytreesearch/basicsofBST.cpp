#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val=val;
        left=right=NULL;
    }
};

Node* insert(Node* root,int i){

    if(root==NULL){
        return new Node(i);
    }

    if(i<root->val){
        root->left=insert(root->left,i);
    }
    else{
        root->right=insert(root->right,i);
    }

    return root;
}

Node* builtbst(vector<int>arr){

    Node* root=NULL;

    for(int i:arr){
        root=insert(root,i);
    }

    return root;
}

bool search(Node* root,int key){
    if(root==NULL){
        return false;
    }
    if(root->val==key){
        return true;
    }

    if(key<root->val){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}

void inorder(Node* root){

    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
    
}

Node* getnextgreaterele(Node* root){    //left most node in the right subtree
    while(root!=NULL && root->left!=NULL){
        root=root->left;
    }

    return root;
}

Node* deletenode(Node* root,int key){

    if(root==NULL){
        return NULL;
    }

    if(key<root->val){
        root->left=deletenode(root->left,key);
    }
    else if(key>root->val){
        root->right=deletenode(root->right,key);
    }
    else{
        if(root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else{
            Node* IS=getnextgreaterele(root->right);
            root->val=IS->val;
            root->right=deletenode(root->right,IS->val);
        }
    }

    return root;
}

int main(){

    vector<int>vec{3,2,1,5,6,4};

    Node* root=builtbst(vec);

    // inorder(root);

    // cout << search(root,34);

    deletenode(root,2);

    inorder(root);
} 
