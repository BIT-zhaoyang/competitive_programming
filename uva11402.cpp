#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define vi vector<int>

using namespace std;

/*
    References: http://lbv-pc.blogspot.fi/2012/10/ahoy-pirates_24.html
    Notes:
        Whenever we need to read values from a node, and its children has pending updating operations to be done, no matter we will go to that children we need to perform the update first since the children's value will affect this node's value which will affect the result!
*/

class SegmentTree{
private:
    vector<int> A, st, mutate;
    int n;

    int left(int p){return p << 1;}
    int right(int p){return (p << 1)+1;}

    void build(int p, int s, int e){
        if(s == e){
            st[p] = A[s];
        } else {
            int mid = (s+e)/2;
            build(left(p), s, mid);
            build(right(p), mid+1, e);

            st[p] = st[left(p)] + st[right(p)];
        }
    }

    int rsq(int p, int s, int e, int l, int r){
        update(p, s, e);

        if(s > r || e < l)  return 0;
        if(s >= l && e <= r)    return st[p];

        int mid = (s+e)/2;
        int s1 = rsq(left(p), s, mid, l, r);
        int s2 = rsq(right(p), mid+1, e, l, r);

        return s1+s2;
    }

    void update(int p, int s, int e){
        if(mutate[p] == 0)  return;

        switch (mutate[p]) {
            case 'F':   st[p] = e-s+1;  break;
            case 'E':   st[p] = 0;  break;
            case 'I':   st[p] = e-s+1 - st[p];  break;
        }

        propogate(p, s, e);
        mutate[p] = 0;
    }

    void propogate(int p, int s, int e){
        if(s == e)  return;
        int l = left(p), r = right(p);
        switch (mutate[p]) {
            case 'F':   mutate[l] = 'F'; mutate[r] = 'F'; break;
            case 'E':   mutate[l] = 'E'; mutate[r] = 'E'; break;
            case 'I':
                if(mutate[l] == 'I')    mutate[l] = 0;
                else if(mutate[l] == 'F')   mutate[l] = 'E';
                else if(mutate[l] == 'E')   mutate[l] = 'F';
                else mutate[l] = 'I';

                if(mutate[r] == 'I')    mutate[r] = 0;
                else if(mutate[r] == 'F')   mutate[r] = 'E';
                else if(mutate[r] == 'E')   mutate[r] = 'F';
                else mutate[r] = 'I';

                break;
        }
    }

    void change(int p, int s, int e, int type, int l, int r){
        update(p, s, e);
        if(s > r || e < l)  return;
        if(s >= l && e <=r){
            mutate[p] = type;
            update(p, s, e);
            return;
        }

        change(left(p), s, (s+e)/2, type, l, r);
        change(right(p), (s+e)/2+1, e, type, l, r);
        st[p] = st[left(p)] + st[right(p)];
    }
public:
    SegmentTree(const vector<int> &_A){
        A = _A; n = A.size();
        st.assign(n<<2, 0);
        mutate.assign(n<<2, 0);
        build(1, 0, n-1);
    }

    int rsq(int l, int r){
        return rsq(1, 0, n-1, l, r);
    }

    void change(int type, int l, int r){
        change(1, 0, n-1, type, l, r);
    }
};

int main(){ _
    int TC; cin >> TC;
    for(int c = 1; c <= TC; ++c){
        int M;  cin >> M;
        string total = "", each;
        int R;
        for(int i = 0; i < M; ++i){
            cin >> R >> each;
            for(int j = 0; j < R; ++j)
                total += each;
        }

        int n = total.length();
        vector<int> pirates(n, 0);
        for(int i = 0; i < n; ++i){
            pirates[i] = (total[i] - '0');
        }

        SegmentTree st(pirates);

        int K;  cin >> K;
        char ch;
        int s, e, count = 1;

        cout << "Case " << c << ":" << endl;

        for(int i = 0; i < K; ++i){
            cin >> ch >> s >> e;
            if(ch == 'S'){
                cout << "Q" << count++ << ": " << st.rsq(s, e) << endl;
            } else {
                st.change(ch, s, e);
            }
        }
    }
    return 0;
}
