#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <climits>
#include <cmath>
#include <set>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(4);

using namespace std;

int main(){ _
    int T; cin >> T;
    string name;

    // ignore the blank line following T
    cin.ignore();
    getline(cin, name);

    while(T--){
        map<string, int> base;
        map<string, int>::iterator it;
        int total = 0;

        while(getline(cin, name), name != ""){
            ++total;
            it = base.find(name);
            if(it == base.end()){
                base[name] = 1;
            } else {
                base[name] += 1;
            }
        }
        it = base.begin();
        while(it != base.end()){
            cout << it->first << " " << fixed << 100.0 * it->second / total << endl;
            ++it;
        }

        if(T) cout << endl;
    }
    return 0;
}
