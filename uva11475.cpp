#include <bits/stdc++.h>
using namespace std;

int main() {
  string origin;
  vector<int> table(100010, -1);
  while(cin >> origin){
    int n = origin.size();
    string rev = origin;
    reverse(rev.begin(), rev.end());

    int i = 0, j = -1;
    while(i < n){
      while(j >= 0 && rev[j] != rev[i]) j = table[j];
      ++i, ++j;
      table[i] = j;
    }

    int m;
    i = 0, j = 0;
    while(i < n){
      while(j >= 0 && rev[j] != origin[i]) j = table[j];
      ++i, ++j;
      m = j;
    }

    cout << origin + rev.substr(m) << endl;
  }
  return 0;
}
