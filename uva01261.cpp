#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

map<string, bool> memo;

bool pop(string& s){
    if(s.size() == 1)   return false;
    if(s.size() == 0)   return true;
    if(memo.count(s))    return memo[s];

    bool possible = false;
    int gs = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == s[gs])   continue;
        else if(i - gs >= 2){
            string _s = s;
            _s.erase(gs, i-gs);
            possible |= pop(_s);
            gs = i;
        } else{
            gs = i;
        }
    }

    if(s.size() - gs >= 2){
        string _s = s;
        _s.erase(gs, s.size()-gs);
        possible |= pop(_s);
    }

    memo[s] = possible;
    return possible;
}


int main(){ _
    int TC; cin >> TC;
    while(TC--){
        memo.clear();
        string s;   cin >> s;
        if(pop(s))  cout << 1 << endl;
        else    cout << 0 << endl;
    }
    return 0;
}
