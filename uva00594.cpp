#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;

const int mod = (1<<8)-1;

int main(){ _
    int n, ans, j, tmp, N;
    while(cin >> N, !cin.eof()){
        ans = 0, n = N;
        for(int i = 0; i < 4; ++i){
            tmp = n & mod;
            ans = (ans << 8) | tmp;
            n = n >> 8;
        }
        cout << N << " converts to " << ans << endl;
    }
    return 0;
}
