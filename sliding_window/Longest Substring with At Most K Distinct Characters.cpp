
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    string s = "aaabb";
    unordered_map<char,int> mp;

    int i = 0, j = 0;
    int m = 0, k = 2;

    while (j < s.size()) {
        mp[s[j]]++;

        while (mp.size() > k) {
            mp[s[i]]--;
            if (mp[s[i]] == 0) {
                mp.erase(s[i]);
            }
            ++i;
        }

        m = max(m, j - i + 1);
        ++j;
    }

    cout << m << " " << s.size();
}