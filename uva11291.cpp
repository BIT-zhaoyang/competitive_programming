#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(2);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

double getNum(string &str, int &idx){
    while(str[idx] == ' ' && idx < str.size())  ++idx;

    string ans = "";
    while(str[idx] != ' ' && str[idx] != ')' && idx < str.size())    ans += str[idx++];
    return stod(ans);
}

double getExpression(string &str, int &idx){
    while((str[idx] == ' ' || str[idx] == ')') && idx < str.size())  ++idx;

    double doubleP = 0.0, e1 = 0.0, e2 = 0.0;
    if(str[idx] == '('){
        ++idx;
        doubleP = getNum(str, idx);
        e1 = getExpression(str, idx);
        e2 = getExpression(str, idx);
        return e1 - e2 + 2 * doubleP * e2;
    } else {
        return getNum(str, idx);
    }
}

int main(){ _
    string line;
    while(getline(cin, line)){
        if(line == "()")    break;
        int idx = 0;
        cout <<  fixed <<  getExpression(line, idx) << endl;
    }
    return 0;
}
