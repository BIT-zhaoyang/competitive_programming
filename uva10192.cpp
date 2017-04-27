#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

string A, B;
vector< vector<int> > table, dir;
set<char> cities;

void backtrack(int row, int col){
  if(row == 0 || col == 0)  return;
  int i = row - 1, j = col - 1;
  switch (dir[row][col]) {
    case 0:
      cities.insert(A[i]);
      backtrack(row - 1, col - 1);
      break;
    case 1:
      backtrack(row - 1, col - 1);
      break;
    case 2:
      backtrack(row - 1, col);
      break;
    case 3:
      backtrack(row, col - 1);
      break;
  }
}

int main(){ _
  int tc = 0;
  while(getline(cin, A) && getline(cin, B)){
    cities.clear();
    int n = A.size(), m = B.size();
    table.assign(n + 1, vector<int> (m + 1, 0));
    dir.assign(n + 1, vector<int> (m + 1, 0));

    for(int row = 1; row <= n; ++row){
      for(int col = 1; col <= m; ++col){
        if(A[row - 1] == B[col - 1]){
          table[row][col] = table[row - 1][col - 1] + 1;
          dir[row][col] = 0;
        } else {
          if(table[row - 1][col - 1] >= table[row][col]){
            table[row][col] = table[row - 1][col - 1];
            dir[row][col] = 1;
          }
          if(table[row - 1][col] > table[row][col]){
            table[row][col] = table[row - 1][col];
            dir[row][col] = 2;
          }
          if(table[row][col - 1] > table[row][col]){
            table[row][col] = table[row][col - 1];
            dir[row][col] = 3;
          }
        }
      }
    }

    backtrack(n, m);

    cout << "Case #" << ++tc << ": ";
    cout << "you can visit at most " << table[n][m] << " cities." << endl;
  }
  return 0;
}
