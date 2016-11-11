#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

/* ============== Great Lesson Learned!!!! ================
    In the function bool process(), I examined whether a node is a leaf by calling
        hasLeaf = process(iL, found - 1, pL, pR - rightLen - 1, sum) || hasLeaf;
        hasLeaf = process(found + 1, iR, pR - rightLen, pR - 1, sum) || hasLeaf;
    The intention is, we should recurse further into deeper layers, and at the same time, we check if a node has leaf. In other words, checking is kind of like a side effection. The main purpose is to recurse.

    Thus, in this way, we must put the 'hasLeaf' variable behind the OR(||) operation. The reason is that c++ uses lazy check mechanism. If we write above two lines like this below:
        hasLeaf = hasLeaf || process(iL, found - 1, pL, pR - rightLen - 1, sum);
        hasLeaf = hasLeaf || process(found + 1, iR, pR - rightLen, pR - 1, sum);
    Then, if the node has left child, after the first line finishes, hasLeaf = true. When the second line begins, since hasLeaf == true, the lazy mechanism starts to work. The program will NOT go to the second part, which is the recurse call of process(found + 1, iR, pR - rightLen, pR - 1, sum). Thus, the recursion logic is broken.

    This is a very hard to detect bug, a great lesson learned!
*/

int minSum, ans;
vector<int> inorder, postorder;

bool process(int iL, int iR, int pL, int pR, int sum){
    if(iL > iR) return false;

    int root = postorder[pR];
    int found = (find(inorder.begin() + iL, inorder.begin() + iR + 1, root) - inorder.begin());
    int leftLen = found - iL,   rightLen = iR - found;
    sum += root;

    bool hasLeaf = false;
    // recurse on left subtree
    hasLeaf = process(iL, found - 1, pL, pR - rightLen - 1, sum) || hasLeaf;
    // recurse on right subtree
    hasLeaf = process(found + 1, iR, pR - rightLen, pR - 1, sum) || hasLeaf;

    if(!hasLeaf && sum < minSum){
        minSum = sum;
        ans = root;
    }
    return true;
}

int main(){ _
    // 3 2 1 4 5 7 6    inorder
    // 3 1 2 5 6 7 4    postorder
    string line;
    while(getline(cin, line)){
        stringstream ss(line);
        inorder.clear(), postorder.clear();
        minSum = INT_MAX;

        int val;
        while(ss >> val)    inorder.push_back(val);
        postorder.assign(inorder.size(), 0);
        for(int i = 0; i < postorder.size(); ++i)   cin >> postorder[i];
        cin.ignore();

        process(0, inorder.size() - 1, 0, postorder.size() - 1, 0);
        cout << ans << endl;
    }
    return 0;
}
