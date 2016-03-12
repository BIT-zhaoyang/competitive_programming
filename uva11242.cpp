#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <climits>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(2);

using namespace std;

int main(){ _
    int f, r;
    while(cin >> f, f != 0){
        cin >> r;
        vector<int> front(f, 0);
        vector<int> rear(r, 0);

        for(int i = 0; i < f; ++i)  cin >> front[i];
        for(int i = 0; i < r; ++i)  cin >> rear[i];
        vector<double> ratio(f*r, 0);

        for(int i = 0; i < f; ++i){
            for(int j = 0; j < r; ++j){
                ratio[i*r + j] = double(rear[j]) / front[i];
            }
        }

        sort(ratio.begin(), ratio.end());
        double max_result = 0, result = 0;
        for(int i = 1; i < f*r; ++i){
            result = ratio[i] / ratio[i-1];
            if(result > max_result) max_result = result;
        }
        cout << fixed << max_result << endl;
    }
    return 0;
}
