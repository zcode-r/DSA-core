
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string txt = "forxxorfxdofr";
    string pat = "for";

    unordered_map<char,int> mp1, mp2;
    int k = pat.size();
    int c = 0;

    for (char ch : pat) mp2[ch]++;

    for (int i = 0; i < txt.size(); ++i) {
        mp1[txt[i]]++;

        if (i >= k) {
            mp1[txt[i - k]]--;
            if (mp1[txt[i - k]] == 0)
                mp1.erase(txt[i - k]);
        }

        if (i >= k - 1 && mp1 == mp2)
            ++c;
    }

    cout << c;
}