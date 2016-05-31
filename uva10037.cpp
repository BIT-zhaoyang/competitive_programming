#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

/* reference:   Crossing the Bridge at Night, Gunter Rote. */

int main(){ _
    int TC; cin >> TC;
    while(TC--){
        int n;  cin >> n;
        vector<int> vi(n, 0);
        for(int i = 0; i < n; ++i)  cin >> vi[i];
        sort(vi.begin(), vi.end());

        int sum = 0;
        for(int i = n-1; ;){
            if(i == 2){
                sum += vi[0] + vi[1] + vi[2];
                break;
            } else if(i == 1){
                sum += vi[1];
                break;
            } else if(i == 0){
                sum += vi[0];
                break;
            } else {
                sum += min(vi[0] + vi[1]*2 + vi[i], 2*vi[0] + vi[i-1] + vi[i]);
                i -= 2;
            }
        }
        cout << sum << endl;

        for(int i = n-1; ;){
            if(i == 2){
                cout << vi[0] << " " << vi[2] << endl;
                cout << vi[0] << endl;
                cout << vi[0] << " " << vi[1] << endl;
                break;
            } else if(i == 1){
                cout << vi[0] << " " << vi[1] << endl;
                break;
            } else if(i == 0){
                cout << vi[0] << endl;
                break;
            } else {
                if(vi[0] + vi[1]*2 + vi[i] < 2*vi[0] + vi[i-1] + vi[i]){
                    cout << vi[0] << " " << vi[1] << endl;
                    cout << vi[0] << endl;
                    cout << vi[i-1] << " " << vi[i] << endl;
                    cout << vi[1] << endl;
                } else {
                    cout << vi[0] << " " << vi[i] << endl;
                    cout << vi[0] << endl;
                    cout << vi[0] << " " << vi[i-1] << endl;
                    cout << vi[0] << endl;
                }
                i -= 2;
            }
        }
        if(TC)  cout << endl;
    }
    return 0;
}
