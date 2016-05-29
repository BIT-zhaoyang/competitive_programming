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
#include <iomanip>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

/*  Good Problem. Though the algorithm is simple, the cases need some thought to process. */

int main(){ _
    char vow[] = {'A', 'U', 'E', 'O', 'I'};
    char con[] = {'J', 'S', 'B', 'K', 'T', 'C', 'L', 'D', 'M', 'V', 'N', 'W', 'F', 'X', 'G', 'P', 'Y', 'H', 'Q', 'Z', 'R'};

    vector<char> vowel;
    for(int i = 0; i < sizeof(vow)/sizeof(char); ++i)
        for(int j = 0; j < 21; ++j)
            vowel.push_back(vow[i]);

    vector<char> cons;
    for(int i = 0; i < sizeof(con)/sizeof(char); ++i)
        for(int j = 0; j < 5; ++j)
            cons.push_back(con[i]);


    int TC; cin >> TC;
    for(int c = 1; c <= TC; ++c){
        cout << "Case " << c << ": ";
        int n;  cin >> n;

        int nVow = ceil(n / 2.0);
        int nCon = floor(n / 2.0);

        vector<char> usedVow(vowel.begin(), vowel.begin()+nVow);
        vector<char> usedCon(cons.begin(), cons.begin()+nCon);
        sort(usedCon.begin(), usedCon.end());
        sort(usedVow.begin(), usedVow.end());

        int vp = 0, cp = 0;
        for(int i = 1; i <= n; ++i){
            if(i % 2)   cout << usedVow[vp++];
            else    cout << usedCon[cp++];
        }
        cout << endl;
    }
    return 0;
}
