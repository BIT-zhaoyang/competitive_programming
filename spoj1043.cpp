#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> v(N, 0);
    for(int i = 0; i < N; ++i){
        cin >> v[i];
    }
    
    int T;
    cin >> T;
    while(T--){
        int x, y;
        cin >> x >> y;
        long long maximum = -15007 * N;
        long long acc = 0;
        for(int i = x; i <= y; ++i){
            acc += v[i];
            if(acc > maximum){
                maximum = acc;
            }
            
            if(acc < 0){
                acc = 0;
            }
        }
        cout << maximum << endl;
    }
    
    return 0;
}