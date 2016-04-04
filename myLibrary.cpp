#include "myLibrary.h"
#include <iostream>

using namespace std;

int main(){
    // UnionFind u(8);
    // for(int i = 0; i < 8; i += 2)   u.linkSet(i, i+1);
    // u.showParent();
    // u.showRank();
    // for(int i = 0; i < 8; ++i)
        // cout << u.findSet(i) << endl;

    // for(int i = 0; i < 6; i += 2)   u.linkSet(i, i + 2);  // rank 3 sets
    // u.showRank();
    //
    // UnionFind s(8);
    // for(int i = 0; i < 8; i += 2)   s.linkSet(i, i+1);
    // s.linkSet(0, 2);  s.linkSet(4, 6);
    // s.linkSet(0, 4);  // rank 4 sets
    // s.showRank();

    int arr[] = {47, 28, 61, 18, 76, 56, 22, 83, 34, 95};
    vector<int> A(arr, arr + 10);
    SegmentTree st(A);
    cout << "RMQ(0, 6) = " << st.rmq(0, 6) << endl;
    cout << "RMQ(3, 8) = " << st.rmq(3, 8) << endl;
    cout << "RMQ(1, 5) = " << st.rmq(1, 5) << endl;
    cout << "RMQ(4, 8) = " << st.rmq(4, 8) << endl;
    st.update(5, 4);
    cout << "RMQ(0, 6) = " << st.rmq(0, 6) << endl;
    cout << "RMQ(3, 8) = " << st.rmq(3, 8) << endl;
    cout << "RMQ(1, 5) = " << st.rmq(1, 5) << endl;
    cout << "RMQ(4, 8) = " << st.rmq(4, 8) << endl;
    cout << "RMQ(0, 4) = " << st.rmq(0, 4) << endl;

    // int f[] = {2, 4, 5, 5, 6, 6, 6, 7, 7, 8, 9};
    // FenwickTree ft(10);
    // for(int i = 0; i < 11; ++i) ft.adjust(f[i], 1);
    // cout << ft.rsq(1, 1) << endl;
    // cout << ft.rsq(1, 2) << endl;
    // cout << ft.rsq(1, 6) << endl;
    // cout << ft.rsq(1, 10) << endl;
    // cout << ft.rsq(3, 6) << endl;
    // ft.adjust(5, 2);
    // cout << ft.rsq(1, 10) << endl;
    return 0;
}
