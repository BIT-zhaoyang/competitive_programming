#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <climits>
#include <cmath>
#include <set>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <queue>
#include <stack>
#include <tuple>

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

int N, a, b;
char largestNode, from, to;
bool visited[26];

void dfs(int node, vector< vector<int> >& AdjList){
    visited[node] = true;

    int next;
    for(int i = 0; i < AdjList[node].size(); ++i){
        next = AdjList[node][i];
        if(visited[next])   continue;
        dfs(next, AdjList);
    }
}

int main(){ _
    int TC; cin >> TC;
    while(TC--){
        cin >> largestNode;
        N = largestNode - 'A' + 1;
        cin.ignore();

        vector< vector<int> > AdjList(N, vector<int> (0));
        string str;
        while(getline(cin, str)){
            if(str == "")   break;
            from = str[0];
            to = str[1];

            a = from - 'A';
            b = to - 'A';

            AdjList[a].push_back(b);
            AdjList[b].push_back(a);
        }

        memset(visited, 0, sizeof visited);
        int ans = 0;
        for(int i = 0; i < N; ++i){
            if(!visited[i]){
                ++ans;
                dfs(i, AdjList);
            }
        }

        cout << ans << endl;
        if(TC)  cout << endl;
    }
    return 0;
}
