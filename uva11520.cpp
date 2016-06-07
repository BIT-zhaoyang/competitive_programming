#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

char square[10][10];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main(){ _
    int TC; cin >> TC;
    for(int tc = 1; tc <= TC; ++tc){
        cout << "Case " << tc << ":" << endl;

        int n;  cin >> n;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> square[i][j];
            }
        }

        int x, y;
        bool success = true;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(square[i][j] != '.') continue;

                for(char ch = 'A'; ch <= 'Z'; ++ch){
                    success = true;
                    for(int k = 0; k < 4; ++k){
                        x = i + dx[k];
                        y = j + dy[k];

                        if(x >= 0 && x < n && y >= 0 && y < n){
                            if(ch == square[x][y]){
                                success = false;
                                break;
                            }
                        }
                    }

                    if(success){
                        square[i][j] = ch;
                        break;
                    }
                }

            }
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cout << square[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
