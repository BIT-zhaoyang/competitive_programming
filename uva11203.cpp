#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define POS_INF 1 << 28
#define NEG_INF -1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        string str; cin >> str;
        int beforeM = 0, M2E = 0, afterE = 0, count = 0, nM = 0, nE = 0;
        bool other = false;
        for(int i = 0; i < str.size(); ++i){
            char ch = str[i];
            switch (ch) {
                case '?':   count += 1; break;
                case 'M':   beforeM = count;    count = 0;  nM += 1;    break;
                case 'E':   M2E = count;    count = 0;  nE += 1;    break;
                default:    other = true;   break;
            }
        }
        afterE = count;
        if(other || nM > 1|| nE > 1 || beforeM == 0 || M2E == 0 || beforeM + M2E != afterE) cout << "no-theorem" << endl;
        else    cout << "theorem" << endl;
    }
    return 0;
}
