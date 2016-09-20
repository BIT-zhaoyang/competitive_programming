#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

vector<string> cities;
vector< vector<int> > AdjMat, parent;

void print(int u, int v){
    if(parent[u][v] == u)   cout << "Path:" << cities[u] << " " << cities[v];
    else{
        print(u, parent[u][v]);
        cout << " " << cities[v];
    }
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        int n, m;   cin >> n;
        cities.assign(n, "");
        map<string, int> s2i;
        AdjMat.assign(n, vector<int> (n, 0));
        parent.assign(n, vector<int> (n, 0));

        for(int i = 0; i < n; ++i){
            cin >> cities[i];
            s2i[cities[i]] = i;
        }
        for(int i = 0; i <n; ++i)
            for(int j = 0; j < n; ++j){
                cin >> AdjMat[i][j];
                if(AdjMat[i][j] == -1)  AdjMat[i][j] = BIGINT;
                else    parent[i][j] = i;
            }

        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    if(AdjMat[i][k] + AdjMat[k][j] < AdjMat[i][j]){
                        AdjMat[i][j] = AdjMat[i][k] + AdjMat[k][j];
                        parent[i][j] = parent[k][j];
                    }

        cin >> m;
        for(int i = 0; i < m; ++i){
            int u, v;
            string employee, stru, strv;
            cin >> employee >> stru >> strv;
            u = s2i[stru], v = s2i[strv];

            if(AdjMat[u][v] != BIGINT){
                cout << "Mr " << employee << " to go from " << stru << " to " << strv << ", you will receive " << AdjMat[u][v] << " euros" << endl;
                print(u, v);
                cout << endl;
            } else {
                cout << "Sorry Mr " << employee << " you can not go from " << stru << " to " << strv << endl;
            }



        }
    }
    return 0;
}
