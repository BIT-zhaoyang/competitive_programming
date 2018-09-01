#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

/*
This problem is intreseting. But most of the interesting part relies on your understanding of the
palindrome. The first observation is that, we only need to find length 3 and 4 palindrome, no longer
ones. The reason is that, the longer one consists of length 3 or 4 ones. The problem demands that no
palindrome embbeds in another one. So if a longer one(say ABCBA) and another one(say EDE) meets the requirement, then the shorter one inside the longer one combined with the other one also meet the
requirement(namely, BCB and EDE).

Next, we loop through the string. Based on each position, we find length 3 and 4 palindromes. One
interesting point is that, if on current position, we find a length 3 palindrome, we needn't
continue to check if a length 4 palindrome exists.
Explanation:
  1) if the length 3 palindrome is in the form ABA(we are at position B), then the length 4
  substring based on the position can't be a
  palindrome anyway since B != A.
  2) if the length 3 palindrome is in the form AAA(we are at the second A position), then no matter
  if the length 4 substring is a palindrome, it doesn't matter. If it isn't, the check fails, we
  don't have to record. If it is, then the AAAA contains the previous AAA. If the AAAA meet the
  requirement described in the problem, then the shorter AAA will also do.
*/


set<string> palins;
bool isPalinWord(string &str) {
  palins.clear();
  int n = str.size();
  for(int i = 1; i + 1 < n; ++i) {
    if(str[i-1] == str[i+1]){
      palins.insert(str.substr(i-1, 3));
      continue;
    }

    if(i + 2 >= n)  continue;
    if(str[i-1] == str[i + 2] && str[i] == str[i + 1]){
      palins.insert(str.substr(i-1, 4));
    }
  }

  return palins.size() >= 2;
}

int main(){ _
  string str;
  while(cin >> str) {
    // cout << str << endl;
    if(isPalinWord(str))  cout << str << endl;
  }
  return 0;
}
