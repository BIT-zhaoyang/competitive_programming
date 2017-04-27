#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

bool first = true;
vector<int> A, B;
vector<string> vocab;
map<string, int> dict;
vector< vector<int> > table, dir;

int read_input(vector<int> &vec){
  string str;
  while(cin >> str){
    if(str == "#")  return 1;
    if(!dict.count(str)){
      vocab.push_back(str);
      dict[str] = vocab.size() - 1;
    }
    vec.push_back(dict[str]);
  }
  return 0;
}

void clear(){
  dict.clear();
  A.clear();
  B.clear();
  vocab.clear();
  first = true;
}

void print(int row, int col){
  if(row == 0 || col == 0)  return;
  switch (dir[row][col]) {
    case 0: case 3:
      print(row - 1, col - 1);
      break;
    case 1:
      print(row - 1, col);
      break;
    case 2:
      print(row, col - 1);
      break;
  }

  if(dir[row][col] == 3){
    if(!first)  cout << " ";
    else  first = false;
    cout << vocab[A[row-1]];
  }
}

int main(){ _
  while(read_input(A) && read_input(B)){
    int n = A.size(), m = B.size();
    table.assign(n + 1, vector<int> (m + 1, 0));
    dir.assign(n + 1, vector<int> (m + 1, 0));

    for(int row = 1; row <= n; ++row){
      for(int col = 1; col <= m; ++col){
        int i = row - 1, j = col - 1;
        if(A[i] == B[j]){
          table[row][col] = table[row-1][col-1] + 1;
          dir[row][col] = 3;
        } else {
          if(table[row-1][col-1] > table[row][col]){
            table[row][col] = table[row-1][col-1];
            dir[row][col] = 0;
          }
          if(table[row-1][col] > table[row][col]){
            table[row][col] = table[row-1][col];
            dir[row][col] = 1;
          }
          if(table[row][col-1] > table[row][col]){
            table[row][col] = table[row][col-1];
            dir[row][col] = 2;
          }
        }
      }
    }

    print(n, m);
    cout << endl;
    clear();
  }
  return 0;
}
