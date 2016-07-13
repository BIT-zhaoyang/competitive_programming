#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define N 100010
using namespace std;

/* This is a very creative problem. It is not solved by MST as hintted in CP3, but simply DSU. One critical observation is that, N mixtures having N compounds means a loop consists of N vertices. No matter how the loop is formed, as long as it is a loop, it's a N mixtures with N components.*/

typedef long long int64;
typedef pair<int, int> ii;

class DSU{
public:
    DSU(int n){
        p.assign(n, 0);
        for(int i = 0; i < n; ++i)  p[i] = i;
        r.assign(n, 0);
    }

    int findParent(int u){
        return (u == p[u]) ? u : (p[u] = findParent(p[u]));
    }

    bool isSameSet(int u, int v){
        return findParent(u) == findParent(v);
    }

    void link(int u, int v){
        int x = findParent(u), y = findParent(v);
        if(x != y){
            if(r[x] > r[y]) p[y] = x;
            else{
                p[x] = y;
                if(r[x] == r[y])    ++r[y];
            }
        }
    }

private:
    vector<int> r, p;
};

int main(){ _
    int ans = 0, u, v;
    while(cin >> u >> v){
        ans = 0;
        DSU dsu(N);
        dsu.link(u, v);

        while(cin >> u){
            if(u == -1) break;
            else    cin >> v;

            if(!dsu.isSameSet(u, v))    dsu.link(u, v);
            else    ++ans;
        }

        cout << ans << endl;
    }

    return 0;
}
