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

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(2);
using namespace std;

typedef pair<int, int> ii;
class DSU{
public:
    DSU(int n){
        p.assign(n, 0); r.assign(n, 0);
        for(int i = 0; i < n; ++i)  p[i] = i;
    }
    int findParent(int u){  return (p[u] == u) ? u : (p[u] = findParent(p[u]));}
    bool isSameSet(int u, int v){return findParent(u) == findParent(v);}
    void link(int u, int v){
        int x = findParent(u), y = findParent(v);
        if(x != y){
            if(r[x] > r[y]) p[y] = x;
            else{
                p[x] = y;
                if(r[x] == r[y])    ++r[y];}}}
private:
    vector<int> p, r;
};

vector< ii > points;
vector< tuple<int, int, double> > edges;

double dist(ii &A, ii &B){
    int x = A.first - B.first, y = A.second - B.second;
    return sqrt(x*x + y*y);
}

bool mysort(tuple<int, int, double> &A, tuple<int, int, double> &B){
    return get<2>(A) < get<2>(B);
}

int main(){ _
    int tc; cin >> tc;
    int k, n, u, v, count; double w, ans;
    while(tc--){
        cin >> k >> n;
        DSU dsu(n);
        points.assign(n, ii(0, 0));
        edges.assign(n*(n-1)/2, make_tuple(0, 0, 0));
        for(int i = 0; i < n; ++i)  cin >> points[i].first >> points[i].second;

        count = 0;
        for(int i = 0; i < n; ++i)  for(int j = i+1; j < n; ++j)
            edges[count++] = make_tuple(i, j, dist(points[i], points[j]));
        sort(edges.begin(), edges.end(), mysort);

        for(int i = 0; i < edges.size() && n > k; ++i){
            tie(u, v, w) = edges[i];
            if(!dsu.isSameSet(u, v)){
                ans = w;
                dsu.link(u, v);
                --n;
            }
        }
        cout << fixed << ans << endl;
    }
    return 0;
}
