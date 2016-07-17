#include <algorithm>
#include <bitset>
#include <cstring>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <sstream>
#include <vector>

#define UNVISITED -1
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

vector<string> words;
vector< vector<int> > AdjList;
map<string, int> s2i;
queue<int> Q;
vector<int> D;

int dist(int u, int v){
    string a = words[u], b = words[v];
    int d = 0;
    for(int i = 0; i < min(a.size(), b.size()); ++i){
        if(a[i] != b[i])    d += 1;
    }
    d += max(b.size(), a.size()) - min(a.size(), b.size());
    return d;
}

void bsf(int s){
    Q.push(s);  D[s] = 0;
    int p, q;
    while(!Q.empty()){
        p = Q.front();  Q.pop();
        for(int i = 0; i < AdjList[p].size(); ++i){
            q = AdjList[p][i];
            if(D[q] == UNVISITED){
                D[q] = D[p] + 1;
                Q.push(q);
            }
        }
    }
}

int main(){ _
    string str1, str2, line;
    stringstream ss;
    int tc, n = 0;  cin >> tc;
    while(tc--){
        n = 0;
        words.clear();
        s2i.clear();

        while(cin >> str1){
            if(str1 == "*")  break;
            words.push_back(str1);
            s2i[str1] = n++;
        }

        AdjList.assign(n, vector<int> (0));
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                int d = dist(i, j);
                if(d == 1){
                    AdjList[i].push_back(j);
                    AdjList[j].push_back(i);}}}

        cin.ignore();
        while(getline(cin, line)){
            if(line == "")  break;
            ss.clear();
            ss.str("");
            ss << line; ss >> str1 >> str2;
            D.assign(n, UNVISITED);
            bsf(s2i[str1]);
            cout << str1 << " " << str2 << " " << D[s2i[str2]] << endl;
        }

        if(tc)  cout << endl;
    }
    return 0;
}
