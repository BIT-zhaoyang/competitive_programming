#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(2);
using namespace std;

int x[8], y[8];
double dist[8][8];

int main(){ _
    int n, count = 0;
    while(cin >> n && n){
        ++count;
        for(int i = 0; i < n; ++i)  cin >> x[i] >> y[i];
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                dist[i][j] = dist[j][i] = sqrt(pow((x[i] - x[j]), 2) + pow(y[i] - y[j], 2)) + 16;
            }
        }

        vector<int> vi(n, 0);
        for(int i = 0; i < n; ++i)  vi[i] = i;

        double shortest = DBL_MAX;
        vector<int> ans;
        do{
            double sum = 0.0;
            for(int i = 0; i < n-1; ++i)    sum += dist[vi[i]][vi[i+1]];
            if(sum < shortest){
                shortest = sum;
                ans = vi;
            }
        }while(next_permutation(vi.begin(), vi.end()));

        cout << "**********************************************************" << endl;
        cout << "Network #" << count << endl;
        for(int i = 0; i < n-1; ++i){
            int a = ans[i], b = ans[i+1];
            cout << "Cable requirement to connect (" << x[a] << "," << y[a] << ") to ("
                 << x[b] << "," << y[b] << ") is " << fixed << dist[a][b] << " feet." << endl;
        }

        cout << "Number of feet of cable required is " << shortest << "." <<  endl;
    }
    return 0;
}
