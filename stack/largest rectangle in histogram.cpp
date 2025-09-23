/*
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>r(n,0);
        vector<int>l(n,0);
        stack<int>s;

        for(int i=n-1; i>=0; --i){
            while(s.size()>0 && heights[s.top()]>=heights[i]){
                s.pop();
            }

            r[i]=s.empty()?n:s.top();
            s.push(i);
        }

        while(!s.empty()){
            s.pop();
        }

        for(int i=0; i<n; ++i){
            while(s.size()>0 && heights[s.top()]>=heights[i]){
                s.pop();
            }

            l[i]=s.empty()?-1:s.top();
            s.push(i);
        }

        int ans=0;

        for(int i=0; i<n; ++i){
            int w=r[i]-l[i]-1;
            int a=heights[i]*w;
            ans=max(ans,a);
        }

        return ans;
    }
};
*/