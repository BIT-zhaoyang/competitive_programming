#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int n;
    while(cin >> n){
        if(n == 0)  break;
        vector< vector<int> > young(26, vector<int> (26, BIGINT));
        vector< vector<int> > old(26, vector<int> (26, BIGINT));

        char age, dir, u, v;    int d;
        for(int i = 0; i < n; ++i){
            cin >> age >> dir >> u >> v >> d;
            if(age == 'Y'){
                young[u - 'A'][v - 'A'] = d;
                if(dir == 'B')  young[v - 'A'][u - 'A'] = d;
            } else {
                old[u - 'A'][v - 'A'] = d;
                if(dir == 'B')  old[v - 'A'][u - 'A'] = d;
            }
        }
        for(int i = 0; i < 26; ++i) young[i][i] = 0, old[i][i] = 0;

        // floyd-warshall
        for(int k = 0; k < 26; ++k)
            for(int i = 0; i < 26; ++i)
                for(int j = 0; j < 26; ++j){
                    young[i][j] = min(young[i][j], young[i][k] + young[k][j]);
                    old[i][j] = min(old[i][j], old[i][k] + old[k][j]);
                }

        cin >> u >> v;
        int s = u - 'A', t = v - 'A', ans = BIGINT;
        for(int i = 0; i < 26; ++i)
            ans = min(ans, young[s][i] + old[t][i]);

        if(ans == BIGINT){
            cout << "You will never meet." << endl;
            continue;
        } else {
            cout << ans;
            for(int i = 0; i < 26; ++i)
                if(young[s][i] + old[t][i] == ans)
                    cout << " " << char('A' + i);
            cout << endl;
        }
    }
    return 0;
}
