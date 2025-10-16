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


int sumofnodes(Node* root){

    if(root==NULL) return 0;

    int leftnode=sumofnodes(root->left);
    int rightnode=sumofnodes(root->right);

    return leftnode+rightnode+root->data;
}

int main(){

    vector<int>vec{1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root=binarytree(vec);

    cout << sumofnodes(root);
}
