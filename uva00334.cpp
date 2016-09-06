#include <bits/stdc++.h>
#define UNVISITED -1
#define BIGINT 1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int NC, NE, NM, tc = 0;
    while (cin >> NC, NC){
        map<string, int> s2i;
        vector<string> events;
        vector< ii > AdjList;
        string e1, e2;
        int u, v;

        for(int i = 0; i < NC; ++i){
            cin >> NE;

            cin >> e1;
            if(s2i.count(e1) == 0){
                events.push_back(e1);
                s2i[e1] = events.size() - 1;
            }
            u = s2i[e1];
            for(int j = 1; j < NE; ++j){
                cin >> e2;
                if(s2i.count(e2) == 0){
                    events.push_back(e2);
                    s2i[e2] = events.size() - 1;
                }
                v = s2i[e2];
                AdjList.push_back(ii(u, v));
                u = v;
            }
        }

        int n = events.size();
        vector< vector<bool> > AdjMat(n, vector<bool> (n, false));
        for(int i = 0; i < AdjList.size(); ++i){
            u = AdjList[i].first, v = AdjList[i].second;
            AdjMat[u][v] = true;
        }

        cin >> NM;
        for(int i = 0; i < NM; ++i){
            cin >> e1 >> e2;
            u = s2i[e1], v = s2i[e2];
            AdjMat[u][v] = true;
        }

        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    AdjMat[i][j] = AdjMat[i][j] | (AdjMat[i][k] & AdjMat[k][j]);

        int total = 0;
        vector< ii > ans;
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
                if(!(AdjMat[i][j] || AdjMat[j][i])){
                    total += 1;
                    ans.push_back(ii(i, j));
                }

        cout << "Case " << ++tc << ", ";
        if(total)   cout << total << " concurrent events:" << endl;
        else    cout << "no concurrent events." << endl;
        for(int i = 0; i < min((int)ans.size(), 2); ++i){
            u = ans[i].first, v = ans[i].second;
            cout << "(" << events[u] << "," << events[v] << ") ";
        }
        if(total)   cout << endl;

    }
    return 0;
}
