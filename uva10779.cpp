#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

/* The modeling of this problem is awesome.... At first, I was trying to build a graph like the neural network. Each person has a layer belong to him with 'm' nodes. But then I found the connections between these nodes are too much... It's almost a fully connected graph. Besides this, there is an option of whether Bob will change sticker with the other person. And after the change, we have to go back to check Bob's state. And also, the ordering of the others also makes difference. And what's more, we may come back to trade with the same person again. It's not possible to represent this complicated idea in the neural network like graph...

Then I found this article: bit.ly/2cZhffN . This modeling is so awesome. It treats people and stickers as the two sides of a bipartite graph. There is a source which only goes to Bob.(The source can be absorbed by the same node of Bob. But an explicit source makes the index easier.) The capacity is the number of stickers Bob has. Then the capacity of res[i][j] where i is person, j is sticker, means how many j-th sticker does the i-th person would like to trade. For Bob, it's the number of j-th sticker Bob has since he will to trade all his stickers. For others, it's the number of j-th stickers they have minus 1, since the others want to preserve at least one of the j-th sticker. The for each j-th sticker that the i-th person doesn't have, we set res[j][i] = 1. This means the i-th person would like to trade for one and only one of the j-th sticker that he doesn't have. This backward edge models the complicated trading procedure mentioned above. At last, we set each res[j][t] = 1 means Bob can have the j-th sticker. Since the problem asks how many stickers can Bob have, thus only res[s][Bob] = #stickers he has, as we mentioned before.

On each augment path, an edge f[j][i] means there is one j-th sticker goes to the i-th person(since res[j][i] = 1), and an edge f[i][j] means there are f[i][j] j-th stickers the i-th person would like to trade. So Bob can uses these stickers to trade for other stickers. Intuitively, there is only one flow from source to Bob, so each reachable sticker node means Bob can have that sticker.
*/

int s, t, f, mf;
vector< vector<int> > res;
vector<int> parent;

void BFS(){
    parent.assign(t+1, -1);
    queue<int> Q;   Q.push(s);
    while(!Q.empty()){
        int u = Q.front();  Q.pop();
        if(u == t)  break;
        for(int v = 0; v < res.size(); ++v)
            if(res[u][v] > 0 && parent[v] == -1)
                parent[v] = u, Q.push(v);
    }
}
void augment(int v, int minEdge){
    if(v == s){ f = minEdge;    return;}
    else if(parent[v] != -1){
        augment(parent[v], min(minEdge, res[parent[v]][v]));
        res[parent[v]][v] -= f; res[v][parent[v]] += f;
    }
}
void EdmondKarp(){
    f = mf = 0;
    while(true){
        // BFS for finding augment path
        BFS();
        // augment path
        f = 0;
        augment(t, BIGINT);
        mf += f;

        if(f == 0)  break;
    }
}

int main(){ _
    int TC; cin >> TC;
    for(int tc = 1; tc <= TC; ++tc){
        /* init */
        int n, m;   cin >> n >> m;
        s = 0, t = n + m + 1;
        res.assign(n+m+2, vector<int> (n+m+2, 0));
        for(int i = n + 1; i <= n + m; ++i) res[i][t] = 1;
        /* input */
        int ns, sidx;   // number of stickers, sticker index
        cin >> ns;  res[s][1] = ns; // input for Bob
        while(ns--){
            cin >> sidx;
            res[1][sidx + n] += 1;
        }
        for(int i = 2; i <= n; ++i){ // input for others
            cin >> ns;
            while(ns--){
                cin >> sidx;
                res[i][sidx + n] += 1;
            }
            for(int j = n + 1; j <= n + m; ++j){
                if(res[i][j] > 0)   res[i][j] -= 1;
                else                 res[j][i] = 1;
            }
        }
        /* EdmondKarp */
        EdmondKarp();
        /* Print Result */
        cout << "Case #" << tc << ": " << mf << endl;
    }
    return 0;
}
