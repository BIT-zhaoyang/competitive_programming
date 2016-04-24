#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define vi vector<int>

using namespace std;


struct frac{
    long long n, d;   // numerator & denominator

    frac(){n = 0, d = 0;}

    frac(long long _n, long long _d){
        n = _n, d = _d;
    }
};

frac sum(frac& f1, frac& f2){
    frac ans;
    ans.n = f1.n + f2.n;
    ans.d = f1.d + f2.d;

    return ans;
}

int main(){ _
    int n; cin >> n;
    string str;
    for(int i = 0; i < n; ++i){
        cin >> str;
        vector<frac> tup(3);
        tup[0] = frac(0, 1);
        tup[1] = frac(1, 1);
        tup[2] = frac(1, 0);
        for(int j = 0; j < str.size(); ++j){
            vector<frac> newTup(3);
            if(str[j] == 'L'){
                newTup[0] = tup[0];
                newTup[1] = sum(tup[0], tup[1]);
                newTup[2] = tup[1];
            } else {
                newTup[0] = tup[1];
                newTup[1] = sum(tup[1], tup[2]);
                newTup[2] = tup[2];
            }
            tup = newTup;
        }
        cout << tup[1].n << "/" << tup[1].d << endl;
    }
    return 0;
}
