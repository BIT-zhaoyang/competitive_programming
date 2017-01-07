#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define POS_INF 1 << 28
#define NEG_INF -1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

string arrange;
map<char, int> loc;

void process(char ch1, char ch2){
    int x1 = loc[ch1] / 5, y1 = loc[ch1] % 5;
    int x2 = loc[ch2] / 5, y2 = loc[ch2] % 5;

    if(x1 == x2){
        y1 = (y1 + 1) % 5;
        y2 = (y2 + 1) % 5;
        cout << arrange[x1 * 5 + y1] << arrange[x2 * 5 + y2];
    } else if(y1 == y2){
        x1 = (x1 + 1) % 5;
        x2 = (x2 + 1) % 5;
        cout << arrange[x1 * 5 + y1] << arrange[x2 * 5 + y2];
    } else {
        cout << arrange[x1 * 5 + y2] << arrange[x2 * 5 + y1];
    }
}

int main(){ _
    int tc; cin >> tc;  cin.ignore();
    while(tc--){
        vector<bool> visited(26, false);
        visited['Q' - 'A'] = true;

        string code;    getline(cin, code);
        arrange = "";
        loc.clear();
        for(int i = 0; i < code.size(); ++i){
            if(code[i] == ' ')  continue;
            char ch = toupper(code[i]);
            if(!visited[ch - 'A']){
                loc[ch] = arrange.size();
                arrange += ch;
                visited[ch - 'A'] = true;
            }
        }
        for(int i = 0; i < visited.size(); ++i)
            if(!visited[i]){
                loc[char(i + 'A')] = arrange.size();
                arrange += char(i + 'A');
            }

        string raw_input, input, trans;   getline(cin, raw_input);
        for(int i = 0; i < raw_input.size(); ++i)
            if(raw_input[i] != ' ')
                input += toupper(raw_input[i]);

        for(int i = 0; i < input.size(); i += 2){
            char ch1, ch2;
            ch1 = input[i];
            if(i + 1 == input.size())   ch2 = 'X';
            else if(input[i + 1] == input[i]){
                ch2 = 'X';
                i -= 1;
            } else {
                ch2 = input[i + 1];
            }

            process(ch1, ch2);
        }
        cout << endl;
    }
    return 0;
}
