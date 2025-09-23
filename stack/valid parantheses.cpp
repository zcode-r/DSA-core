#include <iostream>
#include <stack>
using namespace std;

bool b(string &s){

    if(s.size()%2==1) return false;

    stack<char> st;

    for(char i:s){
        if(i=='(' || i=='[' || i=='{'){
            st.push(i);
        }
        else{
            if(st.size()==0) return false;

            if((st.top()=='(' && i==')') || (st.top()=='{' && i=='}') || (st.top()=='[' && i==']')){
                st.pop();
            }
            else{
                return false;
            }
        
        }
    }

    

    return (st.size()==0);
}

int main(){

    string str="()]]";

    cout << b(str);

}