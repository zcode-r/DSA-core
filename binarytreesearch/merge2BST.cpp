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

Node* insert(Node* root,int val){
    if(root==NULL){
        return new Node(val);
    }

    if(val<root->val){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }

    return root;
}

Node* buildbst(vector<int>vec){
    
    Node* root=NULL;

    for(int i:vec){
        root=insert(root,i);
    }

    return root;
}

void inorder(Node* root,vector<int>&a){
    if(root==NULL){
        return;
    }

    inorder(root->left,a);
    a.push_back(root->val);
    inorder(root->right,a);
}

Node* balanced(vector<int>arr,int st,int ed){
    if(st>ed){
        return NULL;
    }

    int mid=st+(ed-st)/2;

    Node* root=new Node(arr[mid]);

    root->left=balanced(arr,st,mid-1);
    root->right=balanced(arr,mid+1,ed);

    return root;
}

Node* merge(Node* root1,Node* root2){
    vector<int>a1,a2;
    inorder(root1,a1);
    inorder(root2,a2);

    vector<int>res;
    int i=0,j=0;

    while(i<a1.size() && j<a2.size()){
        if(a1[i]<a2[j]){
            res.push_back(a1[i++]);
        }
        else{
            res.push_back(a2[j++]);
        }
    }

    while(i<a1.size()) res.push_back(a1[i++]);
    while(j<a2.size()) res.push_back(a2[j++]);

    return balanced(res,0,res.size()-1);
}

int main(){

    vector<int>vec1{8,2,1,10};
    vector<int>vec2{5,3,0};

    Node* root1=buildbst(vec1);
    Node* root2=buildbst(vec2);

    Node* root=merge(root1,root2);

    vector<int>ans;
    inorder(root,ans);

    for(int i:ans) cout << i << " ";
} 