/*
class Solution {
public:

    bool issame(TreeNode* p,TreeNode* q){
        if(p==NULL || q==NULL){
            return p==q;
        }

        return q->val==p->val && issame(p->left,q->left) && issame(p->right,q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(root==NULL || subRoot==NULL){
            return root==subRoot;
        }
        if(root->val==subRoot->val && issame(root,subRo ot)){
            return true;
        }

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
*/