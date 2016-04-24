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

void recurse(int a, int b, int ca, int cb, int n){
    if(b == n){
        cout << "success" << endl;
        return;
    } else if(a == ca){
        cout << "empty A" << endl;
        recurse(0, b, ca, cb, n);
    } else if(b == 0){
        cout << "fill B" << endl;
        recurse(a, cb, ca, cb, n);
    } else {
        cout << "pour B A" << endl;
        int smaller = min(b, ca-a);
        recurse(a+smaller, b-smaller, ca, cb, n);
    }
}

int main(){ _
    int ca, cb, n;
    while(cin >> ca){
        cin >> cb >> n;
        recurse(0, 0, ca, cb, n);
    }
    return 0;
}
