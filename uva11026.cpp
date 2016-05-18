#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

#define maxN 1001
int vals[maxN];
long long table[maxN][maxN];

/* Simple math problem:
    To compute all K combinations starts with 'a',(let's say we have a, b, c, d, e, K = 3) we just compute a*(bc + bd + be + cd + ce) = a * ((bc+bd+be) + (cd+ce))
        table[a][k] = a * (table[b][k-1] + table[c][k-1] + ... )
    However, computing (table[b][k-1] + table[c][k-1] + ... ) is O(N). We can preserve the sum of table[a][k-1] + ... + table[N][k-1]. When we need to compute (table[b][k-1] + table[c][k-1] + ... ), just subtract table[a][k-1] from the sum which gives us O(1) computation.
    In total, the complexity if O(N^2).
*/

int main(){ _
    int N, M;
    while(cin >> N >> M){
        if(N + M == 0)  break;
        for(int i = 1; i <= N; ++i) cin >> vals[i];

        long long sum = 0, ans = 0;
        //base case
        for(int valIdx = 1; valIdx <= N; ++valIdx){
            table[valIdx][1] = vals[valIdx];
            sum += table[valIdx][1];
        }
        ans = max(ans, sum%M);

        for(int k = 2; k<= N; ++k){
            for(int valIdx = 1; valIdx+(k-1) <= N; ++valIdx){
                sum -= table[valIdx][k-1];
                table[valIdx][k] = (sum % M ) * (vals[valIdx] % M);
                table[valIdx][k] %= M;
            }

            // compute sum of table[][k]
            sum = 0;
            for(int valIdx = 1; valIdx+(k-1) <= N; ++valIdx){
                sum += table[valIdx][k];
            }

            // update answer
            ans = max(ans, sum % M);
        }
        cout << ans << endl;

    }
    return 0;
}
