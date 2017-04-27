#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
  int n, m, tc = 0;
  while(cin >> n >> m){
    if(n + m == 0)  break;
    vector<int> A(n, 0);
    vector<int> B(m, 0);
    vector< vector<int> > table(2, vector<int> (m + 1, 0));

    for(int i = 0; i < n; ++i)  cin >> A[i];
    for(int i = 0; i < m; ++i)  cin >> B[i];

    int pre = 0, cur = 1;
    for(int i = 0; i < n; ++i){
      for(int col = 1; col <= m; ++col){
        int j = col - 1, match = (A[i] == B[j]);
        table[cur][col] = max(table[cur][col], table[pre][col - 1] + match);
        table[cur][col] = max(table[cur][col], table[cur][col - 1]);
        table[cur][col] = max(table[cur][col], table[pre][col]);
      }
      pre = 1 - pre, cur = 1 - cur;
      table[cur].assign(m + 1, 0);
    }

    cout << "Twin Towers #" << ++tc << endl;
    cout << "Number of Tiles : " << table[pre][m] << endl << endl;
  }
  return 0;
}
