#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

/* This is my implementation of finding a euler tour. The one provided by CP3 has bugs and the logic is also wrong. The following one looks better. Reference can be found at here: http://bit.ly/2gzSeel which is a very good article. The article describes the Hierholzer's algorithm, which is the one implemented in CP3.

The basic idea is as follow:
    1. Start with an empty stack and an empty tour (eulerian path).
        - If all vertices have even degree - choose any of them.
        - If there are exactly 2 vertices having an odd degree - choose one of them.
        - Otherwise no euler tour or path exists.
    2. If current vertex has no neighbors - add it to tour, remove the last vertex from the stack and set it as the current one. Otherwise (in case it has neighbors) - add the vertex to the stack, take any of its neighbors, remove the edge between selected neighbor and that vertex, and set that neighbor as the current vertex.
    3. Repeat step 2 until the current vertex has no more neighbors and the stack is empty.

So there are mainly two steps, and two stacks. We name the first stack trail, and the second stack tour. So, why doesn this algorithm work? This can be explained in combine with the example graph in the article. In the example graph, the critical choice happens after the search arrived at 8 from 2. Shall we go to 1 or 5(7)? Let's say we unluckily goes to 1, then we meet a dead end. Now we know we are wrong. Logically, exploring 1 should be the very last step. Hmmmm!!! That is important information. So we can put 1 into the stack 'tour', since it's the last step! After this, we returned back to 8, and we explore 5(7). After this correct tour, we arrived at 8 again. This time, there is no more available edge to visit. Then we push 8 to the stack 'tour'. Then we backtracked to 7, which has no more edges to visit. We push 7 to the stack. We continue do this until the 'trail' stack is empty.

The algorithm sounds a bit clear now, but still vague. Let's explain this more intuitively. Assume the loop 8-5-7 deosn't exist for now. Then it's fine we go to 1 from 8 and this is the last step. And after finding the tail of the tour, we do backtrack. We push 1 into the 'tour' stack first, then 8 next. But unfortunately, when we are going to push 8 into the stack, we found 8 has another available path to visit! So, we suspend pushing 8 into the tour stack. But continues to visit the other possible edges. In another word, we insert some edges between the path we go from 8 to the very last 1. After we visited all other possible pathes, we can continue to backtrack.

Example Input:
9 12
6 9
6 1
1 9
1 2
2 4
2 3
4 3
2 8
1 8
5 8
5 7
8 7
*/

stack<int> trail, tour;
vector< list<int> > AdjList;

void EulerTour(int curr){
    // cout << "Enter " << curr << endl;
    trail.push(curr);
    while(AdjList[curr].size()){
        int v = *AdjList[curr].begin(); // visit the edge, remove it
        AdjList[curr].pop_front();

        for(auto it = AdjList[v].begin(); it != AdjList[v].end(); ++it){
            if(*it == curr){
                AdjList[v].erase(it);  // remove bi-directional edge
                break;
            }
        }
        EulerTour(v);
        // cout << "Back to " << curr << endl;
    }

    tour.push(curr);
    trail.pop();
}

int main(){ _
    int n, m;  cin >> n >> m;
    AdjList.assign(n + 1, list<int> (0));
    for(int i = 0; i < m; ++i){
        int u, v;   cin >> u >> v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }

    EulerTour(1);   // start from an arbitrary node
    cout << "A Euler tour:";
    while(tour.size()){
        cout << " " << tour.top();
        tour.pop();
    }
    cout << endl;
    return 0;
}
