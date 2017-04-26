#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int counter;
string A, B;
vector< vector<int> > nop, action;  // nop: number of operations

void print(int row, int col){
  if(row == 0 && col == 0)  return;
  int i = row - 1, j = col - 1;
  switch (action[row][col]) {
    case 0:
      print(row - 1, col - 1);
      break;
    case 1:
      print(row - 1, col - 1);
      cout << counter++ << " ";
      cout << "Replace " << col << "," << B[j] << endl;
      break;
    case 2:
      print(row - 1, col);
      cout << counter++ << " ";
      cout << "Delete " << col + 1 << endl;
      break;
    case 3:
      print(row, col - 1);
      cout << counter++ << " ";
      cout << "Insert " << col << "," << B[j] << endl;
      break;
  }
}

int main(){ _
  bool first = true;
  while(getline(cin, A) && getline(cin, B)){
    int n = A.size(), m = B.size();
    nop.assign(n + 1, vector<int> (m + 1, POS_INF));
    action.assign(n + 1, vector<int> (m + 1, 0));  // 0: copy 1: replace 2: delete 3:insert

    for(int row = 0; row <= n; ++row) nop[row][0] = row, action[row][0] = 2;
    for(int col = 0; col <= m; ++col) nop[0][col] = col, action[0][col] = 3;

    for(int row = 1; row <= n; ++row){
      for(int col = 1; col <= m; ++col){
        int i = row - 1, j = col - 1;
        if(A[i] == B[j]){
          nop[row][col] = nop[row-1][col-1];
        } else {
          if(nop[row-1][col-1] + 1 < nop[row][col])
            nop[row][col] = nop[row-1][col-1] + 1, action[row][col] = 1;
          if(nop[row-1][col] + 1 < nop[row][col])
            nop[row][col] = nop[row-1][col] + 1, action[row][col] = 2;
          if(nop[row][col-1] + 1 < nop[row][col])
            nop[row][col] = nop[row][col-1] + 1, action[row][col] = 3;
        }
      }
    }

    if(!first)  cout << endl;
    else  first = false;
    counter = 1;
    cout << nop[n][m] << endl;
    print(n, m);
  }
  return 0;
}
