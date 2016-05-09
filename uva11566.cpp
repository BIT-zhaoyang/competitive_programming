#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(2);
using namespace std;

/* Easy problem. 2D multipack problem. Since the 'multi' here is small, namely 2, we can just substitute each object with 2 identical object then use zeroOnePack to solve this problem. This is a 2D problem. Should use the trick to decrese a 3D problem to 2D.
*/

vector< vector<int> > table;
void zeroOnePack2D(int cost, int value);
void printTable();
int main(){ _
    int n, x, t, k;
    while(cin >> n >> x >> t >> k){
        if(n + x + t + k == 0)  break;

        int numOrder = 2*(n+1); // maximal number of orders
        int total = x * (n+1), money = total;   // compute available money
        while (total < (int)ceil((double)((money+t*(n+1))*11)/10.0))
            --money;

        vector<int> cost(2*k, 0);   // each dim sum can be ordered at most 2 times, so we
        vector<int> favor(2*k, 0);  // just substitue each dim sum with 2 identical ones

        int tmp;    // read input data
        for(int i = 0; i < k; ++i){
            cin >> cost[i<<1];  cost[(i<<1)|1] = cost[(i<<1)];
            for(int j = 0; j <= n; ++j){
                cin >> tmp;
                favor[i<<1] += tmp;
                favor[(i<<1)|1] += tmp;
            }
        }
        // cout << "Available money: " << money << endl;
        // for(int i = 0; i < 2*k; ++i)    cout << cost[i] << " " << favor[i] << endl;
        table.assign(numOrder+1, vector<int> (money+1, 0));
        for(int i = 0; i < cost.size(); ++i){
            zeroOnePack2D(cost[i], favor[i]);
        }
        cout << fixed << (double(table[numOrder][money]) / (n+1)) << endl;
        // printTable();
    }
    return 0;
}

void zeroOnePack2D(int cost, int value){
    for(int k = table.size()-1; k > 0; --k){
        for(int b = table[k].size()-1; b >= cost; --b){
            table[k][b] = max(table[k][b], table[k-1][b-cost]+value);
        }
    }
}

void printTable(){
    for(int i = 1; i < table.size(); ++i){
        for(int j = 1; j < table[i].size(); ++j){
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}
