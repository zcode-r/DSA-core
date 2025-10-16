// class Solution {
// public:
//     int widthOfBinaryTree(TreeNode* root) {
//         queue<pair<TreeNode*,unsigned long long>>q;
//         q.push({root,0});
//         int width=0;

//         while(q.size()>0){
//             int cursize=q.size();
//             unsigned long long stidx=q.front().second;
//             unsigned long long edidx=q.back().second;

//             width=max(width,(int)(edidx-stidx+1));

//             for(int i=0; i<cursize; ++i){
//                 auto cur=q.front();
//                 q.pop();

//                 if(cur.first->left){
//                     q.push({cur.first->left,cur.second*2+1});
//                 }

//                 if(cur.first->right){
//                     q.push({cur.first->right,cur.second*2+2});
//                 }
//             }
//         }
        
//         return width;
//     }
// };