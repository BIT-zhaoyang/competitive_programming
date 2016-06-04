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
#include <queue>
#include <stack>

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

/* Again solve backwards. I was stuck due to my implementation ability. But after solving this problem it may improve!

What I have learned? Well, as described at:
http://www.algorithmist.com/index.php/UVa_10672
the thinking process is pretty good. We know we have to move marbles from vertex having extra marbles, but the question is to where shall we move it? How many shall we move it? There are two questions and both don't have a easy answer. But when we solve it backwards, both problems will be solved: we need to move leaf.nMarble-1 marbles, and can only move it to its parents since it's a tree! And this logic is correct! Easily solved!

Next part is how to implement this. The suggestion on algorithmist.com is what I first tried. Keep a queue of leaf, process it, do modification to its parents, and delete it so we will never visit it. But later I found that, we only need to process from leaf to parents, never the other way around. Namely, we only need to go upward and never downward. Thus, only keeping the parent of each node is already enough.

Oh...... After a long time of debug, I realized that I'm really not familiar with graphs. Need to practice a lot on this later!
*/

struct Node{
    int nMarble, parent, nC;
    Node(){
        nMarble = 0;
        parent = -1;
        nC = 0;
    }
};

int main(){ _
    int n;
    while(cin >> n){
        if(n == 0)  break;

        vector<Node> nodes(n+1);
        queue<int> leaves;

        // read data
        int idx, nMarble, nChild, child;
        for(int i = 1; i <= n; ++i){
            // read node index, #Marble, #child
            cin >> idx >> nMarble >> nChild;
            nodes[idx].nMarble = nMarble;
            nodes[idx].nC = nChild;

            // if the node has child, read them
            if(nChild != 0){
                for(int j = 0; j < nChild; ++j){
                    cin >> child;
                    nodes[child].parent = idx;
                }
            } else {
                leaves.push(idx);
            }
        }

        // process from leaf
        int ans = 0, parent, diff, leaf;
        while(!leaves.empty()){
            leaf = leaves.front();
            parent = nodes[leaf].parent;

            if(parent != -1){
                diff = nodes[leaf].nMarble - 1;
                nodes[leaf].nMarble = 1;
                nodes[parent].nMarble += diff;
                nodes[parent].nC -= 1;  // delete this leaf from its parent
                ans += abs(diff);

                // if its parent becomes a leaf, add it to the queue
                if(nodes[parent].nC == 0)   leaves.push(parent);
            }

            leaves.pop();
        }

        cout << ans << endl;
    }
    return 0;
}
