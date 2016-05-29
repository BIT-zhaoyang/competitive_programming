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
#include <deque>
#include <stack>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

int main(){ _
    string str;
    while(cin >> str){
        if(str == "0")  break;

        stack<char> atom, binary;
        int uni = 0;
        for(int i = 0; i < str.size(); ++i){
            switch(str[i]){
                case 'N':   ++uni;  break;
                case 'K': case 'A': case 'C': case 'E': binary.push(str[i]);    break;
                default:    atom.push(str[i]);  break;
            }
        }

        if(atom.size() == 0)    cout << "no WFF possible" << endl;
        else{
            string ans;
            string ch, op;

            // base case
            ch = atom.top();    atom.pop();
            ans = ch;

            // concatenate binary ops
            while(atom.size() > 0 && binary.size() > 0){
                ch = atom.top();    atom.pop();
                op = binary.top();  binary.pop();
                ans = op + ch + ans;
            }

            // prefix uniary ops as many as possible
            while(uni > 0){
                ans = 'N' + ans;
                --uni;
            }

            cout << ans << endl;
        }

    }
    return 0;
}
