#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

map<string, int> dict;

int main(){ _
  int tc = 1;
  string A, B;
  vector<int> vi1, vi2;
  while(getline(cin, A) && getline(cin, B)) {
    if(A == "" || B == ""){
      cout << setw(2) << tc++ << ". Blank!" << endl;
      continue;
    }

    // cout << A << endl;
    // cout << B << endl;

    vi1.clear();  vi2.clear();
    dict.clear();
    string word;
    for(int i = 0; i < A.size(); ++i) {
      if(isalnum(A[i])) word.push_back(A[i]);
      else if(word != ""){
        if(dict.count(word) == 0){
          dict[word] = 0;
          dict[word] = dict.size();
        }
        vi1.push_back(dict[word]);
        word = "";
      }
    }
    if(word != ""){
      if(dict.count(word) == 0){
        dict[word] = 0;
        dict[word] = dict.size();
      }
      vi1.push_back(dict[word]);
      word = "";
    }

    for(int i = 0; i < B.size(); ++i) {
      if(isalnum(B[i])) word.push_back(B[i]);
      else if(word != ""){
        if(dict.count(word) == 0){
          dict[word] = 0;
          dict[word] = dict.size();
        }
        vi2.push_back(dict[word]);
        word = "";
      }
    }
    if(word != ""){
      if(dict.count(word) == 0){
        dict[word] = 0;
        dict[word] = dict.size();
      }
      vi2.push_back(dict[word]);
      word = "";
    }

    int ans = 0, n = vi1.size(), m = vi2.size();
    vector< vector<int> > table(n + 1, vector<int> (m + 1, 0));
    for(int row = 1; row <= n; ++row) {
      int i = row - 1;
      for(int col = 1; col <= m; ++col) {
        int j = col - 1;
        table[row][col] = max(table[row][col], table[row-1][col-1] + (vi1[i] == vi2[j]));
        table[row][col] = max(table[row][col], table[row-1][col]);
        table[row][col] = max(table[row][col], table[row][col-1]);
        ans = max(ans, table[row][col]);
      }
    }
    cout << setw(2) << tc++ << ". Length of longest match: " << ans << endl;
  }
  return 0;
}
