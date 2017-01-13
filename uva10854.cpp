#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
/* A useful input:
1
IF
ELSE
END_IF
S
S
S
IF
ELSE
IF
ELSE
END_IF
IF
ELSE
END_IF
S
S
S
S
S
IF
ELSE
END_IF
END_IF
ENDPROGRAM

"IF" statements in the same layer have multiplication relation.
"IF" and its corresponding "ELSE" have addition relation.
*/

int recurIf();
int recurElse();
int recur();

int recurIf(){
    string str;
    int nPath = 1;
    while(cin >> str){
        if(str == "IF") nPath *= recurIf();
        else if(str == "ELSE")   return nPath + recurElse();
    }
}

int recurElse(){
    string str;
    int nPath = 1;
    while(cin >> str){
        if(str == "IF") nPath *= recurIf();
        else if(str == "END_IF")   return nPath;
    }
}

int recur(){
    string str;
    int nPath = 1;
    while(cin >> str){
        if(str == "IF") nPath *= recurIf();
        else if(str == "ENDPROGRAM") return nPath;
    }
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        cout << recur() << endl;
    }
    return 0;
}
