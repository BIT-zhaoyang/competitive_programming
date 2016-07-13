#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;
/* This is indeed a very good problem. If the CP3 book doesn't tell me this uses MST, I think I really can't solve it in a short time... The idea to solve the problem is as follow:
    1. There are N keys. Each pair of keys can be connected and the distance is the number of rolls to transform from A to B. We can compute this distance for all pairs. Then, to unlock all the N keys, we just need to find a MST since moving along the MST gives us the minimum number of rolss. (This is because JUMP between these unlocked numbers costs nothing).
    2. After building the MST, we need to select the root. The root is the number which needs fewest rolls to turn 0000 to the selected number.
*/
vector<int> keys;
vector< tuple<int, int, int> > edges;

class DSU{
public:
    DSU(int n){
        p.assign(n, 0);
        for(int i = 0; i < n; ++i)  p[i] = i;
        r.assign(n, 0);
    }

    bool isSameSet(int u, int v){
        return findParent(u) == findParent(v);
    }

    int findParent(int u){
        return (u == p[u]) ? u : (p[u] = findParent(p[u]));
    }

    void link(int u, int v){
        int x = findParent(u), y = findParent(v);
        if(x != y){
            if(r[x] > r[y]) p[y] = x;
            else{
                p[x] = y;
                if(r[x] == r[y])    r[y] += 1;
            }
        }
    }

private:
    vector<int> p, r;
};

bool mysort(tuple<int, int, int> &A, tuple<int, int, int> &B){
    return get<2>(A) < get<2>(B);
}

int dist(int A, int B){
    int ans = 0, a, b;
    for(int i = 0; i < 4; ++i){
        a = A % 10, b = B % 10;
        ans += min((a + 10 - b) % 10, (b + 10 - a) % 10);
        A /= 10, B /= 10;
    }

    return ans;
}

int main(){ _
    int tc, N, from, to, w, ans; cin >> tc;
    while(tc--){
        cin >> N;
        keys.assign(N, 0);
        edges.assign(N*N, make_tuple(0, 0, 0));
        for(int i = 0; i < N; ++i)  cin >> keys[i];
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                edges[i*N + j] = make_tuple(i, j, dist(keys[i], keys[j]));
            }
        }

        sort(edges.begin(), edges.end(), mysort);

        ans = INT_MAX;
        for(int i = 0; i < keys.size(); ++i){
            ans = min(ans, dist(0, keys[i]));
        }

        DSU dsu(N);
        for(int i = 0; i < edges.size(); ++i){
            tie(from, to, w) = edges[i];
            if(!dsu.isSameSet(from, to)){
                dsu.link(from, to);
                ans += w;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
