#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(5);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

/* 厉害了我的哥。你不告诉我这是MCBM，我想到头破也想不出来。*/

int n, m;
vector< ii > leftPoint, rightPoint;
vector< vector<int> > AdjList;
vector<double> distDiff;
vector<bool> visited;
vector<int> match;

double dist(ii &A, ii &B){
    int x1 = A.first, y1 = A.second;
    int x2 = B.first, y2 = B.second;
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int aug_path(int leftPoint){
    if(visited[leftPoint])   return 0;
    visited[leftPoint] = true;
    for(auto rightPoint : AdjList[leftPoint]){
        if(match[rightPoint] == -1 || aug_path(match[rightPoint])){
            match[leftPoint] = rightPoint;
            match[rightPoint] = leftPoint;
            return 1;
        }
    }
    return 0;
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        cin >> n >> m;
        AdjList.assign(n, vector<int> (0));
        leftPoint.assign(n, ii(0, 0));
        rightPoint.assign(m, ii(0, 0));
        distDiff.assign(n - 1, 0.0);
        match.assign(n + m, -1);

        for(int i = 0; i < n; ++i)  cin >> leftPoint[i].first >> leftPoint[i].second;
        for(int i = 0; i < m; ++i)  cin >> rightPoint[i].first >> rightPoint[i].second;
        for(int i = 0; i + 1 < n; ++i)  distDiff[i] = dist(leftPoint[i], leftPoint[i + 1]);

        for(int i = 0; i < m; ++i)
            for(int j = 0; j + 1 < n; ++j)
                if(dist(leftPoint[j], rightPoint[i]) + dist(leftPoint[j + 1], rightPoint[i]) <= distDiff[j] * 2)
                    AdjList[j].push_back(i + n);


        int MCBM = 0;
        for(int leftPoint = 0; leftPoint < n; ++leftPoint){
            visited.assign(n, false);
            MCBM += aug_path(leftPoint);
        }

        cout << n + MCBM << endl;
        for(int i = 0; i < n; ++i){
            if(i)   cout << " ";
            cout << leftPoint[i].first << " " << leftPoint[i].second;
            if(match[i] != -1)   cout << " " << rightPoint[match[i] - n].first
                                      << " " << rightPoint[match[i] - n].second;
        }
        cout << endl;
        if(tc)  cout << endl;
    }
    return 0;
}
