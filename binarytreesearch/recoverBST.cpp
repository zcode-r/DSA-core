// class Solution {
// public:

//     TreeNode* pre=NULL;
//     TreeNode* first=NULL;
//     TreeNode* second=NULL;

//     void inorder(TreeNode* root){
//         if(root==NULL) return;

//         inorder(root->left);

//         if(pre!=NULL && root->val<pre->val){
//             if(first==NULL){
//                 first=pre;
//             }
//             second=root;
//         }

//         pre=root;

//         inorder(root->right);
//     }

//     void recoverTree(TreeNode* root) {
//         inorder(root);

//         int temp=first->val;
//         first->val=second->val;
//         second->val=temp;
//     }
// };