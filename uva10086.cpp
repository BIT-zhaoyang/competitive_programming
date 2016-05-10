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
#include <sstream>
#include <iomanip>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

pair<int, int> pick[31][301][301];
int c1[20], c2[20];
#define BIG_VALUE 1 << 20

void printTrack(int nItem, int n, int m){
    if(nItem == 0)  cout << n;
    else{
        printTrack(nItem - 1, n - pick[nItem][n][m].first, m - pick[nItem][n][m].second);
        cout << " " << pick[nItem][n][m].first;
    }
}

int main(){ _
    int n, m;
    while(cin >> n >> m){
        if(n + m == 0)  break;
        vector< vector<int> > memo(n+1, vector<int> (m+1, BIG_VALUE));
        memo[0][0] = 0;

        int nItem, mi;  cin >> nItem;
        for(int n_item = 0; n_item < nItem; ++n_item){
            cin >> mi;
            for(int m_i = 1; m_i <= mi; ++m_i)   cin >> c1[m_i];
            for(int m_i = 1; m_i <= mi; ++m_i)   cin >> c2[m_i];

            for(int i = n; i >= 0; --i){
                for(int j = m; j >= 0; --j){
                    for(int k = 0; k <= mi; ++k){
                        int _k = mi - k;
                        if(i >= k && j >= _k){
                            if(memo[i-k][j- _k] + c1[k]+c2[_k] < memo[i][j]){
                                memo[i][j] = memo[i-k][j- _k] + c1[k]+c2[_k];
                                pick[n_item][i][j] = make_pair(k, _k);
                            }
                        }
                    }
                }
            }
        }
        cout << memo[n][m] << endl;
        printTrack(nItem-1, n, m);
        cout << endl;
    }
    return 0;
}
