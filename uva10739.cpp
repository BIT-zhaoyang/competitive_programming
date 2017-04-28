#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

/* Edit distance doesn't apply to this problem. I think the difference is that, in this problem, both the 'origin' and 'target' strings can vary. */

string str;
vector< vector<int> > table;

int recur(int i, int j){
  if(i >= j) return 0;
  if(table[i][j]) return table[i][j];
  if(str[i] == str[j])  return table[i][j] = recur(i + 1, j - 1);
  return table[i][j] = min(min(recur(i + 1, j), recur(i, j - 1)), recur(i + 1, j - 1)) + 1;
}

int main(){ _
  int TC; cin >> TC;
  for(int tc = 1; tc <= TC; ++tc){
    cout << "Case " << tc << ": ";
    cin >> str;

    int n = str.size();
    table.assign(n, vector<int> (n, 0));
    cout << recur(0, n - 1) << endl;
  }
  return 0;
}
