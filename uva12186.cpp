#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int N, T;
vector< vector<int> > AdjList;

int solve(int u){
    int nChild = AdjList[u].size();
    if(nChild == 0) return 1;

    vector<int> fromChild;
    for(int i = 0; i < AdjList[u].size(); ++i){
        int v = AdjList[u][i];
        fromChild.push_back(solve(v));
    }
    sort(fromChild.begin(), fromChild.end());
    int threshold = int(ceil(nChild /100.0 * T));
    int total = 0;
    for(int i = 0; i < threshold; ++i)  total += fromChild[i];

    return total;
}

int main(){ _
    while(cin >> N >> T){
        if(N == 0)  break;
        AdjList.assign(N + 1, vector<int> (0));
        for(int i = 1; i <= N; ++i){
            int parent;  cin >> parent;
            AdjList[parent].push_back(i);
        }

        cout << solve(0) << endl;
    }
    return 0;
}
