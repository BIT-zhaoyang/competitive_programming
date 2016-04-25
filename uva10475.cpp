#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <climits>
#include <cmath>
#include <set>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <cctype>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

int t, p, s;
vector<string> topic;
map<string, int> compress;
map<int, int> prohibts;
vector<int> ans;

bool myComp(string &a, string &b){
    if(a.size() != b.size())    return a.size() > b.size();
    else    return a < b;
}

void output(){
    int idx;
    for(int i = 0; i < ans.size()-1; ++i){
        idx = ans[i];
        cout << topic[idx] << " ";
    }
    idx = ans.back();
    cout << topic[idx] << endl;
}

void recurse(int idx, int mask){
    if(ans.size() == s){
        output();
        return;
    }

    for(int i = idx+1; i < t; ++i){
        if(mask & (1 << i)) continue;   // if prohibted, continue
        else{
            ans.push_back(i);
            recurse(i, (mask|prohibts[i]) );
            ans.pop_back();
        }
    }
}

int main(){ _
    int TC; cin >> TC;
    for(int count = 1; count <= TC; ++count){
        cout << "Set " << count << ":" << endl;
        cin >> t >> p >> s;

        // read topic
        topic.assign(t, "");
        string tmp;
        for(int i = 0; i < t; ++i){
            cin >> tmp;
            transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);
            topic[i] = tmp;
        }
        sort(topic.begin(), topic.end(), myComp);

        // compress topic
        compress.clear();
        for(int i = 0; i < t; ++i)  compress[topic[i]] = i;

        // read prohibts
        prohibts.clear();
        string t1, t2;
        int c1, c2;
        for(int i = 0; i < p; ++i){
            cin >> t1 >> t2;
            transform(t1.begin(), t1.end(), t1.begin(), ::toupper);
            transform(t2.begin(), t2.end(), t2.begin(), ::toupper);

            c1 = compress[t1], c2 = compress[t2];
            // besides prohibts from given rules, also prohibts itself
            prohibts[c1] |= (1 << c2);    prohibts[c1] |= (1 << c1);
            prohibts[c2] |= (1 << c1);    prohibts[c2] |= (1 << c2);

        }

        // process recursively
        int mask = 0, len = 0; // mask represents which topic can't be taken due to previous select
        ans.clear();
        for(int i = 0; i < t-s+1; ++i){
            ans.push_back(i);
            recurse(i, (mask | prohibts[i]) );
            ans.pop_back();
        }

        cout << endl;
    }
    return 0;
}
