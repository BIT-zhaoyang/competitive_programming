#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define POS_INF 1 << 28
#define NEG_INF -1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    string line;    getline(cin, line);
    while(getline(cin, line)){
        if(line == "___________")   break;
        char ch = 0;
        for(int i = 1; i + 1 < line.size(); ++i){
            if(line[i] == '.')  continue;
            ch <<= 1;
            if(line[i] == 'o')  ++ch;
        }
        cout << ch;
    }
    return 0;
}
