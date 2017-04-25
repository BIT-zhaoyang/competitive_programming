#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc; cin >> tc;
  while(tc--){
    string ori;  cin >> ori;
    string rev = ori;
    reverse(rev.begin(), rev.end());

    vector<int> table(ori.size() + 1, -1);
    int i = 0, j = -1;
    while(i < ori.size()){
      while(j >= 0 && ori[j] != ori[i]) j = table[j];
      ++i, ++j;
      table[i] = j;
    }

    i = 0, j = 0;
    int maxLen = 0;
    while(i < rev.size()){
      while(j >= 0 && ori[j] != rev[i]) j = table[j];
      ++i, ++j;
      maxLen = max(maxLen, j);
    }

    string ans = ori.substr(0, maxLen);
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
  }
  return 0;
}
