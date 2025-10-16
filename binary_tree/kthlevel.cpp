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

void kthlevel(Node* root,int k){

    if(root==NULL) return;
    
    if(k==1){
        cout << root->val << " ";
        return;
    }
    kthlevel(root->left,k-1);
    kthlevel(root->right,k-1);
}

int main(){

    vector<int>vec{1,2,7,-1,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=binarytree(vec);

    kthlevel(root,3);

} 
