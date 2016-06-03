#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

/*  Easy problem. Why there are so few people who have passed this?? */

int main(){ _
    int n;
    while(cin >> n){
        long long sum = 0;
        vector<int> vi(n, 0);
        for(int i = 0; i < n; ++i){
            cin >> vi[i];
            sum += vi[i];
        }

        if(sum % n) cout << -1 << endl;
        else{
            long long ave = sum / n;
            long long ans = 0;
            for(int i = 0; i < n; ++i){
                if(vi[i] < ave){
                    ans += ave - vi[i];
                } else {
                    break;
                }
            }

            ans += 1;   // count the first bar measure after the first singing time
            cout << ans << endl;
        }
    }
    return 0;
}
