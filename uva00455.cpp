#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;  cin >> n;
  string str;
  while(n--){
    cin >> str;

    int m = str.size();
    vector<int> table(m + 1, -1);
    int i = 0, j = -1;
    while(i < m){
      while(j >= 0 && str[i] != str[j]) j = table[j];
      ++i, ++j;
      table[i] = j;
    }

    int len = m - table.back(); // a potential candidate
    if(m % len) cout << m << endl;
    else  cout << len << endl;

    if(n) cout << endl;
  }
}
