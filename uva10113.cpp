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
#include <queue>
#include <stack>
#include <tuple>

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

map<string, int> item2idx;
vector< vector< tuple<int, int, int> > > edges;   // tuple<int, int, int>: index of the child, amount of the child, amount of the parent. parent is always lexilogically large than child. The meaning of the last two ints is how many units of child we can get for only 1 unit of parent. Namely, #child / # parent.
vector<bool> visited;

int gcd(int a, int b)
{
    int c;
    while(a != 0) {
        c = a; a = b%a;  b = c;
    }
    return b;
}

bool dfs(int s, int e, int b, int a, pair<int, int>& ans){
    visited[s] = true;
    if(s == e){
        ans = make_pair(a, b);
        return true;
    }

    int child, nextB, nextA, divisor;
    for(int i = 0; i < edges[s].size(); ++i){
        child = get<0>(edges[s][i]);
        if(visited[child])  continue;

        nextB = b * get<1>(edges[s][i]);
        nextA = a * get<2>(edges[s][i]);
        divisor = gcd(nextB, nextA);
        nextB = nextB / divisor;
        nextA = nextA / divisor;
        if(dfs(child, e, nextB, nextA, ans))    return true;
    }
    return false;
}


int main(){ _
    char op, eq;
    int a, b, idx1, idx2, nitem = 0;
    string A, B, large, small;
    while(cin >> op){
        if(op == '.')   break;

        if(op == '?') {
            cin >> A >> eq >> B;

            pair<int, int> ans;
            visited.assign(visited.size(), false);
            idx1 = item2idx[A], idx2 = item2idx[B];
            if(dfs(idx1, idx2, 1, 1, ans)){
                cout << ans.first << " " << A << " = " << ans.second << " " << B << endl;
            } else {
                cout << "? " << A << " = ? " << B << endl;
            }
        } else {
            cin >> a >> A >> eq >> b >> B;
            if(item2idx.count(A) == 0){
                // item2idx[A] = item2idx.size();
                item2idx[A] = nitem++;
                edges.push_back(vector< tuple<int, int, int> > (0));
                visited.push_back(false);
            }
            if(item2idx.count(B) == 0){
                item2idx[B] = nitem++;
                // item2idx[B] = item2idx.size();
                edges.push_back(vector< tuple<int, int, int> > (0));
                visited.push_back(false);
            }

            idx1 = item2idx[A], idx2 = item2idx[B];
            edges[idx1].push_back(make_tuple(idx2, b, a));
            edges[idx2].push_back(make_tuple(idx1, a, b));
        }
    }

    return 0;
}
