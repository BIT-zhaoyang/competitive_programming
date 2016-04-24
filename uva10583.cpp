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
    vector<int> p, r;
    int nSets;
public:
    UnionFind(int n){
        r.assign(n, 0);
        p.assign(n, 0);
        for(int i = 0; i < n; ++i)  p[i] = i;
        nSets = n;
    }

    int findSet(int i){
        return (p[i] == i) ? p[i] : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int a, int b){
        return findSet(a) == findSet(b);
    }

    void unionSet(int a, int b){
        if(isSameSet(a, b)) return;

        int x = findSet(a), y = findSet(b);
        if(r[x] > r[y]){
            p[y] = x;
        } else {
            p[x] = y;
            if(r[x] == r[y]) ++r[y];
        }

        --nSets;
    }

    int getNumOfSets(){
        return nSets;
    }
};

int main(){ _
    int T = 1, n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0)    break;
        UnionFind students(n);

        int a, b;
        for(int i = 0; i < m; ++i){
            cin >> a >> b;
            students.unionSet(a, b);
        }

        cout << "Case " << T << ": ";
        cout << students.getNumOfSets() << endl;
        ++T;
    }
    return 0;
}
