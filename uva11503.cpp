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
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

class UnionFind{
private:
    vector<int> p, r, s;
public:
    UnionFind(int n){
        r.assign(n, 0);
        p.assign(n, 0);
        for(int i = 0; i < n; ++i)  p[i] = i;
        s.assign(n, 1);
    }

    int findSet(int n){
        return (p[n] == n) ? p[n] : (p[n] = findSet(p[n]));
    }

    bool isSameSet(int a, int b){
        return findSet(a) == findSet(b);
    }

    void unionSet(int a, int b){
        if(isSameSet(a, b)) return;

        int x = findSet(a), y = findSet(b);
        if(r[x] > r[y]){
            p[y] = x;
            s[x] += s[y];
        } else {
            p[x] = y;
            s[y] += s[x];
            if(r[x] == r[y])    ++r[y];
        }
    }

    int getSize(int a){
        return s[findSet(a)];
    }
};

int main(){ _
    int TC; cin >> TC;
    while(TC--){
        int m;  cin >> m;
        UnionFind network(1e5);
        map<string, int> name;
        string a, b;
        int nNames = 0;
        for(int i = 0; i < m; ++i){
            cin >> a >> b;
            if(!name.count(a)){
                name[a] = nNames;
                ++nNames;
            }

            if(!name.count(b)){
                name[b] = nNames;
                ++nNames;
            }

            network.unionSet(name[a], name[b]);
            cout << network.getSize(name[a]) << endl;;
        }
    }
    return 0;
}
