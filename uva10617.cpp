#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
  int tc; cin >> tc;
  while(tc--) {
    string str; cin >> str;
    int n = str.size();
    vector< vector<int64> > table(n, vector<int64> (n, 0));
    for(int i = 0; i < n; ++i)  table[i][i] = 1;
    for(int i = 0; i + 1 < n; ++i) table[i][i+1] = (str[i] == str[i + 1]) + 2;

    for(int stride = 2; stride < n; ++stride) {
      for(int i = 0; i + stride < n; ++i) {
        if(str[i] == str[i + stride]) {
          table[i][i + stride] = table[i][i + stride - 1] + table[i + 1][i + stride] + 1;
        } else {
          table[i][i + stride] = table[i][i + stride - 1] + table[i + 1][i + stride]
                              - table[i + 1][i + stride - 1];
        }
      }
    }

    cout << table[0][n - 1] << endl;
  }
  return 0;
}
