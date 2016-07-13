#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(2);
#define UNVISITED -1
using namespace std;

typedef long long int64;
vector<bool> taken;
priority_queue< pair<double, int> > pq;
vector< vector< double> > AdjList;
vector< pair< double, double> > points;

void process(int u){
    taken[u] = true;

    int v;
    for(int i = 0; i < AdjList[u].size(); ++i){
        if(i == u)  continue;
        v = i;  // for this problem, we can only use edge matrix since it's fully connecetd
        if(!taken[v])   pq.push(make_pair(-AdjList[u][v], -v)); // default setting for pq in STL
            // is max heap, so we need to negate the weight AdjList[u][v]
    }
}

double dist(pair<double, double> &A, pair<double, double> &B){
    double ans = 0, x = A.first - B.first, y = A.second - B.second;
    ans = sqrt(x*x + y*y);
    return ans;
}

int main(){ _
    int tc, n, u; cin >> tc;
    double w;
    while(tc--){
        cin >> n;
        taken.assign(n, false);
        points.assign(n, make_pair(0.0, 0.0));
        AdjList.assign(n, vector<double> (n, DBL_MAX));

        for(int i = 0; i < n; ++i)  cin >> points[i].first >> points[i].second;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i == j)  continue;
                AdjList[i][j] = dist(points[i], points[j]);
            }
        }

        pq.push(make_pair(0.0, 0));

        double ans = 0.0;
        while(!pq.empty()){
            pair<double, int> pii = pq.top();
            pq.pop();
            u = -pii.second, w = -pii.first;
            if(!taken[u]){
                ans += w;
                process(u);
            }
        }

        cout << fixed << ans << endl;
        if(tc)  cout << endl;
    }
    return 0;
}
