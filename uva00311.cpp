#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

/* Ah!!!!!!!!!!! Ugly solution! */

int main(){ _
    long long a1, a2 ,a3, a4, a5, a6;
    while(cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6){
        if(a1 + a2 + a3 + a4 + a5 + a6 == 0)    break;

        long long ans = 0;
        ans += a6;

        ans += a5;
        a1 -= 11*a5;


        ans += a4;
        long long need2 = a4*5;
        if(a2 >= need2){
            a2 -= need2;
        } else {
            need2 -= a2;
            a2 = 0;
            a1 -= need2*4;
        }

        ans += a3/4;
        a3 %= 4;
        switch(a3){
            case 0: break;
            case 1:
                ans += 1;
                need2 = 5;
                if(a2 >= need2){
                    a2 -= 5;    a1 -= 7;
                } else{
                    need2 -= a2;    a2 = 0;
                    a1 -= need2*4;
                }
                break;
            case 2:
                ans += 1;
                need2 = 3;
                if(a2 >= need2){
                    a2 -= 3;    a1 -= 6;
                } else{
                    need2 -= a2;    a2 = 0;
                    a1 -= need2*4;
                }
                break;
            case 3:
                ans += 1;
                need2 = 1;
                if(a2 >= need2){
                    a2 -= 1;    a1 -= 5;
                } else{
                    need2 -= a2;    a2 = 0;
                    a1 -= need2*4;
                }
                break;
        }

        if(a2 > 0 && a1 > 0){
            ans += ceil((a2*4 + a1) / 36.0);
        } else if(a2 > 0){
            ans += ceil((a2*4) / 36.0);
        } else if(a1 > 0){
            ans += ceil(a1 / 36.0);
        }

        cout << ans << endl;

    }
    return 0;
}
