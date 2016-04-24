#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;

class SegmentTree{
private:
    vector<int> A, st;
    int n;

    int left(int p) {return (p << 1);}
    int right(int p) {return (p<<1)+1;}

    int search(int p, int s, int e, int l, int r){
        if(s > r || e < l)  return -1;
        if(s >= l && e <= r)    return st[p];

        int p1 = search(left(p), s, (s+e)/2, l, r);
        int p2 = search(right(p), (s+e)/2+1, e, l, r);

        if(p1 == -1)    return p2;
        if(p2 == -1)    return p1;
        return (A[p1] >= A[p2]) ? p1 : p2;
    }

    void build(int p, int s, int e){
        if(s == e){
            st[p] = s;
        } else {
            build(left(p), s, (s+e)/2);
            build(right(p), (s+e)/2+1, e);

            int p1 = st[left(p)];
            int p2 = st[right(p)];

            st[p] = (A[p1] >= A[p2]) ? p1:p2;
        }
    }

    void update(int p, int s, int e, int idx, int val){
        int l = idx, r = idx;
        if(s > r || e < l)  return;
        if(s == l && e == l){
            A[idx] = val;
            st[p] = idx;
            return;
        }

        update(left(p), s, (s+e)/2, idx, val);
        update(right(p), (s+e)/2+1, e, idx, val);

        int p1 = st[left(p)];
        int p2 = st[right(p)];

        st[p] = (A[p1] >= A[p2]) ? p1:p2;
    }

public:
    SegmentTree(const vector<int> &_A){
        n = _A.size();
        A = _A;
        st.assign(4*n, 0);
        build(1, 0, n-1);
    }

    int search(int l, int r){
        if(l > r)   return 0;
        else        return A[search(1, 0, n-1, l, r)];
    }

    void update(int idx, int val){
        update(1, 0, n-1, idx, val);
    }
};


int main(){ _
    int n, k;
    while(cin >> n){
        if(n == 0)  break;

        cin >> k;
        vector<int> ends, counts, A(n,0);
        map<int, int> idx;

        int cnt = 0, num = 0, last = INT_MIN, curr = 0;
        for(int i = 0; i < n; ++i){
            cin >> curr;
            A[i] = curr;
            if(curr != last){
                // preserve attributes for old value
                ends.push_back(i);
                counts.push_back(cnt);
                idx[last] = num;

                // reset attributes for new value
                cnt = 1;
                ++num;
                last = curr;
            } else {
                ++cnt;
            }
        }
        // preserve the attributes for the last value
        ends.push_back(n);
        counts.push_back(cnt);
        idx[curr] = num;


        // For check correctness
        // for(int i = 0; i < ends.size(); ++i){
        //     cout << counts[i] << " ";
        // }
        // cout << endl;
        // for(int i = 0; i < ends.size(); ++i){
        //     cout << ends[i] << " ";
        // }
        // cout << endl;
        //
        // for(map<int, int>::iterator it = idx.begin(); it != idx.end(); ++it){
        //     cout << it->second << " ";
        // }
        // cout << endl;


        // process queries
        SegmentTree st(counts);
        int l, r, num1, num2, idx1, idx2, leftNum, rightNum;
        for(int i = 0; i < k; ++i){
            cin >> l >> r;
            --l, --r;
            num1 = A[l], num2 = A[r];
            idx1 = idx[num1], idx2 = idx[num2];
            if(num1 == num2){
                cout << r-l+1 << endl;
            } else {
                int mid = st.search(idx1+1, idx2-1);
                int left = ends[idx1] - l;
                int right = r - ends[idx2-1] + 1;

                int ans = max(mid, left);
                ans = max(ans, right);
                cout << ans << endl;
            }
        }
    }
    return 0;
}
