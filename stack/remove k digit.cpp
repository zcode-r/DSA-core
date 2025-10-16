#include <iostream>
#include <stack>
using namespace std;

string smallnum(string num,int k){

        stack<char>st;

        for(char i:num){

            while(!st.empty() && k>0 && st.top()>i){
                st.pop();
                --k;
            }

            st.push(i);
        }

        while(k>0 && !st.empty()){
            st.pop();
            --k;
        }

        string ans="";
        stack<char>temp;

        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }

        while(!temp.empty()){
            ans+=temp.top();
            temp.pop();
        }

        int i=0;

        while(i<ans.size() && ans[i]=='0') ++i;

        ans=ans.substr(i);

        return ans.empty()?"0":ans;
}

int main(){

    string s="1432219";
    int k=3;

    cout << smallnum(s,k);

}