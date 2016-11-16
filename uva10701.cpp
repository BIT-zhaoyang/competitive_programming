#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

string pre, in;
queue<char> pos;

void process(int pL, int pR, int iL, int iR){
    if(pL > pR)    return;

    char root = pre[pL];
    int found = (find(in.begin() + iL, in.begin() + iR, root) - in.begin());
    int leftSize = found - iL, rightSize = iR - found;
    // recurse on left subtree
    process(pL + 1, pL + leftSize, iL, found - 1);
    // recurse on right subtree
    process(pL + leftSize + 1, pR, found + 1, iR);
    pos.push(root);
}

void print(){
    while(pos.size()){
        cout << pos.front();
        pos.pop();
    }
    cout << endl;
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        int n;  cin >> n;
        cin >> pre >> in;
        process(0, n - 1, 0, n - 1);
        print();
    }
    return 0;
}
