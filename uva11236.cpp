#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <climits>
#include <cmath>
// #define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int main(){ 
    // double pa, pab, pabc, sa, sab, sabc;

    for(int a = 1; 4*a <= 2000; ++a){
        for(int b = a; a + 3*b <= 2000; ++b){
            for(int c = b; a + b + 2*c <= 2000; ++c){
                long long p = a*b*c;        // p: product
                long long s = a + b + c;    // s: sum

                if(p <= 1e6) continue;       // d = (1e^6 * s) / (p - 1e^6), thus p should be larger than 1e^6

                long long d = (s * 1e6) / (p - 1e6);

                if(d >= c && s+d <= 2000){
                    // double da = a / 100.0, db = d / 100.0, dc = c / 100.0, dd = d/ 100.0;
                    // if(fabs(da*db*dc*dd - da-db-dc-dd) < 1e-1)
                    if(fabs((s+d)/100.0 - p*d*1.0/1e8) < 1e-9)
                        printf("%0.2lf %0.2lf %0.2lf %0.2lf\n", a / 100.0,
                            b / 100.0, c / 100.0, d / 100.0);
                }
            }
        }
    }
    return 0;
}
