#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;

struct frac{
    int nomi, denom;
    frac(int a, int b){
        nomi = a;
        denom = b;
    }
};

bool smaller(frac &a, frac &b){
    return (int64)(a.nomi)*b.denom < (int64)(b.nomi)*a.denom;
}

bool equal(frac& a, frac& b){
    return a.nomi == b.nomi && a.denom == b.denom;
}

frac add(frac& a, frac& b){
    int nomi = a.nomi + b.nomi;
    int denom = a.denom + b.denom;

    frac ans(nomi, denom);
    return ans;
}

void rec(frac& left, frac& mid, frac& right, frac& given){
    if(equal(mid, given)){
        cout << endl;
        return;
    } else if(smaller(mid, given)){
        cout << "R";
        frac newMid = add(mid, right);
        left = mid;
        mid = newMid;
        rec(left, mid, right, given);
    } else {
        cout << "L";
        frac newMid = add(left, mid);
        right = mid;
        mid = newMid;
        rec(left, mid, right, given);
    }
}

int main(){ _
    int nomi, denom;
    while(cin >> nomi >> denom){
        if(nomi == 1 && denom == 1) break;

        frac left(0, 1);
        frac right(1, 0);
        frac mid(1, 1);
        frac target(nomi, denom);
        rec(left, mid, right, target);
    }
    return 0;
}
