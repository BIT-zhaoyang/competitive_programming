#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
typedef pair< double, pair<int, int> > dii;

/* A better representation is compress points. By compressing points, instead of recording the acutaul positions of these points, we just use idx 0~N-1 to represent them after building the graph. Then, we do dijkstra to see if the N-1th point can be reached or not. */

int w, h;
vector< ii > points;
map< ii, vector< ii > > adjlist;
map< ii, double> dist;
priority_queue< dii, vector< dii >, greater< dii > > pq;

int euc(ii u, ii v){
    int x = u.first - v.first,  y = u.second - v.second;
    return ceil(sqrt(x*x + y*y));
}

double euc2(ii u, ii v){
    int x = u.first - v.first,  y = u.second - v.second;
    return sqrt(x*x + y*y);
}

void dijkstra(ii source){
    dist[source] = 0.0;
    pq.push(dii(dist[source], source));

    ii u, v;    double d1, d2;
    while(!pq.empty()){
        d1 = pq.top().first,    u = pq.top().second;
        pq.pop();
        if(d1 > dist[u])    continue;
        for(int i = 0; i < adjlist[u].size(); ++i){
            v = adjlist[u][i];
            d2 = euc2(u, v);
            if(d1 + d2 < dist[v]){
                dist[v] = d1 + d2;
                pq.push(dii(dist[v], v));
            }
        }
    }
}

int main(){ _
    while(cin >> w >> h){
        int n;  cin >> n;
        double dx, dy;  int x, y;

        points.assign(n, ii(0, 0));
        for(int i = 0; i < n; ++i){
            cin >> dx >> dy;
            x = (int)(dx * 100),  y = (int)(dy * 100);
            points[i] = ii(x, y);
        }

        ii source(0, 0),    dest(w*100, h*100);
        for(int i = 0; i < points.size(); ++i){
            dist[points[i]] = 1e9;
            if(euc(source, points[i]) <= 150)   adjlist[source].push_back(points[i]);
            if(euc(points[i], dest) <=  150)    adjlist[points[i]].push_back(dest);

            for(int j = i+1; j < points.size(); ++j){
                if(euc(points[i], points[j]) <= 150){
                    adjlist[points[i]].push_back(points[j]);
                    adjlist[points[j]].push_back(points[i]);
                }
            }
        }

        double dlimit;   cin >> dlimit;
        dist[dest] = 1e9;
        dijkstra(source);

        if(dist[dest] > dlimit*100)  cout << "Boom!" <<endl;
        else    cout << "I am lucky!" << endl;
    }
    return 0;
}
