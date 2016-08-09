#include <bits/stdc++.h>
#define UNVISITED -1
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
/* The hint in CP3 is really good. A very good modelling of this problem. */
map<string, vector<int> > vocab;
vector<string> words;
vector< vector< ii > > AdjList;
vector<int> dist;
priority_queue<ii, vector< ii >, greater< ii > > pq;

void dijkstra(int source){
    dist[source] = 0;
    pq.push(ii(dist[source], source));

    int u, v, d1, d2;
    while(!pq.empty()){
        u = pq.top().second,    d1 = pq.top().first;
        pq.pop();
        if(d1 > dist[u])    continue;
        for(int i = 0; i < AdjList[u].size(); ++i){
            v = AdjList[u][i].first;
            d2 = AdjList[u][i].second;
            if(d1 + d2 < dist[v]){
                dist[v] = d1 + d2;
                pq.push(ii(dist[v], v));
            }
        }
    }
}

int main(){ _
    int n;
    while(cin >> n){
        if(n == 0)  break;
        vocab.clear();
        words.assign(n + 2, "");
        AdjList.assign(n + 2, vector< ii > (0));
        // read input
        string start, end;
        cin >> start >> end;

        string lang1, lang2, word;
        for(int i = 1; i <= n; ++i){
            cin >> lang1 >> lang2 >> word;
            vocab[lang1].push_back(i);
            vocab[lang2].push_back(i);
            words[i] = word;
        }

        // build graph
        // build graph between words
        int u, v, w;
        for(auto it = vocab.begin(); it != vocab.end(); ++it){
            lang1 = it->first;
            for(int i = 0; i < vocab[lang1].size(); ++i){
                u = vocab[lang1][i];
                for(int j = 0; j < vocab[lang1].size(); ++j){
                    if(j == i)  continue;
                    v = vocab[lang1][j];
                    if(words[u][0] == words[v][0])    continue;
                    w = words[v].size();
                    AdjList[u].push_back(ii(v, w));
                }
            }
        }

        // build graph between start and end point
        // start point is set to 0, end point is set to n+1
        // connect start point to other points
        u = 0;
        for(int i = 0; i < vocab[start].size(); ++i){
            v = vocab[start][i];
            w = words[v].size();
            AdjList[u].push_back(ii(v, w));
        }
        // connect end point
        v = n+1;    w = 0;
        for(int i = 0; i < vocab[end].size(); ++i){
            u = vocab[end][i];
            AdjList[u].push_back(ii(v, 0));
        }

        // now do SSSP
        dist.assign(n+2, INT_MAX);
        dijkstra(0);
        if(dist[n+1] == INT_MAX)    cout << "impossivel" << endl;
        else    cout << dist[n+1] << endl;
    }
    return 0;
}
