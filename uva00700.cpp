#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;

int main(){ _
    int n, count = 0;
    while(cin >> n, n != 0){
        ++count;
        int y, a, b, diff;
        map<int, int> record;

        for(int i = 0; i < n; ++i){
            cin >> y >> a >> b;
            diff = b-a;
            for(int i = y; i < 1e4; i += diff)  record[i] += 1;
            for(int i = y-diff; i > a; i -= diff)   record[i] += 1;
        }

        bool flag = false;
        cout << "Case #" << count << ":" << endl;
        for(map<int, int>::iterator it = record.begin(); it != record.end(); ++it){
            if(it->second == n){
                cout << "The actual year is " << it->first << "." << endl << endl;
                flag = true;
                break;
            }
        }

        if(!flag)   cout << "Unknown bugs detected." << endl << endl;
    }
    return 0;
}
