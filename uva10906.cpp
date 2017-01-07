#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

map<string, bool> isRoot;
map<string, tuple<string, string, string> > eq;

void recurSolve(string &lh, string lastOP, bool leftSide){
    if(lh[0] >= '0' && lh[0] <= '9'){
        cout << lh;
        return;
    }

    string var1, op, var2;
    tie(var1, op, var2) = eq[lh];

    bool brac = false;
    if(lastOP == "*"){
        if(!leftSide || op == "+")  brac = true;
    } else {
        if(!leftSide && op == "+")  brac = true;
    }

    if(brac)    cout << "(";
    recurSolve(var1, op, true);
    cout << op;
    recurSolve(var2, op, false);
    if(brac)    cout << ")";
}

int main(){ _
    int TC; cin >> TC;
    for(int tc = 1; tc <= TC; ++tc){
        int n;  cin >> n;
        eq.clear();
        isRoot.clear();
        string lh, var1, var2, op, rh;
        while(n--){
            cin >> lh >> op >> var1 >> op >> var2;
            isRoot[lh] = true;
            eq[lh] = make_tuple(var1, op, var2);
            if(isalpha(var1[0]))    isRoot[var1] = false;
            if(isalpha(var2[0]))    isRoot[var2] = false;
        }

        string root;
        for(auto it : isRoot)
            if(it.second){
                root = it.first;
                break;
            }
        cout << "Expression #" << tc << ": ";
        // cout << endl;
        recurSolve(root, "", true);
        cout << endl;
    }
    return 0;
}
