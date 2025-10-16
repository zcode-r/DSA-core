/*
//1

class Solution {
public:

    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int left=height(root->left);
        int right=height(root->right);

        return max(left,right)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        int left=diameterOfBinaryTree(root->left);
        int right=diameterOfBinaryTree(root->right);
        int cur=height(root->left)+height(root->right);

        return max(cur,max(left,right));
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////

//2

class Solution {
public:

    int ans=0;

    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int left=height(root->left);
        int right=height(root->right);

        ans=max(ans,left+right);

        return max(left,right)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {

        height(root);

        return ans;
    }
};
*/