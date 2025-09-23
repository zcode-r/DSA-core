//NEXT GREATER ELEMENT 1

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){

    vector<int>a{6,8,0,1,3},ans(a.size(),0);
    stack<int>s;

    for(int i=a.size()-1; i>=0; --i){
        while(s.size()>0 && s.top()<=a[i]){
            s.pop();
        }

        if(s.empty()){
            ans[i]=-1;
        }
        else{
            ans[i]=s.top();
        }

        s.push(a[i]);
    }

    for(int i:ans) cout << i << " ";

}


////////////////////////////////////////////////////////////////////////////////////////////
/*
//NEXT GREATER ELEMENT 2

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
vector<int>v{3,6,5,4,2};
stack<int>s;
int n=v.size();
vector<int>ans(n,0);

for(int i=2*n-1; i>=0; --i){
    while(s.size()>0 && v[s.top()]<=v[i%n]){
        s.pop();
    }

    ans[i%n]=s.empty()?-1:v[s.top()];
    s.push(i%n);
}

for(int i:ans) cout << i << " ";
}

*/

////////////////////////////////////////////////////////////////////////////////////////////

//NEXT GREATER ELEMENT 3
/*
#include <iostream>
#include <algorithm>
using namespace std;

int c(string s){
    int p = -1;

    for(int i = s.size() - 2; i >= 0; --i){
        if(s[i] < s[i+1]){
            p = i;
            break;
        }
    }


    if(p == -1) return -1;

 
    for(int i = s.size() - 1; i > p; --i){
        if(s[i] > s[p]){
            swap(s[i], s[p]);
            break;
        }
    }

    reverse(s.begin() + p + 1, s.end());


    long long ans = stoll(s);  
    if(ans > INT_MAX) return -1; 
    return (int)ans;
}

int main(){
    int n = 21;
    string s = to_string(n);

    cout << c(s);
}

*/