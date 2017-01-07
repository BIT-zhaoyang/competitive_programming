#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define POS_INF 1 << 28
#define NEG_INF -1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    map<int, int> code;
    code[1] = 1, code[2] = 2;
    for(int i = 3, num1 = 1, num2 = 2; i <= 45; ++i){
        int num3 = num1 + num2;
        num1 = num2;
        num2 = num3;
        code[num3] = i;
    }

    int tc; cin >> tc;
    while(tc--){
        int n, maxLen = 0;  cin >> n;
        vector<int> seq(n, 0);
        for(int i = 0; i < n; ++i){
            cin >> seq[i];
            maxLen = max(maxLen, code[seq[i]]);
        }
        string ans(maxLen, ' '), input;

        cin.ignore();
        getline(cin, input);
        int counter = 0;
        for(int i = 0; i < input.size() && counter < n; ++i){
            char ele = input[i];
            if(ele >= 'A' && ele <= 'Z')
                ans[code[seq[counter++]] - 1] = ele;
        }
        cout << ans << endl;
    }
    return 0;
}
