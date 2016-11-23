#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
/*
These two explanations are so good.
http://bit.ly/2fqZom0
http://bit.ly/2glDTC4

To prevent that the link becomes invalid, I copied the blog from the first resource and attached it at the bottom of the code.

Lesson learned:
How to solve an optimization problem?
1. Consider possible factors, or say potential solutions. In this example, it's the formulat that ans = max(lengthA , lengthB , t1+t2+1).
2. Consider possible affects when making a choice. In this example, there are several steps having multiple choices. For example, which node to choose to connect subtree A with subtree B? What affects will this choice bring to the above formula and what will remain the same?? As mentioned in the blog below:
"可以知道，无论怎么选择rtA，rtB都好，lengthA和lengthB都是不变的。但选择不同的rtA和rtB，则会影响t1和t2的值，那么怎么影响呢？"
This is a very insightful observation and it leads us to consider another important question.
*/

int n, tabuU, tabuV;
vector<int> dist, parent;
vector< vector<int> > AdjList;
queue< ii > tabuEdge;

void bfs(int root){
    dist.assign(n + 1, UNVISITED);
    parent.assign(n + 1, UNVISITED);

    dist[root] = 0;
    queue<int> Q;   Q.push(root);
    while(Q.size()){
        int u = Q.front();  Q.pop();
        for(int i = 0; i < AdjList[u].size(); ++i){
            int v = AdjList[u][i];
            if(u == tabuU && v == tabuV)    continue;
            if(u == tabuV && v == tabuU)    continue;
            if(dist[v] == UNVISITED){
                dist[v] = dist[u] + 1;
                parent[v] = u;
                Q.push(v);
            }
        }
    }
}

int find_middle(int node, int length){
    length /= 2;
    while(length--){
        node = parent[node];
    }
    return node;
}

int find_diameter(int root, int &end1, int &end2){
    bfs(root);
    end1 = max_element(dist.begin(), dist.end()) - dist.begin();
    bfs(end1);
    end2 = max_element(dist.begin(), dist.end()) - dist.begin();
    return dist[end2];
}

void solve(){
    // find longest path in the original tree
    tabuU = -1, tabuV = -1;
    int end1, end2;
    int diameter = find_diameter(1, end1, end2);
    // add each edge on the longest path to the tabu edge list
    while(parent[end2] != UNVISITED){
        tabuEdge.push(ii(end2, parent[end2]));
        end2 = parent[end2];
    }

    int minmax = BIGINT, currBest = BIGINT;
    int breakU, breakV, connectU, connectV;
    while(tabuEdge.size()){
        tabuU = tabuEdge.front().first;
        tabuV = tabuEdge.front().second;
        tabuEdge.pop();

        int dA = find_diameter(tabuU, end1, end2);
        int midA = find_middle(end2, dA);

        int dB = find_diameter(tabuV, end1, end2);
        int midB = find_middle(end2, dB);

        currBest = max(max(dA, dB), int(ceil(dA / 2.0)) + int(ceil(dB / 2.0)) + 1);
        if(currBest < minmax){
            minmax = currBest;
            breakU = tabuU, breakV = tabuV;
            connectU = midA, connectV = midB;
        }
    }

    cout << minmax << endl;
    cout << breakU << " " << breakV << endl;
    cout << connectU << " " << connectV << endl;
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        cin >> n;
        AdjList.assign(n + 1, vector<int> (0));
        for(int i = 0; i + 1 < n; ++i){
            int u, v;   cin >> u >> v;
            AdjList[u].push_back(v);
            AdjList[v].push_back(u);
        }
        solve();
    }
    return 0;
}

/*
树dp

题意：给一个无根树，消掉一条边，新增一条边，求新的树的最长链，问怎么消边和加边，使得最长链的长度最小（HDU 3145一样的题目，不过注意输入，HDU是没有case数的）

假设选择一条边a–b断掉，使得树断裂为两个部分A,B，假设在A中选一个一个点rtA，和B中选一个点rtB，将两点；连接，得到一个新树，那么这个新树的最长链是多少呢？最长链只有3个可能，1.完全来自于A部分，假设长度为lengthA。2.完全来自于B部分，长度为lengthB。2.来自于A,B部分，那么就一定经过rtA和rtB，另外一定是从rtA往A部分走出一条最长路t1，从rtB往B部分走出一条最长路t2。那么整个树的最长链就是
max(lengthA , lengthB , t1+t2+1);
可以知道，无论怎么选择rtA，rtB都好，lengthA和lengthB都是不变的。但选择不同的rtA和rtB，则会影响t1和t2的值，那么怎么影响呢？我们的目的是为了使最大值最小，那么就是令t1，t2尽量小，这里有一个结论，t1的最小值是[lengthA/2]上整，t2最小值[lengthB/2]上整，也就是说rtA是A部分的最长链的中点，rtB是B部分最长链的中点

证明：
对于A部分
1.先找出A部分的最长链，并且标记链上的点，染成红色，其他点是白色
2.一个显然的结论就是，如果选了红色的点做根，这个点刚好是链的中点的话，它能走出的最长路就是L/2；如果不是中点，那么它没有将最长链平分，最长链被分为2部分，长度为x，y，假设x < y，那么y肯定是超过链的一半的，且y也是那个根能走出的最长链 4.如果选的点不是红点而是白点为根，那么一定可以从根先走到红点，距离是t，然后走到了红点，一定有2条路可以走，如果2条路刚好是平分的，那么走过的路程是t+L/2，如果不平分，就跟2情况一样，可以选较长的那边继续走，距离是t+y 所以选白点，花费一定大于红点的，而选红点的情况里，选中点是最少的，所以就是选中点最少 所以我们要做的工作就很简单了 1.枚举原树中的每条边，删除它，得到A,B部分
2.在A部分求一次最长链并找到链的中点rtA
3.在B部分求一次最长链并找到链的中点rtB
4.rtA和rtB相连，那么新树的最长链 = max(lengthA,lengthB,[lengthA/2] + [lengthB/2] + 1); 5.用现在的最长链去更新答案

优化： 可以先对原树求一次最长链，然后枚举删边的时候，只枚举最长链上的边，因为，如果不是断开最长链的边，那么得到的新树，其最长链肯定还是原树的最长链，是不可能更新答案的 枚举全部边时间是2500ms,枚举原树最长链上的边时间为750ms,在hdu排名第一，纪念一下 这题在网上应该是找不到题解的，找了很久找到了官方的，不过没有代码
*/
