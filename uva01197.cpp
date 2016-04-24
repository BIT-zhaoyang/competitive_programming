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

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;
//07:02
class UnionFind{
private:
    vector<int> p, r;
public:
    UnionFind(int n){
        r.assign(n, 0);
        p.assign(n, 0);
        for(int i = 0; i < n; ++i)  p[i] = i;
    }

    bool isSameSet(int a, int b){
        return findSet(a) == findSet(b);
    }

    int findSet(int n){
        return (p[n] == n) ? n : (p[n] = findSet(p[n]));
    }

    void linkSet(int a, int b){
        if(isSameSet(a, b)) return;

        int x = findSet(a);
        int y = findSet(b);

        if(r[x] > r[y]) {
            p[y] = x;
        }else{
            p[x] = y;
            if(r[y] == r[x])    ++r[y];
        }
    }
};

int main(){ _
    int n, m, num;
    while(cin >> n >> m){
        if(n == 0 && m == 0)    break;
        UnionFind student(n);

        for(int i = 0; i < m; ++i){
            cin >> num;
            vector<int> members(num, 0);
            for(int j = 0; j < num; ++j){
                cin >> members[j];
            }
            for(int j = 1; j < num; ++j){
                student.linkSet(members[j-1], members[j]);
            }
        }

        int count = 0;
        for(int i = 0; i < n; ++i){
            if(student.isSameSet(i, 0)) ++count;
        }

        cout << count << endl;
    }
    return 0;
}
