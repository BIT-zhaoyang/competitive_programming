#ifndef LIBRARY
#define LIBRARY

#include <vector>
#include <iostream>
using namespace std;
class UnionFind{
private:
    vector<int> p, r;   // p: parent r: rank

public:
    void showRank(){
        for(int i = 0; i < r.size(); ++i)
            cout << r[i] << " ";
        cout << endl;
    }

    void showParent(){
        for(int i = 0; i < p.size(); ++i)
            cout << p[i] << " ";
        cout << endl;
    }

    UnionFind(int n){
        p.assign(n, 0);
        r.assign(n, 0);
        for(int i = 0; i < n; ++i){
            p[i] = i;
        }
    }

    bool isSameSet(int x, int y){
        return findSet(x) == findSet(y);
    }

    int findSet(int n){
        if(p[n] != n)   p[n] = findSet(p[n]);
        return p[n];
    }

    void linkSet(int a, int b){
        int x = findSet(a);
        int y = findSet(b);

        if(x == y)  return;

        if(r[x] > r[y]){
            p[y] = x;
        } else {
            p[x] = y;
            if(r[x] == r[y])
                r[y] += 1;
        }
    }

};

/*  NOTES ABOUT SEGMENT TREE
    I want to write a very ingenious trick used in this implementation.
    As shown in the competitive programming 3 book, each node should store three elements:
        1. the left index of the range,
        2. the right index of the range,
        3. and the index of the minimum key in this range
    However, in this implementation, each element in the vector<int> st represents a node, and in this element, only the index of the minimum key is stored. Both the left index and right index are eliminated.

    The reason is that this algorithm is a deterministic algorithm. The left index and right index of each node is fixed. And we can always compute these two indexes in O(1) time. Thus, we don't need to store this information. We get this information when we doing build, and rmq.
    We can't recover the information only based on the index p, thus, we have to pass the index along with index p.
*/
class SegmentTree{
private:
    vector<int> st, A;
    int left(int p){ return p << 1;}
    int right(int p) { return (p << 1) + 1;}

    void build(int p, int s, int e){
        if(s == e){
            st[p] = s;
            return;
        }

        build( left(p),           s, (s+e)/2);
        build(right(p), (s+e)/2 + 1,       e);

        int p1 = st[left(p)];
        int p2 = st[right(p)];

        st[p] = (A[p1] < A[p2]) ? p1:p2;
    }

    int rmq(int p, int s, int e, int L, int R){
        // p: current index we are looking at
        // s: left border of the range st[p] contains
        // e: right border of the range st[p] contains;
        // L: left border of the range we are querying
        // R: right border of the range we are querying.
        if(e < L || s > R)  return -1;
        if(s >= L && e <=R) return st[p];   // there will be at least one '=' holds

        int p1 = rmq( left(p),         s, (s+e)/2, L, R);
        int p2 = rmq(right(p), (s+e)/2+1,       e, L, R);

        if(p1 == -1)    return p2;
        if(p2 == -1)    return p1;

        return (A[p1] < A[p2]) ? p1:p2;
    }

    void update(int p, int s, int e, int q, int v){
        if(s == e && s == q){
            A[q] = v;   // update A[q] here. No need to update st[p].
            return;
        } else {
            if(q > (s+e)/2) update(right(p), (s+e)/2+1, e, q, v);
            else update(left(p), s, (s+e)/2, q, v);

            int p1 = st[left(p)];
            int p2 = st[right(p)];

            st[p] = (A[p1] < A[p2]) ? p1:p2;
        }
    }

public:
    SegmentTree(const vector<int> _A){
        A = _A;
        st.assign(A.size()*4, 0);
        build(1, 0, A.size()-1);
    }

    int rmq(int L, int R){
        return rmq(1, 0, A.size()-1, L, R);
    }

    void update(int p, int v){
        update(1, 0, A.size()-1, p, v);
    }


};

class FenwickTree{
private:
    vector<int> vi;
    int LSone(int x){
        return x & (-x);
    }

    int rsq(int p){
        int sum = 0;
        for( ; p > 0; p -= LSone(p)){
            sum += vi[p];
        }
        return sum;
    }

public:
    FenwickTree(int n){
        vi.assign(n+1, 0);
    }

    int rsq(int a, int b){  // assume b >= a
        return rsq(b) - rsq(a-1);
    }

    void adjust(int p, int val){    // val is the difference added to the vi[p]
        for( ; p < vi.size(); p += LSone(p)){
            vi[p] += val;
        }
    }
};

#endif
