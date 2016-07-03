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

int n, m;
map<string, int> s2i;
vector<int> counter;
vector<string> vs;
vector< vector<int> > edges;
string name, a, b;
int ai, bj;

void bfs2(){
    for(int i = 0; i < n; ++i){
        if(counter[i] == 0){
            cout << " " << vs[i];
            --counter[i];   // This equals setting i to be visited. since when we visit it, it has counter[i] = 0. Now we decrease it by one, it becomes counter[i] = -1 so we will not visit it again.
            for(int j = 0; j < edges[i].size(); ++j){
                --counter[edges[i][j]];
            }
            bfs2();
        }
    }
}


int main(){ _
    int tc = 0;
    while(cin >> n){
        s2i.clear();
        vs.assign(n, "");
        counter.assign(n, 0);
        edges.assign(n, vector<int> (0));

        for(int i = 0; i < n; ++i){
            cin >> name;
            s2i[name] = i;
            vs[i]  = name;
        }

        cin >> m;
        for(int i = 0; i < m; ++i){
            cin >> a >> b;
            ai = s2i[a],    bj = s2i[b];
            edges[ai].push_back(bj);
            counter[bj] += 1;
        }

        cout << "Case #" << ++tc << ": Dilbert should drink beverages in this order:";
        bfs2();
        cout << "." << endl << endl;

    }
    return 0;
}
