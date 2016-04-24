#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define vi vector<int>

using namespace std;

class FenwickTree{
private:
    vi ft, A;
    int leastOne(int x){
        return x & (-x);
    }

    int rsq(int a){
        int sum = 0;
        for(int i = a; i > 0; i -= leastOne(i)){
            sum += ft[i];
        }
        return sum;
    }

public:
    FenwickTree(const vi &_A){
        A.assign(_A.size(), 0);
        ft.assign(_A.size(), 0);
        for(int i = 1; i < A.size(); ++i)   update(i, _A[i]);
    }

    void update(int idx, int val){
        int diff = val - A[idx];
        A[idx] = val;
        for(int i = idx; i < A.size(); i += leastOne(i)){
            ft[i] += diff;
        }
    }

    int rsq(int a, int b){
        return rsq(b)-rsq(a-1);
    }
};

int main(){ _
    int N, TC = 0;
    while(cin >> N){
        if(!N)  break;

        if(TC)  cout << endl;
        cout << "Case " << ++TC << ":" << endl;

        vi A(N+1, 0);
        for(int i = 1; i <= N; ++i)  cin >> A[i];

        FenwickTree ft(A);

        string str; cin.ignore();
        char type;  int a, b;
        while(getline(cin, str)){
            if(str == "END")    break;
            stringstream ss;
            ss << str;
            ss >> type >> a >> b;

            switch (type) {
                case 'M':
                    cout << ft.rsq(a, b) << endl;
                    break;
                case 'S':
                    ft.update(a, b);
                    break;
            }
        }

    }
    return 0;
}
