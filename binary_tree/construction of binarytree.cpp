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

static int i=-1;

Node* binarytree(vector<int> vec){

    ++i;
    if(vec[i]==-1) return NULL;

    Node* root=new Node(vec[i]);

    root->left=binarytree(vec);
    root->right=binarytree(vec);

    return root;
}

int main(){

    vector<int>vec{1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root=binarytree(vec);

    cout << root->data << " " << "\n";
    cout << root->left->data << " " << root->right->data;

}
