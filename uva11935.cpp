#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(3);
#define UNVISITED -1
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    double last, curr, consump, leak, maxTotal, total;
    string type;
    while(true){
        cin >> curr >> type;

        total += (curr - last) * (consump + leak) / 100;
        maxTotal = max(maxTotal, total);
        last = curr;

        if(type == "Goal"){
            cout << fixed << maxTotal << endl;
            last = curr = consump = leak = maxTotal = total = 0.0;
        } else if(type == "Fuel"){
            cin >> type >> consump;
            if(consump == 0.0)  break;
        } else if(type == "Gas"){
            cin >> type;
            total = 0.0;
        } else if(type == "Leak"){
            leak += 100.0;
        } else if(type == "Mechanic"){
            leak = 0;
        }
    }
    return 0;
}
