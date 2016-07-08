#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;

int n, dfsCounter;
vector<int> dfs_num, dfs_low, S;
vector<bool> visiting, appear;
vector< vector<int> > AdjList;
vector< vector<int> > ans;
char ch[5], answer;

void init(int n){
    dfs_num.assign(26, UNVISITED);
    dfs_low.assign(26, UNVISITED);
    visiting.assign(26, false);
    appear.assign(26, false);
    AdjList.assign(26, vector<int> (0));
    ans.clear();
    S.clear();
    dfsCounter = 0;
}

void SCC(int p);
bool mysort(vector<int> &a, vector<int> &b){
    return a[0] < b[0];
}

int main(){ _
    int tc = 0;
    while(cin >> n){
        if(n == 0)  break;
        if(tc++)  cout << endl;

        init(n);

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < 5; ++j){
                cin >> ch[j];
                appear[ch[j] - 'A'] = true;
            }
            cin >> answer;

            for(int j = 0; j < 5; ++j){
                if(ch[j] == answer) continue;
                AdjList[answer - 'A'].push_back(ch[j] - 'A');
            }
        }

        for(int i = 0; i < 26; ++i){
            if(appear[i] && dfs_num[i] == UNVISITED)    SCC(i);
        }

        sort(ans.begin(), ans.end(), mysort);

        for(int i = 0; i < ans.size(); ++i){
            for(int j = 0; j < ans[i].size(); ++j){
                if(j) cout << " ";
                cout << char(ans[i][j] + 'A');
            }
            cout << endl;
        }
    }
    return 0;
}

void SCC(int p){
    dfs_low[p] = dfs_num[p] = dfsCounter++;
    visiting[p] = true;
    S.push_back(p);

    int q;
    for(int i = 0; i < AdjList[p].size(); ++i){
        q = AdjList[p][i];
        if(dfs_num[q] == UNVISITED) SCC(q);
        if(visiting[q]) dfs_low[p] = min(dfs_low[p], dfs_low[q]);
    }

    if(dfs_num[p] == dfs_low[p]){
        vector<int> component;
        while(true){
            q = S.back();
            S.pop_back();
            visiting[q] = false;
            component.push_back(q);
            if(q == p)  break;
        }

        sort(component.begin(), component.end());
        ans.push_back(component);
    }
}
