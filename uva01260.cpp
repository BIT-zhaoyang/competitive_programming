#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;

int main(){ _
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> a(n, 0);
        int bsum = 0;
        for(int i = 0; i < n; ++i)  cin >> a[i];

        for(int i = 1; i < n; ++i){
            int val = a[i], count = 0;
            for(int j = 0; j < i; ++j){
                if(a[j] <= val) ++count;
            }
            bsum += count;
        }
        cout << bsum << endl;
    }
    return 0;
}
