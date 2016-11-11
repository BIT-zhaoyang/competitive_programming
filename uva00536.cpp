#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

string pre, in;
queue<char> qc;

void process(int pL, int pR, int iL, int iR){
    if(pL > pR) return;

    char root = pre[pL];
    int found = in.find(root, iL);

    int leftLen = found - iL,   rightLen = iR - found;
    process(pL + 1, pL + leftLen, iL, found - 1);  // recurse on left subtree
    process(pL + leftLen + 1, pR, found + 1, iR);  // recurse on right subtree
    qc.push(root);
}

void print(){
    while(qc.size()){
        cout << qc.front();
        qc.pop();
    }
    cout << endl;
}

int main(){ _
    while(cin >> pre >> in){
        process(0, pre.size() - 1, 0, in.size() - 1);
        print();
    }
    return 0;
}
