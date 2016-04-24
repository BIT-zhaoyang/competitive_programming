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
        p.assign(n, 0);
        r.assign(n, 0);
        for(int i = 0; i < n; ++i)  p[i] = i;
        nSets = n;
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
        } else {
            p[x] = y;
            if(r[x] == r[y])    ++r[y];
        }
        --nSets;
    }

    int getNumSets(){
        return nSets;
    }
};

int main(){ _
    int TC; cin >> TC;
    while(TC--){
        int P, T;   cin >> P >> T;
        string line;
        cin.ignore();

        UnionFind ans(P+1);
        vector< vector<bool> > people(P+1, vector<bool> (T+1, false));

        int a, b;
        while(getline(cin, line)){
            if(line == "")  break;
            stringstream ss;
            ss << line;

            ss >> a >> b;
            people[a][b] = true;
        }


        for(int i = 1; i < P; ++i){
            for(int j = i+1; j <= P; ++j){
                if(people[i] == people[j])  ans.unionSet(i, j);
            }
        }

        cout << ans.getNumSets() - 1 << endl;
        if(TC)   cout << endl;
    }
    return 0;
}
