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
#include <unordered_map>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;

int main(){ _
    int n, m;
    while(cin >> n >> m, !cin.eof()){
        int num;
        unordered_map<int, vector<int> > record;
        for(int i = 1; i <= n; ++i){
            cin >> num;
            record[num].push_back(i);
        }

        int k, v;
        for(int i = 0; i < m; ++i){
            cin >> k >> v;
            if(k > record[v].size())    cout << 0 << endl;
            else cout << record[v][k-1] << endl;
        }
    }
    return 0;
}
