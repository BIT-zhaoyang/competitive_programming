/*
    reference: https://www.quora.com/How-do-I-solve-the-nested-doll-problem-on-SPOJ
    sort by one dimension x, if x1 == x2, break the tie by sorting y in decresing order.
 
    after sorting, find longest non-increasing sequence.
    the idea is that, when x2 > x1, (because we sort x in ascending order), if we get a y2 < y1,
    then these two nodes are not comparable, so they are parts of an antichain.
 
    by finding a longest non-increasing sequence, we have made sure that the newest node is not comparable
    with any previous node, because only a node not comparable with any seen variable will be added to the antichain.
 
    UPDATES:!!!!
    M[j] represents the index of the element ending at the j-th chain! Because once an element fits into a chain, it will
    pick one chain in the formed 'j' chains, and will replace the j-th chains ending element.
 
*/

#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

#define pii pair<int, int>

using namespace std;

struct Doll{
    int w, h;

    Doll(int _w, int _h){
        w = _w;
        h = _h;
    }
};

bool cmp(Doll &d1, Doll &d2){
    if(d1.w != d2.w){
        return d1.w < d2.w;
    } else {
        return d1.h > d2.h;
    }
};



int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<Doll> X;
        int w, h;
        for(int i = 0; i < n; ++i){
            cin >> w >> h;
            X.push_back(Doll(w, h));
        }
        
        sort(X.begin(), X.end(), cmp);
        
        int L = 0;
        vector<int> M(n+1, 0);
        for(int i = 0; i < n; ++i){
            int lo = 1, hi = L, mid;
            while(lo <= hi){
                mid = ceil((lo + hi) / 2);
                if(X[i].h > X[M[mid]].h){
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            
            M[lo] = i;
            
            if(lo > L){
                L = lo;
            }
        }
        
        cout << L << endl;
    }
}



