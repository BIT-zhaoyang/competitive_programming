#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< pair<int, int> > vii;

/* This problem is really interesting. It took me a while to came up with this implementation
    Let's first discuss the situations in this problem. Since each person will pass the email to one and only one another person, this process must ends by passing the email back to a guy who has already received this. Namely, the process ends by a loop.

    There are two kinds of loops. The first one is just a pure loop, namely, circle. For example, in given example 1, the loop is 1 -> 2 -> 3 -> 1. The second loop has a tail(or maybe head) associated with it. For example, in given example 2, the loop is: 4 -> 3 -> 2 -> 1 -> 2. Notice that, 1 & 2 form a loop, 4 -> 3 forms a tail to this loop.

    The size of this example is 5*10^4. So, by just traversing each node will lead to TLE since it's O(N^2) time. Thus, we need to preserve some results of previous computations. We store these results in vector<int> nPass. nPass[i] represents how many people the email will reach by starting forwarding it at the ith person.

    In function dfs, we process above mentioned situations. First, we make judgement about whether we meet a loop. This is done in if(visited[to]). If the next node 'to' we are going to visit has already been visited, then it means we meet a loop. But what kinds of loop is it? if(nPass[to] != 0) this means we meet another loop, namely, we are in situation 2, a loop with tail. This is like we are at node 3 in the 4 -> 3 -> 2 -> 1 -> 2 case. Then nPass[3] = 1 + nPass[2], which is nPass[node] = 1 + nPass[to]. Then we return false which means we didn't meet a pure loop. So that nPass[4] = 1 + nPass[3]. If we meet a pure loop, we set the nPass[node] = dist, where dist represents how long the current path is. For example, in 1 -> 2 -> 3 -> 1, we meet the beginning of the loop at node 3 and the length of current path is 3. Then we set nPass[3] = 3 since it's a pure loop so that every node on this loop should have the same nPass number. After this, we return true. Then we are back to node 2, we set the same nPass number to node 2 by setting nPass[node] = nPass[to];
*/

bool dfs(int node, vi &AdjList, vi& nPass, int dist, vi &visited){
    visited[node] = 1;

    int to = AdjList[node];
    if(visited[to]){    // maybe a loop, or may access another loop
        if(nPass[to] != 0){  // access to another loop
            nPass[node] = 1 + nPass[to];
            return false;   // this node doesn't form a loop in its origin chain
        } else {
            nPass[node] = dist; // this node form a loop within its origin chain
            return true;
        }
    } else {
        bool loop = dfs(to, AdjList, nPass, dist + 1, visited);
        if(loop)    nPass[node] = nPass[to];
        else    nPass[node] = 1 + nPass[to];
        return loop;
    }
}

int main(){ _
    int TC; cin >> TC;
    for(int tc = 1; tc <= TC; ++tc){
        int n;  cin >> n;
        vi AdjList(n+1, 0);
        vi nPass(n+1, 0);
        vi visited(n+1, 0);

        int from, to;
        for(int i = 1; i <= n; ++i){
            cin >> from >> to;
            AdjList[from] = to;
        }

        int dist = 1;
        for(int i = 1; i <= n; ++i){
            if(nPass[i] == 0){
                dist = 1;
                dfs(i, AdjList, nPass, dist, visited);
            }
        }

        auto it = max_element(nPass.begin(), nPass.end());
        cout << "Case " << tc << ": " << it - nPass.begin() << endl;
    }
    return 0;
}
