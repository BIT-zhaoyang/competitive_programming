#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int order;
        cin >> order;
        vector<int> c(order+1, 0);
        for(int i = 0; i <= order; ++i){
            cin >> c[i];
        }
        int d, k, x;
        cin >> d >> k;
        k *= 2;
        for(x = 1; ; ++x){
            if(x*(x+1)*d >= k)  break;
        }

        long long sum = 0;
        long long prev = 1;
        for(int i = 0; i <= order; ++i){
            sum = sum + prev * c[i];
            prev *= x;
        }

        cout << sum << endl;
    }
    return 0;
}
