#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(2);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
/* several improvement:
    My first solution is to copy AdjMat to a new matrix distMat every time we need to add a new road. Namely, update an edge information. This copy is essential since we don't want previous updates affect the current update. After each updation, rerun the folyd-warshall algorithm. This solution passed the test. (Another caveat: the coordinates can be float type. Though I passed with int type, it's unsafe.) But unsurprisingly, it runs very slow.

    Then I check the solution at here: http://bit.ly/2cqAEex which is much better and deepened my understanding of the floy-warshall algorithm. In this solution, after each updation, the length from node i to node j will be improved if it uses the newly added path u-v. Thus, the improvement is improve = AdjMat[i][j] - min(AdjMat[i][j], min(AdjMat[i][u] + uv + AdjMat[v][j],  AdjMat[i][v] + uv + AdjMat[u][j])); This is a much better reflection of the dynamic recursion idea lying beneath the floyd-warshall algorithm, maybe with a slight modification. In floyd-warshall, the idea is to compute bottom-up by considering one additional node. In this algorith, the idea is to compute bottom-up by considering one additional edge! Great solution.

    After using this improvement, my solution speeded up from 1.060 seconds to 0.100 seconds. 10X faster!
*/


int n, m;
vector< ii > nodes;
vector< vector<double> > AdjMat, distMat;

double compute(ii &a, ii &b){
    int dx = a.first - b.first, dy = a.second - b.second;
    return sqrt(dx*dx + dy*dy);
}

void APSP(){
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                distMat[i][j] = min(distMat[i][k] + distMat[k][j], distMat[i][j]);
}

void copy(){
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= n; ++j)
            distMat[i][j] = AdjMat[i][j];
}

double length(){
    double total = 0.0;
    for(int i = 1; i <= n; ++i)
        for(int j = i + 1; j <= n; ++j)
            total += distMat[i][j];
    total *= 2.0;
    return total;
}

// int main(){ _
//     while(cin >> n >> m){
//         if(n == 0)    break;
//         nodes.assign(n+1, ii(0, 0));
//         for(int i = 1; i <= n; ++i)  cin >> nodes[i].first >> nodes[i].second;
//         AdjMat.assign(n+1, vector<double> (n+1, 1e9));
//         distMat.assign(n+1, vector<double> (n+1, 1e9));
//
//         int u, v;
//         for(int i = 0; i < m; ++i){
//             cin >> u >> v;
//             double dist = compute(nodes[u], nodes[v]);
//             AdjMat[u][v] = AdjMat[v][u] = dist;
//             distMat[u][v] = distMat[v][u] = dist;
//         }
//
//         // compute initial total dist
//         APSP();
//         double init = length();
//
//         // select new road
//         int x, y;
//         double newLen = 0.0, best = init;
//         for(int i = 1; i <= n; ++i){
//             for(int j = i + 1; j <= n; ++j){
//                 if(AdjMat[i][j] < 1e9)  continue;
//                 copy();
//                 distMat[i][j] = distMat[j][i] = compute(nodes[i], nodes[j]);
//                 APSP();
//                 newLen = length();
//
//                 if(newLen + 1e-9 < best){
//                     x = i, y = j;
//                     best = newLen;
//                 } else if(abs(newLen - best) < 1e-9){
//                     if(distMat[i][j] < compute(nodes[x], nodes[y]))
//                         x = i, y = j;
//                     else if(abs(distMat[i][j] - compute(nodes[x], nodes[y]) < 1e-9))
//                         if(i + j < x + y)
//                             x = i, y = j;
//                 }
//             }
//         }
//
//         if(abs(init - best) + 1e-9 <= 1.0)  cout << "No road required" << endl;
//         else    cout << x << " " << y << endl;
//     }
//     return 0;
// }

// improved solution
int main(){ _
    while(cin >> n >> m){
        if(n == 0)    break;
        nodes.assign(n+1, ii(0, 0));
        for(int i = 1; i <= n; ++i)  cin >> nodes[i].first >> nodes[i].second;
        distMat.assign(n+1, vector<double> (n+1, 1e9));
        // This one is essential in this algorithm, since in computing the improvement 'improve', it's necessary to have distMat[i][i] = 0. Otherwise, the algorithm won't work.
        for(int i = 0; i <= n; ++i) distMat[i][i] = 0;

        int u, v;
        for(int i = 0; i < m; ++i){
            cin >> u >> v;
            double dist = compute(nodes[u], nodes[v]);
            distMat[u][v] = distMat[v][u] = dist;
        }

        // compute initial total dist
        APSP();

        // select new road
        int x, y;
        double most = -1e9, improve = 0.0;
        for(int u = 1; u <= n; ++u){
            for(int v = u + 1; v <= n; ++v){
                double uv = compute(nodes[u], nodes[v]);
                improve = 0.0;
                for(int i = 1; i <= n; ++i)
                    for(int j = i + 1; j <= n; ++j)
                        improve += distMat[i][j] - min(distMat[i][j],
                                    min(distMat[i][u] + uv + distMat[v][j],
                                        distMat[i][v] + uv + distMat[u][j]));
                improve *= 2.0;
                if(improve - 1e-9 > most){
                    x = u, y = v;
                    most = improve;
                } else if(abs(improve - most) < 1e-9){
                    double xy = compute(nodes[x], nodes[y]);
                    if(uv + 1e-9 < xy)
                        x = u, y = v;
                    else if(abs(uv - xy) < 1e-9)
                        if(u + v < x + y)
                            x = u, y = v;
                }
            }
        }

        if(most + 1e-9 <= 1.0)  cout << "No road required" << endl;
        else    cout << x << " " << y << endl;
    }
    return 0;
}
