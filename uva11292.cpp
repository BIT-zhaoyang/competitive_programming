#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

int main(){ _
    int n, m;
    while(cin >> n >> m){
        if(n + m == 0)  break;
        vector<int> dragon(n, 0), knight(m, 0);
        for(int i = 0; i < n; ++i)  cin >> dragon[i];
        for(int i = 0; i < m; ++i)  cin >> knight[i];

        sort(dragon.begin(), dragon.end());
        sort(knight.begin(), knight.end());

        int ans = 0;
        for(int i = 0, j = 0; i < n; ++i){
            if(j == m){
                cout << "Loowater is doomed!" << endl;
                ans = 0;
                break;
            }

            for( ; j < m; ++j){
                if(knight[j] >= dragon[i]){
                    ans += knight[j];
                    ++j;
                    break;
                }
            }
        }

        if(ans != 0)    cout << ans << endl;
    }
    return 0;
}
