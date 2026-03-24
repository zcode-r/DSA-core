//Build a adjacency list (Graph)
//Build indegree and outdegree
//Find the startnode of eulerpath

/*

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        
        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>indeg,outdeg;

        for(auto &e:pairs){

            int u=e[0];
            int v=e[1];

            adj[u].push_back(v);

            outdeg[u]++;
            indeg[v]++;
        }

        int start=pairs[0][0];

        for(auto &e:adj){

            int node=e.first;

            if(outdeg[node]-indeg[node]==1){
                start=node;
                break;
            }
        }

        vector<int>ans;
        stack<int>st;
        
        st.push(start);

        while(!st.empty()){
            int cur=st.top();

            if(!adj[cur].empty()){
                int next=adj[cur].back();
                adj[cur].pop_back();
                st.push(next);
            }
            else{
                ans.push_back(cur);
                st.pop();
            }
        }

        reverse(begin(ans),end(ans));

        vector<vector<int>>res;

        for(int i=1; i<ans.size(); ++i){
            res.push_back({ans[i-1],ans[i]});
        }

        return res;

        
    }
};

*/