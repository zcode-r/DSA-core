// class Solution {
// public:

//     int pre=0;

//     int kthSmallest(TreeNode* root, int k) {
//         if(root==NULL) return -1;

//         if(root->left){
//             int left=kthSmallest(root->left,k);
//             if(left!=-1){
//                 return left;
//             }
//         }

//         if(pre+1==k){
//             return root->val;
//         }

//         pre+=1;

//         if(root->right){
//             int right=kthSmallest(root->right,k);
//             if(right!=-1){
//                 return right;
//             }
//         }

//         return -1;
//     }
// };