#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){

    vector<int>a{15,-2,2,-8,1,7,10,23};
    unordered_map<int,int>m;
    int prefixsum=0;
    int maxlen=INT_MIN;

    for(int i=0; i<a.size(); ++i){

        prefixsum+=a[i];

        if(m.find(prefixsum)!=m.end()){
            maxlen=max(maxlen,i-m[prefixsum]);
        }
        else{
            m[prefixsum]=i;
        }
    }

    cout << maxlen;

}