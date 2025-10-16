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

static int i=-1;

Node* binarytree(vector<int>v){

    ++i;

    if(v[i]==-1) return NULL;

    Node* root=new Node(v[i]);

    root->left=binarytree(v);
    root->right=binarytree(v);

    return root;
}

void Path(Node* root,vector<string>&ans,string path){
    if(root->left==NULL && root->right==NULL){
        ans.push_back(path);
        return;
    }

    if(root->left){
        Path(root->left,ans,path+"->"+to_string(root->left->val));
    }

    if(root->right){
        Path(root->right,ans,path+"->"+to_string(root->right->val));
    }
}




int main(){

    vector<int>vec{1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=binarytree(vec);
    vector<string>ans;

    string path=to_string(root->val);

    Path(root,ans,path);

    for(string i:ans) cout << i << " " << "\n";

} 