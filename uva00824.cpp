#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< pair<int, int> > vii;

int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int main(){ _
    int x, y, dir;
    while(cin >> x){
        if(x == -1) break;
        cin >> y >> dir;

        int nx, ny, type;
        map< pair<int, int>, int> neib;
        for(int i = 0; i < 8; ++i){
            cin >> nx >> ny >> type;
            neib[make_pair(nx, ny)] = type;
        }

        dir = (dir + 8 - 2)%8;
        for(int i = 0; i < 8; ++i){
            nx = x + dx[(dir+i)%8];
            ny = y + dy[(dir+i)%8];
            if(neib[make_pair(nx, ny)] == 1){
                cout << (dir+i)%8 << endl;
                break;
            }
        }
    }
    return 0;
}
