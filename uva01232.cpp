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

#define MAXN 100000
/*
    Though accepted, I feel this solution is not very elegant.
    This solution used the same idea -- lazy updation as the Ahoi! Pirates! problem.
*/

class SegmentTree{
private:
    vector<int> minimum, maximum, mutate;
private:
    int left(int p){return p<<1;}
    int right(int p){return (p<<1)|1;}

    void update(int p, int s, int e){
        if(mutate[p] == 0)  return;

        minimum[p] = maximum[p] = mutate[p];
        if(s+1 != e)    mutate[left(p)] = mutate[right(p)] = mutate[p];
        mutate[p] = 0;
    }

    int query(int p, int s, int e, int l, int r, int v){
        update(p, s, e);
        if(s >= r || e <= l)  return 0;
        if(s >= l && e <= r){
            if(maximum[p] <= v){
                mutate[p] = v;
                update(p, s, e);
                return e-s;
            }

            if(minimum[p] > v)  return 0;
        }

        int s1 = query(left(p), s, (s+e)/2, l, r, v);
        int s2 = query(right(p), (s+e)/2, e, l, r, v);

        minimum[p] = min(minimum[left(p)], minimum[right(p)]);
        maximum[p] = max(maximum[left(p)], maximum[right(p)]);
        return s1 + s2;
    }
public:
    SegmentTree(){
        minimum.assign(MAXN<<2, 0);
        maximum.assign(MAXN<<2, 0);
        mutate.assign(MAXN<<2, 0);
    }
    int query(int l, int r, int v){
        return query(1, 1, MAXN, l, r, v);
    }
};

int main(){ _
    int TC, n; cin >> TC;
    while(cin >> n, n){
        SegmentTree st;

        int l, r, v, ans = 0;
        for(int i = 0; i < n; ++i){
            cin >> l >> r >> v;
            ans += st.query(l, r, v);
            // cout << st.query(l, r, v) << endl;
        }
        cout << ans << endl;
    }
    return 0;
}
