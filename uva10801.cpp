#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

int n, m;
vector<int> T, dist;
vector< vector<int> > ele2floor, floor2ele;
priority_queue< iii, vector< iii >, greater< iii > > pq;

void dijkstra(){
    int currF = 0, nextF, currEle, nextEle, d1, d2;
    for(int i = 0; i < floor2ele[currF].size(); ++i){
        currEle = floor2ele[currF][i];
        pq.push(iii(0, currF, currEle));
    }

    int extra;
    while(!pq.empty()){
        tie(d1, currF, currEle) = pq.top(); pq.pop();
        if(d1 > dist[currF])    continue;
        for(int i = 0; i < floor2ele[currF].size(); ++i){
            nextEle = floor2ele[currF][i];
            if(nextEle == currEle)  extra = 0;
            else    extra = 60;

            for(int j = 0; j < ele2floor[nextEle].size(); ++j){
                nextF = ele2floor[nextEle][j];
                d2 = abs(nextF - currF) * T[nextEle];
                if(d1 + d2 + extra < dist[nextF]){
                    dist[nextF] = d1 + d2 + extra;
                    pq.push(iii(dist[nextF], nextF, nextEle));
                }
            }
        }
    }
}

int main(){ _
    int F;
    string line;    stringstream ss;
    while(cin >> n >> m){
        T.assign(n, 0);
        dist.assign(100, INT_MAX);
        floor2ele.assign(100, vector<int> (0));
        ele2floor.assign(n, vector<int> (0));
        for(int i = 0; i < n; ++i)  cin >> T[i];    cin.ignore();
        for(int i = 0; i < n; ++i){
            getline(cin, line);
            ss.clear(); ss.str("");
            ss << line;
            while(ss >> F){
                floor2ele[F].push_back(i);
                ele2floor[i].push_back(F);
            }
        }

        dijkstra();
        if(dist[m] == INT_MAX)  cout << "IMPOSSIBLE" << endl;
        else    cout << dist[m] << endl;
    }
    return 0;
}
