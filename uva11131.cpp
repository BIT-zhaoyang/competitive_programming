#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

/* To tell the truth, I didn't come up with the solution by myself but looked at the hints in CP3. But the problem also has description problem. It's kind of vague. In a better statement, the problem can be asked: How many lists of traversing a tree are needed, so that the tree structure can be determined uniquely(The lists are constrained to have some special properties).

The solution is amazingly simple. Just two DFS are needed but in reverse order, which means one DFS check the left subtree first, the other one check the right subtree first.
*/

map<string, vector<string> > AdjList;

void process(string &line){
    size_t start = 0, found = line.find(',');
    string parent, child;
    if(found != string::npos){
        parent = line.substr(start, found);
        start = found + 1;
    }

    while(found != string::npos){
        found = line.find(',', start);
        child = line.substr(start, found - start);
        AdjList[parent].push_back(child);
        start = found + 1;
    }
}

void DFS1(string &parent){
    for(int i = 0; i < AdjList[parent].size(); ++i){
        DFS1(AdjList[parent][i]);
    }
    cout << parent << endl;
}

void DFS2(string &parent){
    for(int i = AdjList[parent].size() - 1; i >= 0; --i){
        DFS2(AdjList[parent][i]);
    }
    cout << parent << endl;
}

int main(){ _

    string root, line;
    cin >> line;    // the first line needs special process since it contains the root
    process(line);
    root = AdjList.begin()->first;

    while(cin >> line){
        process(line);
    }

    cout << 2 << endl << endl;
    DFS1(root);
    cout << endl;
    DFS2(root);
    return 0;
}
