#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

bool process(string &str){
    char *cstr = new char[str.size() + 1];
    strcpy(cstr, str.c_str());

    vector<bool> hold(52, false);
    char *pch = strtok(cstr, "&");
    while(pch != NULL){
        string atom(pch);
        pch = strtok(NULL, "&");
        if(atom.size() == 1)    hold[atom.back() - 'a'] = true;
        else    hold[atom.back() - 'a' + 26] = true;
    }

    delete [] cstr;

    for(int i = 0; i < 26; ++i)
        if(hold[i] && hold[i + 26])
            return false;

    return true;
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        string input;   cin >> input;
        char *cstr = new char[input.size() + 1];
        strcpy(cstr, input.c_str());

        vector<string> tokens;
        char *pch = strtok(cstr, "(|)");
        while(pch != NULL){
            string token(pch);
            // cout << token << endl;
            pch = strtok(NULL, "(|)");
            tokens.push_back(token);
        }

        delete []cstr;

        // for(auto ele : tokens)  cout << ele << endl;
        bool success = false;
        for(auto ele : tokens)
            success = success || process(ele);

        if(success) cout << "YES" << endl;
        else    cout << "NO" << endl;

        // cout << endl;
    }
    return 0;
}
