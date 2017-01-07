#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define POS_INF 1 << 28
#define NEG_INF -1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int n;  string text;
    while(cin >> n >> text){
        map<string, int> count;
        for(int i = 0; i + n < text.size(); ++i){
            count[text.substr(i, n)] += 1;
        }
        int maxCount = 0;   string ans;
        for(auto ele : count){
            if(ele.second > maxCount){
                maxCount = ele.second;
                ans = ele.first;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
