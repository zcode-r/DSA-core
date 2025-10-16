/*
//DFS(DEPTH FIRST SEARCH)


//PREORDER -> ROOT LEFT RIGHT

void preorder(Node* root){

    if(root==NULL) return;

    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//INORDER -> LEFT ROOT RIGHT

void inorder(Node* root){

    if(root==NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//POSTORDER -> LEFT RIGHT ROOT

void postorder(Node* root){

    if(root==NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//BFS(BREADTH FIRST SEARCH)

//LEVELORDER

void levelorder(Node* root){

    queue<Node*>q;

    q.push(root);
    //q.push(NULL);

    while(!q.empty()){

        Node* cur=q.front();
        q.pop();

        // if(cur==NULL){
        //     if(!q.empty()){
        //         cout << "\n";
        //         q.push(NULL);
        //         continue;
        //     }
        //     else{
        //         break;
        //     }

        // }

        cout << cur->data << " ";

        if(cur->left!=NULL){
            q.push(cur->left);
        }

        if(cur->right!=NULL){
            q.push(cur->right);
        }
    }
}
    
*/