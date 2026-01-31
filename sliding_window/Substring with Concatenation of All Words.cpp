#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    string s="abarfoothefoobarman";
    vector<string>a{"foo","bar"};

    int wordlen=a[0].size();
    int wordcount=a.size();
    unordered_map<string,int>have;
    vector<int>ans;

    for(string s:a) have[s]++;

    for(int i=0; i<wordlen; ++i){

        int left=i,right=i;
        int count=0;
        unordered_map<string,int>seen;

        while(right+wordlen<=s.size()){
            string w=s.substr(right,wordlen);
            right+=wordlen;

            if(have.find(w)!=have.end()){
                seen[w]++;
                ++count;

                while(seen[w]>have[w]){
                    string lef=s.substr(left,wordlen);
                    seen[lef]--;
                    left+=wordlen;
                    --count;
                }

                if(count==wordcount){
                    ans.push_back(left);
                }

            }
            else{
                count=0;
                seen.clear();
                left=right;
            }
        }
    }

    for(int i:ans) cout << i << " ";
}
