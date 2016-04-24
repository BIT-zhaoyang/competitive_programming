#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;

int vi[55];
int table[55][55];

int cut(int *c, int n){
    for(int i = 0; i < n-1; ++i)    table[i][i+1] = 0;

    for(int l = 2; l < n; ++l){
        for(int i = 0; i+l < n; ++i){
            int j = i+l;
            table[i][j] = INT_MAX;
            for(int k = i+1; k < j; ++k){
                table[i][j] = min(table[i][k] + table[k][j], table[i][j]);
            }
            table[i][j] += c[j] - c[i];
        }
    }

    return table[0][n-1];
}

int main(){ _
    int l, n;
    while(cin >> l, l != 0){
        cin >> n;
        vi[0] = 0;
        for(int i = 1; i <= n; ++i)  cin >> vi[i];
        vi[n+1] = l;
        cout << "The minimum cutting is " << cut(vi, n+2) << "." << endl;
    }
    return 0;
}
