#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define POS_INF 1 << 28
#define NEG_INF -1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

/* This is a new type of graph modelling problem I haven't seen before. Again, it is a good problem. If I wasn't told it is MCBM problem, I will not be able to come up with the solution. Even I know it belongs to this category, I didn't come up with solution, but reffered to others' blogs.

I've tried DP and greedy but both doesn't work. DP solution has a exponential state space which is not practical. I came up with a greedy strategy which always take the mode which can process most tasks first. But it proves to be wrong. Consider this example:
1 2
1 1
1 1
2 1
2 1
2 3
The optimal solution is to take mode 1 and 2 of the first machine. But according to my solution, it will take mode 1 of the second machine then for the rest two there is no difference between which machine we choose.

So, finally comes the MCBM solution. I once got quite close to the modelling. My first temp is that, on the left side, we list all the modes of both machine, and then on the right side, we list all tasks. This seems to be such a natural choice of building bipartite graph, i.e. one side is mode, and the other side is task. Then the problem becomes, how to we find the minimum set of nodes on the left side, such that, all nodes on the right side is covered by an edge emitted from the left side. This seems to be a Min Vertex Cover problem which is in fact a MCBM problem but it is not a MVC problem. MVC problem asks to find a set of nodes which covers all edges(the nodes can be from either side, not limited to one side), rather than nodes, what's more restricted, only part of the nodes. So my modelling is not correct.

Then I checked some blogs, they put modes of machine A on the left side and put modes of machine B on the right side. Next, they model each task as an edge, which connects the i-th node on the left and j-th node on the right if the task can be executed on mode-i on machine A and mode-j on machine B. Then, it becomes a MVC problem. The goal is to cover all edges(the tasks) by using minimum nodes(the machine modes from both machine). If a task can be processed by current selection of nodes, it will be covered.

My modelling is in fact quite close to the correct MVC modelling. If we wipe out the task node and connect the edges coming into and out of these nodes, my modelling becomes the MVC modelling. But anyway, I learned something new from this problem. Events, objects are not limited to being modelled only as nodes in the graph, but they can also by modelled as edges.
*/

int n, m, k;
vector<int> match;
vector<bool> visited;
vector< vector<int> > AdjList;

int aug_path(int u){
    if(visited[u])  return 0;
    visited[u] = true;
    for(int i = 0; i < AdjList[u].size(); ++i){
        int v = AdjList[u][i];
        if(match[v] == -1 || aug_path(match[v])){
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

int main(){ _
    while(cin >> n >> m >> k){
        AdjList.assign(n, vector<int> (0));
        match.assign(m, -1);
        for(int i = 0; i < k; ++i){
            int id, u, v;   cin >> id >> u >> v;
            --u, --v;
            AdjList[u].push_back(v);
        }

        int MCBM = 0;
        for(int i = 0; i < n; ++i){
            visited.assign(n, false);
            MCBM += aug_path(i);
        }
        cout << MCBM << endl;
    }
    return 0;
}
