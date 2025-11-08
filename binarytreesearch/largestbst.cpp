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

class Info{
public:
    int min,max,size;

    Info(int min,int max,int size){
        this->max=max;
        this->min=min;
        this->size=size;
    }
};

Info helper(Node* root){
    if(root==NULL){
        return Info(INT_MAX,INT_MIN,0);
    }

    Info left=helper(root->left);
    Info right=helper(root->right);

    if(root->val > left.max && root->val < right.min){
        int curmin=min(root->val,left.min);
        int curmax=max(root->val,right.max);
        int siz=left.size+right.size+1;

        return Info(curmin,curmax,siz);
    }

    return Info(INT_MIN,INT_MAX,max(left.size,right.size));
}

int largestBST(Node* root){
    Info info=helper(root);
    return info.size;
}

int main(){

    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(15);
    root->left->left=new Node(1);
    root->left->right=new Node(8);
    root->right->right=new Node(7);

    cout << largestBST(root);
} 
