#include <bits/stdc++.h>
using namespace std;

int main() {
  string line;
  vector<int> table(1000011, -1);
  while(cin >> line){
    if(line == ".") break;

    int n = line.size();

    int i = 0, j = -1;
    while(i < n){
      while(j >= 0 && line[i] != line[j]) j = table[j];
      ++i, ++j;
      table[i] = j;
    }

    int period = n - table[n];
    if(n % period) cout << 1 << endl;
    else  cout << n / period << endl;
  }
  return 0;
}
