#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;

vector< vector<int> > AdjList;
vector<int> bfs_num;
vector<int> _bfs_num;
vector< vector<char> > result;

void hline(int n){
    cout << "+" << setfill('-') << setw(2*n-1) << "" << setfill(' ') << "+" << endl;
}

void bfs(int s, int block, vector<int>& bfs_num){
    queue<int> Q;
    Q.push(s);
    bfs_num[s] = 1;
    while(!Q.empty()){
        int node = Q.front();
        Q.pop();
        if(node == block)   continue;
        for(int i = 0; i < AdjList[node].size(); ++i){
            int neib = AdjList[node][i];
            if(bfs_num[neib] == -1){
                bfs_num[neib] = 1;
                Q.push(neib);
            }
        }
    }
}

void print(int t){
    cout << "Case " << t << ":" << endl;
    int N = result.size();

    for(int i = 0; i < N; ++i){
        hline(N);
        for(int j = 0; j < N; ++j){
            cout << "|" << result[i][j];
        }
        cout << "|" << endl;
    }

    hline(N);
}

int main(){ _
    int TC; cin >> TC;
    for(int t = 1; t <= TC; ++t){
        int N;  cin >> N;
        AdjList.clear();    AdjList.assign(N, vector<int> (0));
        result.clear();     result.assign(N, vector<char> (N, 'N'));

        int tmp;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                cin >> tmp;
                if(tmp) AdjList[i].push_back(j);
            }
        }

        bfs_num.clear();    bfs_num.assign(N, -1);
        bfs(0, -1, bfs_num);

        for(int p = 0; p < N; ++p){     // p: potential dominator
            _bfs_num.clear();   _bfs_num.assign(N, -1);
            bfs(0, p, _bfs_num);
            for(int d = 0; d < N; ++d){     // d: destination node
                if(bfs_num[d] == 1) result[d][d] = 'Y';
                if(bfs_num[d] == 1 && _bfs_num[d] == -1)  result[p][d] = 'Y';
            }
        }

        print(t);
    }
    return 0;
}
