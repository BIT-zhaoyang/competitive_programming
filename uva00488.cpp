#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        int height, freq;   cin >> height >> freq;
        while (freq--) {
            for(int i = 1; i <= height; ++i)
                cout << setw(i) << setfill(char(i + '0')) << i << endl;
            for(int i = height - 1; i >= 1; --i)
                cout << setw(i) << setfill(char(i + '0')) << i << endl;
            if(freq)    cout << endl;
        }
        if(tc)  cout << endl;
    }
    return 0;
}
