#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <climits>
#include <cmath>
#include <set>
#include <bitset>
#include <sstream>
#include <iomanip>

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;

set<string> ansSet;
vector<int> vi;
vector<int> candidate;

void recurse(int sum, int i){
    if(sum == 0){
        string str;
        for(int i = 0; i < candidate.size()-1; ++i)
            str = str + to_string(candidate[i]) + "+";
        str += to_string(candidate.back());
        if(!ansSet.count(str)){
            cout << str << endl;
            ansSet.insert(str);
        }
        return;
    }
    if(sum < 0) return;
    if(i == vi.size())  return;

    candidate.push_back(vi[i]);
    recurse(sum - vi[i], i+1);
    candidate.pop_back();

    recurse(sum, i+1);
}

int main(){ _
    int t, n;
    while(cin >> t >> n){
        if(t == 0)  break;
        cout << "Sums of " << t << ":" << endl;
        ansSet.clear();
        vi.assign(n, 0);    candidate.clear();
        for(int i = 0; i < n; ++i)  cin >> vi[i];
        recurse(t, 0);
        if(ansSet.size() == 0)  cout << "NONE" << endl;
    }
    return 0;
}
