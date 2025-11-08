#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        left=right=NULL;
    }

};

Node* insert(Node* root,int i){
    if(root==NULL){
        return new Node(i);
    }

    if(root->data<i){
        root->right=insert(root->right,i);
    }
    else{
        root->left=insert(root->left,i);
    }

    return root;
}

Node* buildbst(vector<int>&v){

    Node* root=NULL;

    for(int i:v){
        root=insert(root,i);
    }

    return root;
}

Node* rightmostvalueleft(Node* root){
    Node* ans;

    while(root!=NULL){
        ans=root;
        root=root->right;
    }

    return ans;
}

Node* leftmostvalueright(Node* root){
    Node* ans;

    while(root!=NULL){
        ans=root;
        root=root->left;
    }

    return ans;
}

vector<int> getpresuc(Node* root,int k){
    Node* cur=root;
    Node* pre=NULL;
    Node* suc=NULL;

    while(cur!=NULL){
        if(k<cur->data){
            suc=cur;
            cur=cur->left;
        }
        else if(k>cur->data){
            pre=cur;
            cur=cur->right;
        }
        else{

            if(cur->left!=NULL){
                pre=rightmostvalueleft(cur->left);
            }

            if(cur->right!=NULL){
                suc=leftmostvalueright(cur->right);
            }

            break;
        }
    }

    return {pre->data,suc->data};
}

int main(){

    vector<int>a={3,2,1,5,6,4};

    Node* root=buildbst(a);

    vector<int>ans=getpresuc(root,3);

    cout << ans[0] << " " << ans[1];
}