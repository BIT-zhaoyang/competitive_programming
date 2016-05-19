#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(5);
using namespace std;

bool mycompare(int i, int j){return i > j;}

int main(){ _
    int C, S, count = 0;
    while(cin >> C >> S){
        cout << "Set #" << ++count << endl;
        vector<int> vi(2*C, 0);
        for(int i = 0; i < S; ++i)  cin >> vi[i];
        sort(vi.begin(), vi.end(), mycompare);

        double average = 0;
        for(int i = 0; i < vi.size(); ++i)  average += vi[i];
        average /= C;

        int sum = 0;    double balance = 0.0;
        for(int i = 0; i < C; ++i){
            sum = 0;
            cout << " " << i << ":";
            int j = vi.size()-1 - i;
            if(vi[i] != 0){
                cout << " " << vi[i];
                sum += vi[i];
            }

            if(vi[j] != 0){
                cout << " " << vi[j];
                sum += vi[j];
            }
            cout << endl;
            balance += abs(sum - average);
        }
        cout << "IMBALANCE = " << fixed << balance << endl;
        cout << endl;
    }
    return 0;
}
