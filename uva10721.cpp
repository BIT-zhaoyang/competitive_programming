#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

long long table[51][51][51];

long long rec(int n, int k, int m){
    if(n <= 0)  return 0;
    if(k == 1){
        if(n <= m)  return 1;
        else return 0;
    }

    if(table[n][k][m] != -1)    return table[n][k][m];

    long long sum = 0;
    for(int i = 1; i <= m; ++i)
        sum += rec(n-i, k-1, m);

    table[n][k][m] = sum;
    return sum;
}

int main(){ _
    memset(table, -1, sizeof table);
    int n, k, m;
    while(cin >> n >> k >>m)    cout << rec(n, k, m) << endl;
    return 0;
}
