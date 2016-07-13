#include <algorithm>
#include <bitset>
#include <cstring>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <sstream>
#include <vector>

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef pair<int, int> ii;

class DSU{
public:
    DSU(int n){
        p.assign(n, 0); r.assign(n, 0);
        for(int i = 0; i < n; ++i)  p[i] = i;
    }
    int findParent(int u){  return (p[u] == u) ? u : (p[u] = findParent(p[u]));}
    bool isSameSet(int u, int v){   return findParent(u) == findParent(v); }
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
    vector<int> p, r;
};

vector< ii > points;
vector< tuple<int, int, double> > edges;

double dist(ii &A, ii &B){
    long long x = A.first - B.first, y = A.second - B.second;
    return sqrt(x*x + y*y);
}

bool mysort(tuple<int, int, double> &A, tuple<int, int, double> &B){
    return get<2>(A) < get<2>(B);
}

int main(){ _
    int tc, x, y, k; cin >> tc;
    while(tc--){
        points.clear();
        edges.clear();
        cin >> k;
        while(cin >> x){
            if(x == -1) break;
            else    cin >> y;
            points.push_back(ii(x, y));
        }

        int n = points.size();
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                edges.push_back(make_tuple(i, j, dist(points[i], points[j])));
            }
        }

        sort(edges.begin(), edges.end(), mysort);

        DSU dsu(n);
        int u, v;   double w, ans = 0;
        for(int i = 0; i < edges.size() && n > k; ++i){
            tie(u, v, w) = edges[i];
            if(!dsu.isSameSet(u, v)){
                --n;    ans = w;
                dsu.link(u, v);
            }
        }

        cout << int(ceil(ans)) << endl;
    }
    return 0;
}
