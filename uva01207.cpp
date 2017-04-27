#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int n, m;
string A, B;
vector< vector<int> > table;

int main(){ _
  while(cin >> n >> A >> m >> B){
    table.assign(2, vector<int> (m + 1, POS_INF));
    for(int i = 0; i <= m; ++i)  table[0][i] = i;

    int cur = 1, pre = 0;
    for(int i = 0; i < n; ++i){
      table[cur][0] = i + 1;
      for(int col = 1; col <= m; ++col){
        int j = col - 1;
        if(A[i] == B[j]) table[cur][col] = table[pre][col - 1];
        else {
          table[cur][col] = min(table[cur][col], table[pre][col] + 1);
          table[cur][col] = min(table[cur][col], table[cur][col-1] + 1);
          table[cur][col] = min(table[cur][col], table[pre][col-1] + 1);
        }
        // cout << table[cur][col] << " ";
      }
      // cout << endl;
      pre = 1 - pre,  cur = 1 - cur;
      table[cur].assign(m + 1, POS_INF);
    }
    cout << table[pre][m] << endl;
  }
  return 0;
}
