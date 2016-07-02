#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
const int dr[4] = {1, -1, 0, 0};
const int dc[4] = {0, 0, -1, 1};

class Figure{
public:
    Figure(int _n, int _m){
        n = _n, m = _m * 4;
        read_data();
    }

    void solve(){
        link_white();
        find_character();
        print();
    }

private:
    void read_data(){
        data.assign(n+2, vector<int> (m+2));
        index.assign(n+2, vector<int> (m+2, 0));
        // visited.assign(n, vector<bool> (m, false));

        char ch;
        int num;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; j += 4){
                cin >> ch;
                if(ch >= 'a')   num = 10 + (ch - 'a');
                else    num = (ch - '0');

                for(int k = 3; k >= 0; --k){
                    data[i][j+k] = (num % 2);
                    num /= 2;
                }
            }
        }
    }

    void link_white(){
        int idx = 1;
        for(int i = 0; i < n+2; ++i){
            for(int j = 0; j < m+2; ++j){
                if(index[i][j] == 0 && data[i][j] == 0){
                    dfs(i, j, idx);
                    ++idx;
                }
            }
        }
        whites.assign(idx+1, false);
    }

    void dfs(int row, int col, int idx){
        index[row][col] = idx;

        int r, c;
        for(int i = 0; i < sizeof(dr)/sizeof(int); ++i){
            r = row + dr[i];
            c = col + dc[i];
            if(r < 0 || r >= n+2 || c < 0 || c >= m+2)  continue;
            if(index[r][c] != 0 || data[r][c] != 0) continue;
            dfs(r, c, idx);
        }
    }

    void find_character(){
        int idx = -1, num;
        for(int i = 0; i < n+2; ++i){
            for(int j = 0; j < m+2; ++j){
                if(data[i][j] == 1 && index[i][j] == 0){
                    whites.assign(whites.size(), false);
                    dfs(i, j, whites, idx);

                    num = 0;
                    for(int k = 0; k < whites.size(); ++k){
                        if(whites[k])   ++num;
                    }

                    switch (num) {
                        case 1: ele.push_back('W'); break;
                        case 2: ele.push_back('A'); break;
                        case 3: ele.push_back('K'); break;
                        case 4: ele.push_back('J'); break;
                        case 5: ele.push_back('S'); break;
                        case 6: ele.push_back('D'); break;
                    }
                }
            }
        }
    }

    void dfs(int row, int col, vector<bool> &whites, int idx){
        index[row][col] = idx;

        int r, c;
        for(int i = 0; i < sizeof(dr)/sizeof(int); ++i){
            r = row + dr[i];
            c = col + dc[i];
            if(r < 0 || r >= n+2 || c < 0 || c >= m+2)  continue;
            if(data[r][c] == 0){
                whites[index[r][c]] = true;
            } else {
                if(index[r][c] != 0)    continue;
                dfs(r, c, whites, idx);
            }
        }
    }

    void print(){
        sort(ele.begin(), ele.end());
        for(int i = 0; i < ele.size(); ++i) cout << ele[i];
        cout << endl;
    }

private:
    vector< vector<int> > data;
    vector< vector<int> > index;
    vector<bool> whites;
    vector<char> ele;

    int n, m;
};

int main(){ _
    int n, m, count = 0;
    while(cin >> n >> m){
        if(n + m == 0)  break;
        cout << "Case " << ++count << ": ";
        Figure f(n, m);
        f.solve();
    }
    return 0;
}
