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
typedef pair<double, double> dd;

vector< dd > points;
vector< vector<int> > AdjList;
vector< bool > bfs_num;
vector<int> parent;
queue<int> Q;

double dist(dd &a, dd &b){
    double dx, dy;
    dx = a.first - b.first,     dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

void bfs(int source){
    Q.push(source);
    bfs_num[source] = true;
    int p, q;
    while(!Q.empty()){
        p = Q.front();  Q.pop();
        for(int i = 0; i < AdjList[p].size(); ++i){
            q = AdjList[p][i];
            if(bfs_num[q] == false){
                Q.push(q);
                bfs_num[q] = true;
                parent[q] = p;
            }
        }
    }
}

int backtrack(int q){
    int ans = 0;
    while (parent[q] != -1) {
        ++ans;
        q = parent[q];
    }
    return ans;
}

int main(){ _
    int speed, minutes;
    string line;    stringstream ss;
    double sx, sy, tx, ty, x, y;
    while(cin >> speed >> minutes){
        if(speed == 0 && minutes == 0)  break;
        points.clear();
        AdjList.clear();
        cin >> sx >> sy >> tx >> ty;
        points.push_back(dd(sx, sy));
        points.push_back(dd(tx, ty));

        cin.ignore();
        while(getline(cin, line)){
            if(line == "")  break;
            ss.clear();
            ss.str("");
            ss << line;
            ss >> x >> y;
            points.push_back(dd(x, y));
        }

        AdjList.assign(points.size(), vector<int> (0));
        for(int i = 0; i < points.size(); ++i){
            for(int j = i+1; j < points.size(); ++j){
                if(dist(points[i], points[j]) <= speed * minutes * 60){
                    AdjList[i].push_back(j);
                    AdjList[j].push_back(i);
                }
            }
        }

        bfs_num.assign(points.size(), false);
        parent.assign(points.size(), UNVISITED);
        bfs(0);
        if(bfs_num[1] == false) cout << "No." << endl;
        else{
            int n = backtrack(1);
            cout << "Yes, visiting " << n - 1<< " other holes." << endl;
        }
    }
    return 0;
}
