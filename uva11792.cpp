#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

vector<int> counter, dist, important;
vector< vector<int> > AdjList;
queue<int> Q;

void bfs(int source){
    Q.push(source);
    dist[source] = 0;

    int p, q;
    while(!Q.empty()){
        p = Q.front();
        Q.pop();
        for(int i = 0; i < AdjList[p].size(); ++i){
            q = AdjList[p][i];
            if(dist[q] == UNVISITED){
                dist[q] = dist[p] + 1;
                Q.push(q);
            }
        }
    }
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        int N, L, last, curr;
        cin >> N >> L;
        // init
        important.clear();
        counter.assign(N+1, 0);
        AdjList.assign(N+1, vector<int> (0));
        // get input
        for(int i = 0; i < L; ++i){
            cin >> last;
            ++counter[last];
            while(cin >> curr){
                if(curr == 0)    break;

                ++counter[curr];
                AdjList[last].push_back(curr);
                AdjList[curr].push_back(last);
                last = curr;
            }
        }
        // find important stations
        for(int i = 1; i <= N; ++i)
            if(counter[i] > 1)    important.push_back(i);

        // bfs from all important station
        int minTime = INT_MAX, minIdx = -1, accTime;
        for(int i = 0; i < important.size(); ++i){
            dist.assign(N+1, UNVISITED);
            bfs(important[i]);
            accTime = 0;
            for(int j = 0; j < important.size(); ++j){
                accTime += dist[important[j]];
            }
            if(accTime < minTime){
                minTime = accTime;
                minIdx = important[i];
            }
        }

        cout << "Krochanska is in: " << minIdx << endl;
    }
    return 0;
}
