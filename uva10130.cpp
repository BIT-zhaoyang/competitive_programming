#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;

int p[1100], w[1100];
int table[2][40];

int knapsack(int n, int s){
    // int n = p.size();
    // vector< vector<int> > table(n, vector<int> (s+1, 0));
    int prev = 0, curr = 1;
    memset(table, 0, sizeof table);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= s; ++j){
            if(j >= w[i])   table[curr][j] = max(table[prev][j], table[prev][j-w[i]] + p[i]);
            else table[curr][j] = table[prev][j];
        }
        prev = 1 - prev;
        curr = 1 - curr;
    }
    return table[prev][s];
}

int main(){ _
    int TC; cin >> TC;
    memset(p, 0, sizeof p); memset(w, 0, sizeof w);
    memset(table, 0, sizeof table);
    while(TC--){
        int n;  cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> p[i] >> w[i];
        }

        int t; cin >> t;
        int s = 0, sum = 0;
        for(int i = 0; i < t; ++i){
            cin >> s;
            sum += knapsack(n, s);
        }

        cout << sum << endl;
    }
    return 0;
}
