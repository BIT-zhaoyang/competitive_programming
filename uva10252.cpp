#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define POS_INF 1 << 28
#define NEG_INF -1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    string str1, str2;
    while(getline(cin, str1) && getline(cin, str2)){
        vector<int> count1(26, 0), count2(26, 0);
        for(int i = 0; i < str1.size(); ++i)
            count1[str1[i] - 'a'] += 1;
        for(int i = 0; i < str2.size(); ++i)
            count2[str2[i] - 'a'] += 1;

        for(int i = 0; i < count1.size(); ++i){
            int n = min(count1[i], count2[i]);
            cout << setw(n) << setfill(char(i + 'a')) << "";
        }
        cout << endl;
    }
    return 0;
}
