#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

/* What the fuck is this problem? I though we should arrange the words to make them taking the fewest lines. But in fact the words order is fixed. We don't have to arrange them. Just simply count how many lines these words will take... Shit...*/

int main(){ _
    int N, L, C;
    string str;
    while(cin >> N >> L >> C){
        vector<int> vi(N, 0);
        for(int i = 0; i < N; ++i){
            cin >> str;
            vi[i] = str.size();
        }

        int nL = 0, nC = C;
        for(int i = 0; i < vi.size(); ++i){
            if(vi[i] <= nC){
                nC -= vi[i] + 1;
            } else {
                ++nL;
                nC = C - (vi[i] + 1);
            }
        }
        ++nL;   //count for the last line

        cout << int(ceil(nL / 1.0 / L)) << endl;
    }
    return 0;
}
