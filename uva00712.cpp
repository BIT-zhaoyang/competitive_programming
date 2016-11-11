#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int depth, tc = 0;
    while(cin >> depth, depth){
        cout << "S-Tree #" << ++tc << ":" << endl;
        vector<int> leaf(1 << (depth + 1), 0);
        vector<int> layer(depth, 0);

        char ch; int order;
        for(int i = 0; i < depth; ++i){
            cin >> ch >> order;
            layer[i] = order - 1;
        }
        for(int i = (1 << depth); i < leaf.size(); ++i){
            cin >> ch;
            leaf[i] = ch - '0';
        }

        int nQ; cin >> nQ;
        while(nQ--){
            string query;   cin >> query;
            int idx = 1;
            for(int currLayer = 0; currLayer < layer.size(); ++currLayer){
                int currOrder = layer[currLayer];
                if(query[currOrder] == '1') idx = (idx << 1) + 1;
                else    idx = (idx << 1);
            }
            cout << leaf[idx];
        }
        cout << endl << endl;
    }
    return 0;
}
