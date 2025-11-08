// class Solution {
// public:
//     int maxFrequency(vector<int>& nums, int k, int numOperations) {
//         int maxel=*max_element(begin(nums),end(nums))+k;

//         vector<int>fre(maxel+1,0);

//     //for frequency
//         for(int i:nums){
//             fre[i]++;
//         }

//     //prefix sum
//         for(int i=1; i<=maxel; ++i){
//             fre[i]+=fre[i-1];
//         }

//         int res=0;

//         for(int i=0; i<=maxel; ++i){
//             if(fre[i]==0){
//                 continue;
//             }

//             int l=max(0,i-k);
//             int r=min(maxel,i+k);

//             int totalcount=fre[r]-(l>0?fre[l-1]:0);

//             int targetcount=fre[i]-fre[i-1];

//             int needconvertions=totalcount-targetcount;

//             int maxpossiblefre=targetcount+min(needconvertions,numOperations);

//             res=max(res,maxpossiblefre);
//         }

//         return res;
//     }
// };

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class Solution {
// public:
//     int maxFrequency(vector<int>& nums, int k, int numOperations) {

//         int maxel=*max_element(begin(nums),end(nums))+k;
//         map<int,int>diff;
//         unordered_map<int,int>fre;

//         for(int i=0; i<nums.size(); ++i){
//             fre[nums[i]]++;

//             int l=max(nums[i]-k,0);
//             int r=min(nums[i]+k,maxel);

//             diff[l]++;
//             diff[r+1]--;

//             diff[nums[i]]+=0;
//         }

//         int res=1;
//         int presum=0;

//         for(auto it=diff.begin(); it!=diff.end(); ++it){

//             int t=it->first;

//             it->second+=presum;

//             int targetcount =fre[t];

//             int needconverstion=it->second-targetcount;

//             int maxpossibel=min(needconverstion,numOperations);

//             res=max(res,targetcount+maxpossibel);

//             presum=it->second;
//         }

//         return res;
//     }
// };