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
    int T; cin >> T;
    while(T--){
        int n, m; cin >> n >> m;
        vector< vector<int> > matrix(n, vector<int> (m, 0));
        vector<int> count(m, 0);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin >> matrix[i][j];
                count[j] += matrix[i][j];
            }
        }

        bool possible = true;
        for(int i = 0; i < m; ++i){
            if(count[i] != 2){
                possible = false;
                break;
            }
        }

        pair<int, int> edge;
        set< pair<int, int> > E;
        int start, end;
        for(int j = 0; j < m; ++j){
            start = -1, end = -1;
            for(int i = 0; i < n; ++i){
                if(matrix[i][j] == 1){
                    if(start == -1) start = i;
                    else    end = i;
                }
            }
            edge = make_pair(start, end);
            if(E.count(edge)){
                possible = false;
                break;
            } else {
                E.insert(edge);
            }
        }


        if(possible)    cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
