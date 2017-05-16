#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
  string ori, rever;
  while(cin >> ori) {
    rever = ori;
    reverse(rever.begin(), rever.end());

    int n = ori.size(), m = rever.size();
    vector< vector<int> > table(n + 1, vector<int> (m + 1, 0));
    vector< vector<int> > dir(n + 1, vector<int> (m + 1, 0));

    for(int row = 1; row <= n; ++row) {
      int i = row - 1;
      for(int col = 1; col <= m; ++col) {
        int j = col - 1;
        if(ori[i] == rever[j]){
          table[row][col] = table[row - 1][col - 1] + 1;
          dir[row][col] = 1;
        } else {
          if(table[row][col - 1] >= table[row][col]) {
              table[row][col] = table[row][col - 1];
              dir[row][col] = 2;
          }
          if(table[row - 1][col] > table[row][col]){
            table[row][col] = table[row - 1][col];
            dir[row][col] = 3;
          }
        }
      }
    }

    cout << ori.size() - table[n][m] << " ";

    int row = n, col = m;
    while(row > 0 && col > 0) {
      switch (dir[row][col]) {
        case 1:
          cout << ori[row - 1];
          --row, --col;
          break;
        case 2:
          cout << rever[col - 1];
          --col;
          break;
        case 3:
          cout << ori[row - 1];
          --row;
          break;
      }
    }

    while(row > 0){
      cout << ori[row - 1];
      --row;
    }

    while(col > 0){
      cout << rever[col - 1];
      --col;
    }
    cout << endl;
  }
  return 0;
}
