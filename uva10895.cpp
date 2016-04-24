#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <climits>
#include <cmath>
#include <set>
#include <bitset>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;

int main(){ _
    int M, N;
    while(cin >> M >> N, !cin.eof()){
        vector< vector<int> > coord(N+1);
        vector< vector<int> > value(N+1);
        for(int count = 1; count <= M; ++count){
            int num; cin >> num;
            vector<int> rows;
            for(int j = 0; j < num; ++j){
                int col; cin >> col;
                coord[col].push_back(count);
                rows.push_back(col);
            }

            for(int j = 0; j < num; ++j){
                int v; cin >> v;
                int row = rows[j];
                value[row].push_back(v);
            }
        }

        cout << N << " " << M << endl;
        for(int i = 1; i <= N; ++i){
            cout << coord[i].size();
            for(int j = 0; j < coord[i].size(); ++j)
                cout << " " << coord[i][j];
            cout << endl;

            for(int j = 0; j < value[i].size(); ++j){
                cout << value[i][j];
                if(j != value[i].size()-1)  cout << " ";
            }
            cout << endl;
        }

    }
    return 0;
}
