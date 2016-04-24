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
    vector<int> r, s, p;
public:
    UnionFind(int n){
        r.assign(n, 0);
        s.assign(n, 1);
        p.assign(n, 0);
        for(int i = 0; i < n; ++i)  p[i] = i;
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

    int getSize(int i){
        return s[findSet(i)];
    }
};

int main(){ _
    int N, M;
    while(cin >> N >> M){
        if(N == 0 && M == 0)    break;

        UnionFind chain(N);
        map<string, int> creature;
        string temp;
        for(int i = 0; i < N; ++i){
            cin >> temp;
            creature[temp] = i;
        }

        string a, b;
        for(int i = 0; i < M; ++i){
            cin >> a >> b;
            chain.unionSet(creature[a], creature[b]);
        }

        int maxSize = 0;
        for(map<string, int>::iterator it = creature.begin(); it != creature.end(); ++it){
            maxSize = max(maxSize, chain.getSize(it->second));
        }

        cout << maxSize << endl;
    }
    return 0;
}
