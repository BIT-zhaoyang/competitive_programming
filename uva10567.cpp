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

int main(){ _
    string str; cin >> str;
    map<char, vector<int> > dict;

    char ch;
    for(int i = 0; i < str.size(); ++i){
        ch = str[i];
        dict[ch].push_back(i);
    }

    int Q;  cin >> Q;
    string query;
    while(Q--){
        cin >> query;
        int start = 0, target;
        char ch = query[0];
        bool success = true;

        // record the start position
        if(dict[ch].size() != 0)    start = dict[ch][0];
        else    success = false;

        // find the position for the rest
        target = start + 1;
        vector<int>::iterator it;
        for(int i = 1; i < query.size(); ++i){
            ch = query[i];
            it = lower_bound(dict[ch].begin(), dict[ch].end(), target);
            if(it == dict[ch].end()){
                success = false;
                break;
            } else {
                target = (*it) + 1;
            }
        }

        // if successfully terminated, target points to 1 ahead of the position of the last char
        if(success) cout << "Matched " << start << " " << target - 1 << endl;
        else    cout << "Not matched" << endl;
    }
    return 0;
}
