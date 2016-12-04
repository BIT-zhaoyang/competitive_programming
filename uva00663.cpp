#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

/* Ugly code !!! */

int n;
vector<bool> visited;
vector<int> match, coord;
vector< list<int> > AdjList;

int aug_path(int l){
    if(visited[l])  return 0;
    visited[l] = true;
    for(auto r : AdjList[l]){
        if(match[r] == -1 || aug_path(match[r])){
            match[r] = l;
            match[l] = r;
            return 1;
        }
    }
    return 0;
}

int MCBM(){
    int MCBM = 0;
    match.assign(n * 2, -1);
    for(int i = 0; i < n; ++i){
        visited.assign(n, false);
        MCBM += aug_path(i);
    }
    return MCBM;
}

int main(){ _
    int tc = 0;
    while(cin >> n){
        if(n == 0)  break;
        match.assign(n * 2, -1);
        AdjList.assign(n * 2, list<int> (0));
        coord.assign(4 * n, 0);
        for(int i = 0; i < n; ++i){
            cin >> coord[4 * i];
            cin >> coord[4 * i + 1];
            cin >> coord[4 * i + 2];
            cin >> coord[4 * i + 3];
        }
        for(int i = 0; i < n; ++i){
            int x, y;   cin >> x >> y;
            for(int j = 0; j < n; ++j){
                if(x > coord[4 * j] && x < coord[4 * j + 1]
                && y > coord[4 * j + 2] && y < coord[4 * j + 3]){
                    AdjList[j].push_back(i + n);
                    AdjList[i + n].push_back(j);
                }
            }
        }

        int nMatch = MCBM();

        cout << "Heap " << ++tc << endl;
        if(nMatch != n)   cout << "none" << endl;
        else {
            vector< pair<char, int> > candidate, ans;
            for(int i = 0; i < n; ++i){
                candidate.push_back(make_pair(char(i + 'A'), match[i]));
            }

            // check if each edge in the potential solution is not replacable
            for(int left = 0; left < n; ++left){
                int right = candidate[left].second;
                for(auto it = AdjList[left].begin(); it != AdjList[left].end(); ++it)
                    if(*it == right){
                        AdjList[left].erase(it);
                        break;
                    }

                int nMatch = MCBM();
                if(nMatch != n) ans.push_back(make_pair(char(left + 'A'), candidate[left].second));
                AdjList[left].push_back(right);
            }

            if(ans.size() == 0) cout << "none" << endl;
            else{
                for(int i = 0; i < ans.size(); ++i){
                    if(i)   cout << " ";
                    cout << "(" << ans[i].first << "," << ans[i].second - n + 1 << ")";
                }
                cout << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
