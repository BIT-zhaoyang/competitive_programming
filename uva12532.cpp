#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define vi vector<int>
using namespace std;
/*
    This problem can be solved using either SegmentTree or FenwickTree.
    When using SegmentTree, we just need to modify it to query range product which can be implemented easily. One little trick I used here is that I used 1, 0, -1 to represent pos, 0, and neg numbers so that we don't have to worry about overflow. The update function is the same as a normal rsq, rmq SegmentTree tree with operation replaced by '*'. This solution gives 0.090s solution in uva.

    Using FenwickTree is also straightforward. We build two trees. One keeps the number of zeros in range(a, b) and the other one keeps the number of negs in range(a, b). When we do query, we first check if there is any zero in this range. If there is, the answer is 0. If not, we check if we have odd number of negs in this range. If yes, the answer is '-'. Otherwise, the answer is '+'. But the implementation is a bit tedious as shown in the code.
*/
class SegmentTree{
private:
    vi A,st;

    void build(int p, int s, int e){
        if(s == e){
            if(A[s] > 0)    st[p] = 1;
            else if(A[s] < 0)   st[p] = -1;
            else    st[p] = 0;
        } else {
            build(p<<1, s, (s+e)/2);
            build((p<<1)+1, (s+e)/2+1, e);

            st[p] = st[p<<1] * st[(p<<1) + 1];
        }
    }
    int rpq(int p, int s, int e, int l, int r){
        if(s > r || e < l)  return 1;
        if(s >= l && e <= r)    return st[p];

        int p1 = rpq(p<<1, s, (s+e)/2, l, r);
        int p2 = rpq((p<<1)+1, (s+e)/2+1, e, l, r);

        return p1*p2;
    }
    void update(int p, int s, int e, int idx, int val){
        if(e < idx || s > idx)  return;
        // this statement has two functions: 1. save time since we don't have to update range disconnect with required range. 2. if we don't write thsi statement, we left one base case out and the recursion will continue forever, leading to memory error.
        if(s == idx && e == idx){
            if(val > 0)    st[p] = 1;
            else if(val < 0)   st[p] = -1;
            else    st[p] = 0;
        } else {
            update(p << 1, s, (s+e)/2, idx, val);
            update((p << 1) + 1, (s+e)/2+1, e, idx, val);

            st[p] = st[p<<1] * st[(p<<1)+1];
        }
    }
public:
    SegmentTree(const vi& _A){
        A = _A;
        st.assign(A.size() << 2, 0);
        build(1, 0, A.size()-1);
    }
    int rpq(int l, int r){  return rpq(1, 0, A.size()-1, l, r); }
    void update(int idx, int val){  update(1, 0, A.size()-1, idx, val); }
};

class FenwickTree{
private:
    vi ft;
    int leastOne(int i){return i & (-i);}
    int rsq(int idx){
        int sum = 0;
        for(; idx; idx -= leastOne(idx))    sum += ft[idx];
        return sum;
    }
public:
    FenwickTree(int n){ ft.assign(n+1, 0);  }
    void update(int idx, int val){
        for(; idx < ft.size(); idx += leastOne(idx))    ft[idx] += val;
    }
    int rsq(int a, int b){  return rsq(b) - rsq(a-1);   }
};


int main(){ _
    int N, K;
    while(cin >> N >> K){
        //  ===================== Using SegmentTree =====================
        // vi A(N, 0);
        // for(int i = 0; i < N; ++i)  cin >> A[i];
        // SegmentTree st(A);
        //
        // char ch;    int a, b, result;
        // for(int i = 0; i < K; ++i){
        //     cin >> ch >> a >> b;
        //     switch (ch) {
        //         case 'C':
        //             st.update(a-1, b);
        //             break;
        //         case 'P':
        //             result = st.rpq(a-1, b-1);
        //             if(result > 0)  cout << "+";
        //             else if(result < 0) cout << "-";
        //             else    cout << "0";
        //             break;
        //     }
        // }
        // cout << endl;

        // ===================== Using FenwickTree ===================
        FenwickTree zeros(N);
        FenwickTree negs(N);

        vi A(N+1, 0);
        for(int i = 1; i <= N; ++i){
            cin >> A[i];
            if(A[i] == 0)    zeros.update(i, 1);
            else if(A[i] < 0)    negs.update(i, 1);
        }

        char ch;    int a, b, result;
        for(int i = 0; i < K; ++i){
            cin >> ch >> a >> b;
            switch(ch){
                case 'C':
                    if(A[a] > 0 && b > 0){

                    } else if(A[a] == 0 && b > 0){
                        zeros.update(a, -1);
                    } else if(A[a] < 0 && b > 0){
                        negs.update(a, -1);
                    } else if(A[a] > 0 && b == 0){
                        zeros.update(a, 1);
                    } else if(A[a] == 0 && b == 0){

                    } else if(A[a] < 0 && b == 0){
                        negs.update(a, -1);
                        zeros.update(a, 1);
                    } else if(A[a] > 0 && b < 0){
                        negs.update(a, 1);
                    } else if(A[a] == 0 && b < 0){
                        zeros.update(a, -1);
                        negs.update(a, 1);
                    } else if (A[a] < 0 && b < 0){

                    }

                    A[a] = b;   // don't forget to update A!
                    break;
                case 'P':
                    int numZ = zeros.rsq(a, b);
                    int numN = negs.rsq(a, b);
                    if(numZ > 0)    cout << 0;
                    else if(numN % 2)   cout << "-";
                    else    cout << "+";

                    break;
            }
        }

        // ================= No need to modify code after here =================
        cout << endl;
    }
    return 0;
}
