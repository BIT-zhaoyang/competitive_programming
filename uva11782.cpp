#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int H, N, K;
vector<int> value;
vector< vector<int> > table;

int left(int u){
    int v = (u << 1);
    return (v >= N) ? -1 : v;
}

int right(int u){
    int v = (u << 1) + 1;
    return (v >= N) ? -1 : v;
}

int solve(int u, int k){
    if(u == -1) return NEG_INF;
    if(k == 1)  return table[u][k] = value[u];
    if(table[u][k] != -1)   return table[u][k];

    int L = left(u), R = right(u), ans = NEG_INF;
    for(int i = 1; i < k; ++i){
        ans = max(ans, solve(L, i) + solve(R, k - i));
    }
    return table[u][k] = ans;
}

void read_input(int u){
    cin >> value[u];
    int L = left(u), R = right(u);
    if(L != -1) read_input(L);
    if(R != -1) read_input(R);
}

int main(){ _
    while(cin >> H >> K){
        N = (1 << (H + 1));
        value.assign(N, 0);
        table.assign(N, vector<int> (K + 1, -1));
        read_input(1);

        int ans = NEG_INF;
        for(int k = 1; k <= K; ++k){
            ans = max(ans, solve(1, k));
        }
        cout << ans << endl;
    }
    return 0;
}
