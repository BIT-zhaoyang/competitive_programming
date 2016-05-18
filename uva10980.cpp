#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(2);
using namespace std;

#define maxN 1000
//10:55
int main(){ _
    double temp;
    int n, count = 0;
    while(cin >> temp >> n){
        cout << "Case " << ++count << ":" << endl;
        vector<double> price(n+1, 0);
        vector<int> volume(n+1, 1);
        price[0] = temp;
        for(int i = 1; i <= n; ++i){
            cin >> volume[i] >> price[i];
        }

        vector<double> table(maxN, 1<<25);
        table[0] = 0;
        for(int i = 1; i < maxN; ++i){
            for(int j = 0; j < volume.size(); ++j){
                if(i >= volume[j])  table[i] = min(table[i], table[i-volume[j]] + price[j]);
            }
        }

        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss;
        ss << str;
        int K;
        while(ss >> K){
            cout << "Buy " << K << " for $";
            double ans = 1<<25;
            for(int i = K; i < maxN; ++i)
                ans = min(ans, table[i]);
            cout << fixed << ans << endl;
        }

    }

    return 0;
}
