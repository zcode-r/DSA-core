#include <iostream>
#include <algorithm>
#include <stack>
#include <sstream>
using namespace std;

string simplepath(string s){
    stack<string>st;
    stringstream ss(s);
    string str;

    while(getline(ss,str,'/')){

        if(str=="" || str==".") continue;

        if(str==".."){
            if(!st.empty()) st.pop();
        }
        else{
            st.push(str);
        }
    }

    stack<string>temp;
    string ans="";

    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }

    while(!temp.empty()){
        ans+="/"+temp.top();
        temp.pop();
    }

    return ans.empty()?"/":ans;
}

int main() {
    
    string path = "/a/./b/../../c/";

    cout << simplepath(path);
}