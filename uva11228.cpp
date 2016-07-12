#include <algorithm>
#include <bitset>
#include <cstring>
#include <climits>
#include <cmath>
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

vector< vector<double> > AdjList;
vector< pair<int, int> > cities;
priority_queue< pair<double, int> > pq;
vector<bool> taken;

void process(int u){
    taken[u] = true;

    double w;   int v;
    for(int i = 0; i < AdjList[u].size(); ++i){
        w = AdjList[u][i], v = i;
        if(!taken[v]){
            pq.push(make_pair(-w, -v));
        }
    }
}

double dist(pair<int, int> &A, pair<int, int> &B){
    int x = A.first - B.first, y = A.second - B.second;
    return sqrt(x*x + y*y);
}

int main(){ _
    int TC, n, r, nState, u; cin >> TC;
    double lenRoad, lenRail, w;
    for(int tc = 1; tc <= TC; ++tc){
        cout << "Case #" << tc << ": ";

        cin >> n >> r;
        cities.assign(n, make_pair(0, 0));
        AdjList.assign(n, vector<double> (n, 0.0));
        taken.assign(n, false);
        nState = 1;
        lenRoad = lenRail = 0.0;

        for(int i = 0; i < n; ++i)  cin >> cities[i].first >> cities[i].second;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                AdjList[i][j] = dist(cities[i], cities[j]);
            }
        }


        pq.push(make_pair(0.0, 0));
        while(!pq.empty()){
            pair<double, int> next = pq.top();
            pq.pop();
            w = -next.first, u = -next.second;
            if(!taken[u]){
                if(w > r){
                    nState += 1;
                    lenRail += w;
                } else {
                    lenRoad += w;
                }
                process(u);
            }
        }

        cout << nState << " " << lround(lenRoad) << " " << lround(lenRail) << endl;

    }
    return 0;
}
