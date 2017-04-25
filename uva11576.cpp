#include <bits/stdc++.h>
using namespace std;

vector<int> table;

void kmpProcess(string &p){
  int n = p.size();
  table.resize(n + 1, -1);
  int i = 0, j = -1;
  while(i < n){
    while(j >= 0 && p[j] != p[i]) j = table[j];
    ++i, ++j;
    table[i] = j;
  }
}

int kmpMatch(string &t, string &p){
  int i = 0, j = 0, n = t.size();
  while(i < n){
    while(j >= 0 && p[j] != t[i]) j = table[j];
    ++i, ++j;
  }
  return j;
}


int main() {
  int tc; cin >> tc;
  while(tc--){
    int k, w; cin >> w >> k;

    string p, t;  cin >> t; --k;
    int result = t.size();
    while(k--){
      cin >> p;
      kmpProcess(p);
      result += p.size() - kmpMatch(t, p);
      t = p;
    }
    cout << result << endl;
  }
  return 0;
}
