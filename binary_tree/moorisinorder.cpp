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

void morrisinorder(Node* root){

    while(root!=NULL){

        if(root->left==NULL){
            cout << " " << root->data << " ";
            root=root->right;
        }

        else{

            Node* ip=root->left;

            while(ip->right!=NULL && ip->right!=root){
                ip=ip->right;
            }

            if(ip->right==NULL){
                ip->right=root;
                root=root->left;
            }
            else{
                ip->right=NULL;
                cout << " " << root->data << " ";
                root=root->right;
            }
        }
    }
}

int main(){

    vector<int>vec{1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root=binarytree(vec);

    morrisinorder(root);

}