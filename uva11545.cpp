#include <bits/stdc++.h>
#define UNVISITED -1
#define BIGINT 1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

/* This problem: exciting! */

const int MAXN = 1000;
int table[MAXN][24][17];    // states: location, time, status.
                            // status: travelling 1-16 hours, and wake up after rest(represent by 0)

int main(){ _
    int TC; cin >> TC;
    for(int tc = 1; tc <= TC; ++tc){
        cout << "Case #" << tc << ": ";
        for(int i = 0; i < MAXN; ++i)
            for(int t = 0; t < 24; ++t)
                for(int s = 0; s < 17; ++s)
                    table[i][t][s] = BIGINT;

        string line;    cin >> line;
        int n = line.size();
        table[0][6][0] = 0, table[0][14][0] = 8, table[0][22][0] = 16;
        for(int i = 1; i < n; ++i){
            // we can only rest after arriving at a location, so we process travel part first
            for(int t = 0; t < 24; ++t){
                // we can't be in jungle during dark hours
                if(line[i] == '*' && (t <= 6 || t >= 18)) continue;
                for(int j = 1; j <= 16; ++j){
                    int lastT = (t + 24 - 1) % 24;
                    table[i][t][j] = table[i - 1][lastT][j - 1] + 1;
                }
            }

            // now we can handle relax part, we can only rest if this place is plain ground
            for(int t = 0; t < 24; ++t){
                // wake up time in jungle can only between [14, 18)
                if(line[i] == '*' && (t < 14 || t >= 18))   continue;
                int timeBeforeRest = (t + 24 - 8) % 24;
                for(int j = 1; j <= 16; ++j)
                    table[i][t][0] = min(table[i][t][0], table[i][timeBeforeRest][j] + 8);
            }

            // Now here is the tricky part, we can rest for two consecutive times
            for(int t = 0; t < 24; ++t){
                if(line[i] == '*' && (t < 14 || t >= 18))   continue;
                int timeBeforeRest = (t + 24 - 8) % 24;
                table[i][t][0] = min(table[i][t][0], table[i][timeBeforeRest][0] + 8);
            }
        }

        int ans = BIGINT;
        for(int t = 0; t < 24; ++t)
            for(int s = 1; s <= 16; ++s)
                if(table[n - 1][t][s] != BIGINT)
                    ans = min(ans, table[n - 1][t][s]);

        if(ans == BIGINT)  cout << -1 << endl;
        else    cout << ans << endl;

    }
    return 0;
}
