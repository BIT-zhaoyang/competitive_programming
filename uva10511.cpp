#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
/* This is such a hard implementation. The lack of MAXN is one of the main difficulty. I referred to this program: bit.ly/2dbqr1B . If the MAXN is given, it would be a little easier to implement the program.

Another point is that, though it's good to physially seperate the index of nodes on each side of a bipartite graph, it's not necessary to do so. This program mixed the index of these nodes and it still works.(Of course it will work...)

Finally, those M(), P(), C() tiny function is really useful. These functions make the code more readable and tidy. So the lesson is, hide trivial, verbose operations into tiny helper functions.
*/

#define MAXN 1300

const int s = 0, t = 1;
int n, f, mf;
map<string, int> man, party, club;
int M(string &s){ if(man.count(s))  return man[s];  else    return man[s] = n++;}
int P(string &s){ if(party.count(s))  return party[s];  else    return party[s] = n++;}
int C(string &s){ if(club.count(s))  return club[s];  else    return club[s] = n++;}

vector<int> parent;
vector< vector<int> > res;
void augment(int v, int minEdge){
    if(v == s){ f = minEdge;    return;}
    else if(parent[v] != -1){
        augment(parent[v], min(minEdge, res[parent[v]][v]));
        res[parent[v]][v] -= f; res[v][parent[v]] += f;
    }
}

void EdmondKarp(){
    f = mf = 0;
    while(true){
        queue<int> Q;   Q.push(s);
        parent.assign(n, -1);
        while(!Q.empty()){
            int u = Q.front(); Q.pop();
            if(u == t)  break;
            for(int v = 0; v < n; ++v)
                if(res[u][v] > 0 && parent[v] == -1)
                    parent[v] = u, Q.push(v);
        }

        f = 0;
        augment(t, BIGINT);
        mf += f;

        if(f == 0)  break;
    }
}

void print(){
    for(auto mit = man.begin(); mit != man.end(); ++mit)
        for(auto cit = club.begin(); cit != club.end(); ++cit)
            if(res[cit->second][mit->second]){
                cout << mit->first << " " << cit->first << endl;
                break;
            }
}


int main(){ _
    int tc; cin >> tc;  cin.ignore();
    string line;    getline(cin, line);
    while(tc--){
        n = 2;
        man.clear(), party.clear(), club.clear();
        res.assign(MAXN, vector<int> (MAXN, 0));

        while(getline(cin, line)){
            if(line == "")  break;
            stringstream ss(line);
            string m, p, c;
            ss >> m >> p;
            res[P(p)][M(m)] = 1;
            while(ss >> c)  res[M(m)][C(c)] = 1, res[C(c)][t] = 1;
        }

        int maxC = (club.size() - 1) / 2;
        for(auto it = party.begin(); it != party.end(); ++it)
            res[s][it->second] = maxC;

        // EdmondKarp
        EdmondKarp();

        if(mf != club.size())   cout << "Impossible." << endl;
        else    print();

        if(tc)  cout << endl;
    }
    return 0;
}
