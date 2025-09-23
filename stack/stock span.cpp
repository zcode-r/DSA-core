#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){

    vector<int> v{100,80,60,70,60,75,85};

    vector<int>ans(v.size(),0);
    stack<int>s;

    for(int i=0; i<v.size(); ++i){

        while(s.size()>0 && v[s.top()]<=v[i]){
            s.pop();
        }

        if(s.empty()){
            ans[i]=i+1;
        }
        else{
            ans[i]=i-s.top();
        }

        s.push(i);
    }

    for(auto i:ans){
        cout << i << " ";
    }

}
/*
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class StockSpanner {
    stack<pair<int,int>> st; // {price, span}
public:

   StockSpanner() {}

    int next(int price) {
        int span = 1;

        while(!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});
        return span;
    }
};

int main(){

    StockSpanner s;

    cout << s.next(100) << " ";
    cout << s.next(80) << " ";
    cout << s.next(60) << " ";
    cout << s.next(70) << " ";
    cout << s.next(60) << " ";
    cout << s.next(75) << " ";
    cout << s.next(85) << " ";
}
*/