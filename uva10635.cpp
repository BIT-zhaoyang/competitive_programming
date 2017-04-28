#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int LIS(vector<int> &vi){
  vector<int> seq;
  for(int i = 0; i < vi.size(); ++i){
    int val = vi[i];
    auto it = upper_bound(seq.begin(), seq.end(), val);
    if(it == seq.end()) seq.push_back(val);
    else *it = val;
  }

  return seq.size();
}

int main(){ _
  int TC; cin >> TC;
  for(int tc = 1; tc <= TC; ++tc){
    cout << "Case " << tc << ": ";
    int n, p, q;  cin >> n >> p >> q;
    vector<int> pos(n*n + 1, -1), input;
    for(int i = 0; i <= p; ++i){
      int val;  cin >> val;
      pos[val] = i;
    }

    for(int i = 0; i <= q; ++i){
      int val;  cin >> val;
      if(pos[val] == -1)  continue;
      input.push_back(pos[val]);
    }

    cout << LIS(input) << endl;
  }
  return 0;
}
