#include <iostream>
#include <queue>
#include <vector>
#include <stack>
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

static int i=-1;

Node* binarytree(vector<int>v){

    ++i;

    if(v[i]==-1) return NULL;

    Node* root=new Node(v[i]);

    root->left=binarytree(v);
    root->right=binarytree(v);

    return root;
}

int sumtree(Node* root){
    if(root==NULL) return 0;

    int left=sumtree(root->left);
    int right=sumtree(root->right);
    root->val=root->val+left+right;

    return root->val;

}

void preorder(Node* root){

    if(root==NULL) return;

    cout << root->val << " ";

    preorder(root->left);
    preorder(root->right);

}

int main(){

    vector<int>vec{1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=binarytree(vec);
    vector<vector<int>>ans;

    preorder(root);
    cout << "\n";
    sumtree(root);
    preorder(root);

} 