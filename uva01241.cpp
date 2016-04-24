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
    int TC; cin >> TC;
    bitset<1025> players;
    while(TC--){
        int N, M; cin >> N >> M;
        players.set();

        int absent;
        for(int i = 0; i < M; ++i){
            cin >> absent;
            players[absent-1] = false;
        }

        int num = 1 << N, count = 0;
        for(int stride = 1; stride < num; stride *= 2){
            for(int i = 0; i+stride < num; i += 2*stride){
                count += players[i] ^ players[i + stride];
                players[i] = players[i] | players[i+stride];
            }
        }

        cout << count << endl;
    }
    return 0;
}
