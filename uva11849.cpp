#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <climits>
#include <cmath>
#include <set>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;

int main(){ _
    int N, M;
    cin >> N >> M;
    while(N != 0 && M != 0){
        set<int> si;
        int cd;
        for(int i = 0; i < N+M; ++i){
            cin >> cd;
            si.insert(cd);
        }

        cout << N+M - si.size() << endl;
        cin >> N >> M;
    }
    return 0;
}
