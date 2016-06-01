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
    int B, S, count = 0;
    while(cin >> B >> S){
        if(B+S == 0)    break;
        cout << "Case " << ++count << ": ";

        vector<int> bachlor(61, 0);
        vector<int> spinster(61, 0);

        int age;
        for(int i = 0; i < B; ++i){
            cin >> age;
            ++bachlor[age];
        }

        for(int i = 0; i < S; ++i){
            cin >> age;
            ++spinster[age];
        }

        for(int i = 60; i >= 2; --i){
            while(bachlor[i] > 0 && S > 0){
                int older = i + 1;
                while(older < 61 && spinster[older] == 0)   ++older;

                int younger = i;
                while(younger > 1 && spinster[younger] == 0)    --younger;

                int marry = 0;
                if(older == 61) marry = younger;
                else if(younger == 1)   marry = older;
                else{
                    if(i - younger < older - i) marry = younger;
                    else    marry = older;
                }

                --spinster[marry];
                --bachlor[i];
                --S;
                --B;
            }
        }

        if(B == 0)  cout << 0 << endl;
        else{
            for(int i = 2; i < 61; ++i){
                if(bachlor[i] != 0){
                    cout << B << " " << i << endl;
                    break;
                }
            }
        }

    }
    return 0;
}
