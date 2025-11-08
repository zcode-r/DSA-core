#include <iostream>
#include <queue>
#include <map>
#include <vector>
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

void topview(Node* root){

    queue<pair<Node*,int>>q;
    map<int,int>m;
    q.push({root,0});

    while(!q.empty()){
        Node* cur=q.front().first;
        int curHD=q.front().second;

        if(m.find(curHD)==m.end()){
            m[curHD]=cur->val;
        }
        q.pop();

        if(cur->left!=NULL){
            q.push({cur->left,curHD-1});
        }

        if(cur->right!=NULL){
            q.push({cur->right,curHD+1});
        }
    }

    for(auto& i:m){
        cout << i.second << " ";
    }
}

void leftview(Node* root,int l,vector<int>&arr){
    if(!root) return;

    if(l==arr.size()) arr.push_back(root->val);

    leftview(root->left,l+1,arr);
    leftview(root->right,l+1,arr);
}

void rightview(Node* root,int l,vector<int>&arr){
    if(!root) return;

    if(l==arr.size()) arr.push_back(root->val);

    rightview(root->right,l+1,arr);
    rightview(root->left,l+1,arr);
}

void bottomView(Node* root) {

    if(!root) return;

    // map: hd -> node value
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    
    while(!q.empty()) {
        auto p = q.front();
        q.pop();

        Node* node = p.first;
        int hd = p.second;

        mp[hd] = node->val;

        if(node->left) q.push({node->left, hd - 1});
        if(node->right) q.push({node->right, hd + 1});
    }

    for(auto &it : mp) {
        cout << it.second << " ";
    }

}


int main(){

    vector<int>vec{1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=binarytree(vec);

    vector<int>left;
    //leftview(root,0,left);
    //topview(root);
    // rightview(root,0,left);
    bottomView(root);

   // for(int i:left) cout << i << " ";
} 