#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
  string A, B;
  while(getline(cin, A) && getline(cin, B)) {
    int n = A.size(), m = B.size();
    vector< vector<int> > table(2, vector<int> (m + 1, 0));

    int pre = 0, cur = 1, ans = 0;
    for(int row = 1; row <= n; ++row) {
      int i = row - 1;
      for(int col = 1; col <= m; ++col) {
        int j = col - 1;
        table[cur][col] = max(table[pre][col - 1] + (A[i] == B[j]), table[cur][col]);
        table[cur][col] = max(table[pre][col], table[cur][col]);
        table[cur][col] = max(table[cur][col - 1], table[cur][col]);
        ans = max(ans, table[cur][col]);
      }
      pre = 1 - pre, cur = 1- cur;
    }

    cout << ans << endl;
  }
  return 0;
}
