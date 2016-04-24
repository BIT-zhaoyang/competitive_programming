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
//6:25

class UnionFind{
private:
    vector<int> p, r;
public:
    UnionFind(int n){
        r.assign(n, 0);
        p.assign(n, 0);
        for(int i = 0; i < n; ++i)  p[i] = i;
    }

    int findSet(int n){
        return (p[n] == n) ? n : (p[n] = findSet(p[n]));
    }

    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }

    void linkSet(int i, int j){
        if(isSameSet(i, j)) return;

        int x = findSet(i);
        int y = findSet(j);

        if(r[x] > r[y]){
            p[y] = x;
        } else {
            p[x] = y;
            if(r[x] == r[y])    r[y] += 1;
        }
    }
};

int main(){ _
    int T;  cin >> T;
    while(T--){
        int n;  cin >> n;
        UnionFind computers(n+1);
        cin.ignore();
        string line;
        int a, b, correct = 0, wrong = 0;
        char type;
        while(getline(cin, line)){
            if(line == "")  break;

            stringstream ss;
            ss << line;
            ss >> type >> a >> b;
            if(type == 'c'){
                computers.linkSet(a, b);
            } else {
                if(computers.isSameSet(a, b)) correct += 1;
                else    wrong += 1;
            }
        }
        cout << correct << "," << wrong << endl;
        if(T)   cout << endl;
    }
    return 0;
}
