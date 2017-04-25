#include <bits/stdc++.h>
using namespace std;

vector<int> table;

void kmpProcess(string &p){
  int i = 0, j = -1;
  table.assign(p.size() + 1, -1);
  while(i < p.size()){
    while(j >= 0 && p[i] != p[j]) j = table[j];
    ++i, ++j;
    table[i] = j;
  }
}

int kmpMatch(string &t, string &p){
  int i = 0, j = 0;
  while(i < t.size()){
    while(j >= 0 && t[i] != p[j]) j = table[j];
    ++i, ++j;
  }
  return j;
}

int main() {
  int tc; cin >> tc;
  while(tc--){
    string str; cin >> str;
    string rev = str;
    reverse(rev.begin(), rev.end());

    // match twice
    // once forward, then store these matched length in one set
    kmpProcess(str);
    set<int> allMatch;
    int len = kmpMatch(rev, str);
    while(len > 0){
      allMatch.insert(len);
      len = table[len];
    }

    // once backward, take the matched length.
    // find the complement length in the previous set, until current
    // length becomes 0
    kmpProcess(rev);
    len = kmpMatch(str, rev);
    bool alin = false;
    while(len > 0){
      int comp = str.size() - len;
      if(allMatch.count(comp)){
        alin = true;
        break;
      }
      len = table[len];
    }

    if(alin) cout << "alindrome" << endl;
    else if(allMatch.count(str.size())) cout << "palindrome" << endl;
    else cout << "simple" << endl;
  }
  return 0;
}
