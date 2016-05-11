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
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef pair<int, int> pii;

map<pii, bool> memo;
map<pii, int> choice;
const char ops[4] = {'+', '-', '*', '/'};

int operate(int a, int b, int opIdx){
    int tmp = 1e6;
    switch(ops[opIdx]){
        case '+':   tmp = a + b;    break;
        case '-':   tmp = a - b;    break;
        case '*':   tmp = a * b;    break;
        case '/':   if(a % b == 0)  tmp = a / b;    break;
    }
    return tmp;
}

bool rec(int val, int p, vector<int> &vi, int target){
    if(p == vi.size())  return val == target;

    pii status = make_pair(val, p);
    if(memo.count(status))  return memo[status];

    bool possible = false;
    for(int i = 0; i < 4; ++i){
        int tmp = operate(val, vi[p], i);
        if(tmp >= -32000 && tmp <= 32000)   possible |= rec(tmp, p+1, vi, target);
        if(possible){
            choice[status] = i;
            break;
        }
    }
    memo[status] = possible;
    return possible;
}

void backtrack(pii &status, vector<int> &vi){
    int p = status.second;
    cout << vi[p-1];
    if(choice.count(status)){
        cout << ops[choice[status]];
        int tmp = operate(status.first, vi[p], choice[status]);

        pii next = make_pair(tmp, p+1);
        backtrack(next, vi);
    }
}

int main(){ _
    int TC; cin >> TC;
    while(TC--){
        memo.clear();   choice.clear();
        int n;  cin >> n;
        vector<int> vi(n, 0);
        for(int i = 0; i < n; ++i)  cin >> vi[i];
        int target; cin >> target;

        if(n == 0){
            cout << "NO EXPRESSION" << endl;
            continue;
        }

        bool possible = rec(vi[0], 1, vi, target);
        if(possible){
            pii initStatus = make_pair(vi[0], 1);
            backtrack(initStatus, vi);
            cout <<"=" << target << endl;
        } else {
            cout << "NO EXPRESSION" << endl;
        }
    }
    return 0;
}
