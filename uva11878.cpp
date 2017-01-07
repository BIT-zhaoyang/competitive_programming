#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int nCorrect = 0;
    string line;
    while(getline(cin, line)){
        stringstream ss(line);
        int num1, num2, num3;
        char op, eq;
        if(ss >> num1 >> op >> num2 >> eq >> num3){
            if(op == '+' && num1 + num2 == num3)    ++nCorrect;
            else if(op == '-' && num1 - num2 == num3)    ++nCorrect;
        }
    }
    cout << nCorrect << endl;
    return 0;
}
