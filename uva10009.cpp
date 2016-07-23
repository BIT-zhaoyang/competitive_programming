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

#define UNVISITED -1
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

map<string, int> s2i;
vector<string> cities;
vector< vector<int> > children;
vector<int> parent, ans, dfs_layer, dfs_appear, dfs_node_trace;

void dfs(int p, int layer){
    dfs_appear[p] = dfs_node_trace.size();
    dfs_layer.push_back(layer);
    dfs_node_trace.push_back(p);
    int q;
    for(int i = 0; i < children[p].size(); ++i){
        q = children[p][i];
        dfs(q, layer + 1);
        dfs_layer.push_back(layer);
        dfs_node_trace.push_back(p);
    }
}

class SparseTable{
public:
    SparseTable(vector<int> _vi){
        vi = _vi;   n = vi.size();
        st.assign(n, vector<int> ((int)log2(n), 0));
        for(int i = 0; i < n; ++i)  st[i][0] = i;

        int id1, id2;
        for(int j = 1; (1<<j) < n; ++j){
            for(int i = 0; i + (1<<j) - 1 < n; ++i){
                id1 = st[i][j-1],   id2 = st[i + (1<<(j-1))][j-1];
                if(vi[id1] < vi[id2])   st[i][j] = id1;
                else    st[i][j] = id2;
            }
        }
    }

    int query(int u, int v){
        int logDiff = log2(v - u), id1, id2;
        id1 = st[u][logDiff], id2 = st[v - (1<<logDiff) + 1][logDiff];
        if(vi[id1] < vi[id2])   return id1;
        else    return id2;
    }
private:
    vector<int> vi;
    vector< vector<int> > st;
    int n;
};

void backtrack1(int node, int target){
    ans.push_back(node);
    if(node != target)  backtrack1(parent[node], target);
}

void backtrack2(int node, int target){
    if(node != target){
        backtrack2(parent[node], target);
        ans.push_back(node);
    }
}

void print(){
    int p;
    for(int i = 0; i < ans.size(); ++i){
        p = ans[i];
        cout << cities[p][0];
    }
    cout << endl;
}

int main(){ _
    int tc; cin >> tc;
    int ni, nq, id1, id2;
    string p, q;
    while(tc--){
        cin >> ni >> nq;
        // init
        s2i.clear();    cities.clear();     children.clear();    parent.clear();
        // read input
        for(int i = 0; i < ni; ++i){
            cin >> p >> q;
            if(s2i.count(p) == 0){
                s2i[p] = cities.size();
                cities.push_back(p);
                children.push_back(vector<int> (0));
                parent.push_back(-1);
            }
            if(s2i.count(q) == 0){
                s2i[q] = cities.size();
                cities.push_back(q);
                children.push_back(vector<int> (0));
                parent.push_back(-1);
            }

            id1 = s2i[p], id2 = s2i[q];
            children[id1].push_back(id2);
            parent[id2] = id1;
        }
        // DFS from Rome and build SpT
        // dfs
        dfs_appear.assign(parent.size(), UNVISITED);
        dfs_layer.clear();      dfs_node_trace.clear();
        int layer = 0;
        dfs(s2i["Rome"], layer);
        // build SpT on dfs_layer
        SparseTable st(dfs_layer);

        // answer queries
        int _p, _q, LCA;
        for(int i = 0; i < nq; ++i){
            ans.clear();
            cin >> p >> q;
            _p = s2i[p],    _q = s2i[q];
            id1 = min(dfs_appear[_p], dfs_appear[_q]);
            id2 = max(dfs_appear[_p], dfs_appear[_q]);
            LCA = dfs_node_trace[st.query(id1, id2)];
            backtrack1(_p, LCA);
            backtrack2(_q, LCA);
            print();
        }
        if(tc)  cout << endl;
    }
    return 0;
}
