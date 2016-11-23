#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

vector<int> preorder, inorder;
queue<int> postorder;

void process(int pl, int pr, int il, int ir){
    if(pl >= pr)    return;
    int root = preorder[pl];
    int idx = find(inorder.begin() + il, inorder.begin() + ir, root) - inorder.begin();
    int leftSize = idx - il;
    process(pl + 1, pl + 1 + leftSize, il, idx);
    process(pl + leftSize + 1, pr, idx + 1, ir);
    postorder.push(root);
}

int main(){ _
    int num;
    while(cin >> num)   preorder.push_back(num);
    inorder = preorder;
    sort(inorder.begin(), inorder.end());
    process(0, preorder.size(), 0, preorder.size());
    while(postorder.size()){
        cout << postorder.front() << endl;
        postorder.pop();
    }
    return 0;
}
