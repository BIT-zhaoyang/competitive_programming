#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define vi vector<int>

using namespace std;

//14:24
class SegmentTree{
private:
    int n;
    vi A, st;

    int left(int p){return p<<1;}
    int right(int p){return (p<<1)|1;}

    int rmq(int p, int s, int e, int l, int r){ // range minimum query
        if(s > r || e < l)  return -1;
        if(s >= l && e <= r)    return st[p];

        int p1 = rmq(left(p), s, (s+e)/2, l, r);
        int p2 = rmq(right(p), (s+e)/2+1, e, l, r);

        if(p1 == -1)    return p2;
        if(p2 == -1)    return p1;

        return (A[p1] <= A[p2]) ? p1:p2;
    }

    void build(int p, int s, int e){
        if(s == e){
            st[p] = s;
        } else {
            build(left(p), s, (s+e)/2);
            build(right(p), (s+e)/2+1, e);

            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1]<= A[p2]) ? p1:p2;
        }
    }

    void update(int p, int s, int e, int idx, int val){
        int l = idx, r = idx;
        if(s > r || e < l)  return;
        if(s == l && e == r){
            A[idx] = val;
            st[p] = idx;
            return;
        }

        update(left(p), s, (s+e)/2, idx, val);
        update(right(p), (s+e)/2+1, e, idx, val);

        int p1 = st[left(p)], p2 = st[right(p)];
        st[p] = (A[p1]<= A[p2]) ? p1:p2;
    }

public:
    SegmentTree(const vi &_A){
        n = _A.size();  A = _A;
        st.assign(n<<2, 0);
        build(1, 0, n-1);
    }

    int rmq(int l, int r){  // note that the returned value is the index to the minimum element
        return rmq(1, 0, n-1, l, r);
    }

    void update(int idx, int val){
        update(1, 0, n-1, idx, val);
    }
};

int main(){ _
    int n;  cin >> n;
    vector< vi > pos(n, vi (n, 0));
    vector< vi > neg(n, vi (n, 0));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> pos[i][j];
            neg[i][j] = -pos[i][j];
        }
    }

    vector<SegmentTree> psf;
    vector<SegmentTree> nsf;
    for(int i = 0; i < n; ++i){
        psf.push_back(SegmentTree (pos[i]));
        nsf.push_back(SegmentTree (neg[i]));
    }


    int k;  cin >> k;
    char ch;
    int x1, y1, x2, y2, val;
    for(int j = 0; j < k; ++j){
        cin >> ch;
        if(ch == 'q'){
            cin >> x1 >> y1 >> x2 >> y2;
            --x1, --y1, --x2, --y2;
            int least = INT_MAX, most = INT_MAX, idx;
            for(int i = x1; i <= x2; ++i){
                idx = psf[i].rmq(y1, y2);
                least = min(pos[i][idx], least);

                idx = nsf[i].rmq(y1, y2);
                most = min(neg[i][idx], most);
            }
            cout << -most << " " << least << endl;
        } else {
            cin >> x1 >> y1 >> val;
            --x1, --y1;
            pos[x1][y1] = val;
            neg[x1][y1] = -val;

            psf[x1].update(y1, val);
            nsf[x1].update(y1, -val);
        }
    }
    return 0;
}
