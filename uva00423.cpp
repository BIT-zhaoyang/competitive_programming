#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 25
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

// int main(){ _
//     int n;  cin >> n;
//     vector< vector< ii > > AdjList(n, vector< ii > (0));
//
//     string str; int val;
//     for(int i = 1; i < n; ++i){
//         for(int j = 0; j < i; ++j){
//             cin >> str;
//             if(str[0] == 'x')   continue;
//             val = stoi(str);
//             AdjList[i].push_back(ii(j, val));
//             AdjList[j].push_back(ii(i, val));
//         }
//     }
//
//     // dijkstra
//     int source = 0;
//     priority_queue< ii, vector< ii >, greater< ii > > pq;
//     vector<int> dist(n, BIGINT);
//     dist[source] = 0;
//     pq.push(ii(dist[source], source));
//
//     int p, q, d1;
//     while(!pq.empty()){
//         p = pq.top().second,    d1 = pq.top().first;
//         pq.pop();
//         if(d1 > dist[p])    continue;
//         for(int i = 0; i < AdjList[p].size(); ++i){
//             q = AdjList[p][i].first;
//             if(dist[p] + AdjList[p][i].second < dist[q]){
//                 dist[q] = dist[p] + AdjList[p][i].second;
//                 pq.push(ii(dist[q], q));
//             }
//         }
//     }
//
//     int ans = 0;
//     for(int i = 0; i < n; ++i)  ans = max(ans, dist[i]);
//     cout << ans << endl;
//     return 0;
// }

// Floyd-Warshall
int main(){
    int n;  cin >> n;
    vector< vector<int> > AdjMat(n, vector<int> (n, BIGINT));

    string str;     int val;
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < i; ++j){
            cin >> str;
            if(str[0] == 'x')   continue;
            val = stoi(str);
            AdjMat[i][j] = AdjMat[j][i] = val;
        }
    }

    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);}}}

    int ans = 0;
    for(int i = 1; i < n; ++i)  ans = max(ans, AdjMat[0][i]);
    cout << ans << endl;
}
