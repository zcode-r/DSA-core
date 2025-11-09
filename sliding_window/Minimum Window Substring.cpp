
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";

    unordered_map<char,int>win,tar;

    int i=0,j=0;
    int n=s.size();
    int stidx=0;
    int have=0,need=0;
    int ans=INT_MAX;

    for(char c:t)tar[c]++;
    need=tar.size();

    while(j<n){
        char c=s[j];
        win[c]++;

        if(tar.count(s[j]) && tar[s[j]]==win[s[j]]){
            ++have;
        }

        while(have == need){
            if(j-i+1<ans){
                ans=min(ans,j-i+1);
                stidx=i;
            }

            win[s[i]]--;

            if(tar.count(s[i]) && win[s[i]]<tar[s[i]]){
                --have;
            }

            ++i;
        }

        ++j;
    }

    cout << s.substr(stidx,ans);  

}
