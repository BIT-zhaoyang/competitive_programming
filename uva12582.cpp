#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< pair<int, int> > vii;

int main(){ _
    int TC; cin >> TC;
    string str;
    const char base = 'A';
    for(int tc = 1; tc <= TC; ++tc){
        cin >> str;
        vi count(26, 0);
        vector<bool> appear(26, false);

        stack<char> sc;
        sc.push(str[0]);

        // this part counts how many children does each node have
        char parent, child;
        for(int i = 1; i < str.size(); ++i){
            child = str[i];
            appear[child - base] = true;

            parent = sc.top();
            if(child == parent) sc.pop();
            else{
                count[parent - base] += 1;
                sc.push(child);
            }
        }

        // after counting #children, we need to add 1 for counting the path between each node and its parent, except for the starting node str[0]
        for(char ch = 'A'; ch <= 'Z'; ++ch){
            if(ch == str[0])    continue;
            else    count[ch - base] += 1;
        }

        // output the result
        cout << "Case " << tc << endl;
        for(char ch = 'A'; ch <= 'Z'; ++ch){
            if(appear[ch - base])   cout << ch << " = "  << count[ch - base] << endl;
        }
    }
    return 0;
}
