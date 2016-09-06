#include <bits/stdc++.h>
#define UNVISITED -1
#define BIGINT 1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

vector<string> cities;
map<string, int> m2i;
string stru, strv, line;
vector< vector<string> > roads(100, vector<string> (100, ""));
vector< vector<int> > AdjMat(100, vector<int> (100, BIGINT));
vector< vector<int> > parent(100, vector<int> (100, 0));

void printtitle(){
    cout << endl << endl;

    cout << left << setfill(' ');
    cout << setw(21) << "From";
    cout << setw(21) << "To";
    cout << setw(11) << "Route";
    cout << setw(5) << "Miles" << endl;

    cout << right << setfill('-');
    cout << setw(21) << " ";
    cout << setw(21) << " ";
    cout << setw(11) << " ";
    cout << setw(5) << "" << endl;

    cout << left << setfill(' ');
}

void print(int u, int v){
    if(parent[u][v] == u){
        cout << setw(21) << cities[u];
        cout << setw(21) << cities[v];
        cout << setw(11) << roads[u][v];
        cout << setw(5) << right << AdjMat[u][v] << endl;
        cout << left;
    } else {
        print(u, parent[u][v]);
        u = parent[u][v];
        print(parent[u][v], v);
    }
}

void printtail(int u, int v){
    cout << right << setw(58) << "-----" << endl;
    cout << setw(42) << "";
    cout << left << setw(11) << "Total";
    cout << right << setw(5) << AdjMat[u][v] << endl;
}

int main(){ _
    int u, v, last = 0, curr = 0, roadlen = 0;
    string roadname;

    // build graph
    while(getline(cin, line)){
        if(line == "")  break;
        last = curr = 0;
        curr = line.find(",");
        stru = line.substr(last, curr - last);
        if(m2i.count(stru)) u = m2i[stru];
        else{
            cities.push_back(stru);
            m2i[stru] = cities.size() - 1;
        }

        last = curr + 1;
        curr = line.find(",", last);
        strv = line.substr(last, curr - last);
        if(m2i.count(strv)) v = m2i[strv];
        else{
            cities.push_back(strv);
            m2i[strv] = cities.size() - 1;
        }

        last = curr + 1;
        curr = line.find(",", last);
        roadname = line.substr(last, curr - last);

        last = curr + 1;
        roadlen = stoi(line.substr(last));


        u = m2i[stru];
        v = m2i[strv];
        if(roadlen < AdjMat[u][v]){
            AdjMat[u][v] = AdjMat[v][u] = roadlen;
            roads[u][v] = roads[v][u] = roadname;
            parent[u][v] = u;
            parent[v][u] = v;
        }
    }

    // floyd-warshall
    int n = cities.size();
    for(int k = 0; k < n; ++k)
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(AdjMat[i][k] + AdjMat[k][j] < AdjMat[i][j]){
                    AdjMat[i][j] = AdjMat[i][k] + AdjMat[k][j];
                    parent[i][j] = parent[k][j];
                }

    // read queries
    while(getline(cin, line)){
        last = 0, curr = 0;
        curr = line.find(",");
        stru = line.substr(last, curr - last);
        strv = line.substr(curr + 1);
        u = m2i[stru];
        v = m2i[strv];
        // cout << stru << ", " << strv << endl;

        printtitle();
        print(u, v);
        printtail(u, v);
    }

    return 0;
}
