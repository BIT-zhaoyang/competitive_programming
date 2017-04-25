#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc; cin >> tc;
  while(tc--){
    int n;  cin >> n;

    vector<string> str(n, "");
    for(int i = 0; i < n; ++i)  cin >> str[i];
    sort(str.begin(), str.end());

    bool possible = true;
    for(int i = 0; i + 1 < n; ++i){
      int n = str[i].size();
      if(str[i] == str[i + 1].substr(0, n)){
        possible = false;
        break;
      }
    }

    if(possible)  cout << "YES" << endl;
    else  cout << "NO" << endl;
  }
  return 0;
}
