#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define vi vector<int>
using namespace std;

void recurse(string &perm, string &str){
    if(perm.size() == str.size())   cout << perm << endl;
    else {
        char ch = str[perm.size()];
        for(int i = 0; i <= perm.size(); ++i){
            perm.insert(perm.begin()+i, ch);
            recurse(perm, str);
            perm.erase(perm.begin()+i);
        }
    }
}

int main(){ _
    string str; int count = 0;
    while(cin >> str){
        if(count)   cout << endl;
        ++count;

        string perm;
        recurse(perm, str);
    }
    return 0;
}
