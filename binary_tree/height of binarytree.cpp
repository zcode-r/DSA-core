#include <iostream>
#include <queue>
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

static int i=-1;

Node* binarytree(vector<int> vec){

    ++i;
    if(vec[i]==-1) return NULL;

    Node* root=new Node(vec[i]);

    root->left=binarytree(vec);
    root->right=binarytree(vec);

    return root;
}


int height(Node* root){

    if(root==NULL) return 0;

    int left=height(root->left);
    int right=height(root->right);

    return (max(left,right)+1);
}

int main(){

    vector<int>vec{1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root=binarytree(vec);

    cout << height(root);
}