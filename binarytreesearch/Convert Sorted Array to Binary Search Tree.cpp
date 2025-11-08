// class Solution {
// public:

// TreeNode* ans(vector<int>arr,int st,int ed){

//     if(st>ed){
//         return NULL;
//     }

//     int mid=st+(ed-st)/2;
//     TreeNode* root=new TreeNode(arr[mid]);

//     root->left=ans(arr,st,mid-1);
//     root->right=ans(arr,mid+1,ed);

//     return root;
// }

//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         return ans(nums,0,nums.size()-1);
//     }
// };