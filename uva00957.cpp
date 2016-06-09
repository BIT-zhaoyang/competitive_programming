#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

/*                                 UB       <- upper_bound
          a1 a2 a3 ... t t t t t t b1 b2 b3
        lower_bound-> LB

        t: target value
*/

/* Intuitive explanation on the following two functions:
    The only difference lies at if(vi[M] < targetYear) and if(vi[M] <= targetYear).
    Why this difference gives different performance?
    Let's consider the previous one step before the 'while' loop terminates.
    Before the while loop terminates, the relatino of L, R, M must be:
        1 <= R - L <= 2;    // plot this you will get it
        L <= M < R; -> vi[L] <= vi[M] < vi[R]

    In each iteration, either L increase or R decrease(R implicitly decrease due to the downwards of integer division).

    In case 1: R - L = 2, M = L + 1. if(vi[M] < targetYear), L = M + 1 = R. Then at this time, vi[L] >= targetYear. The reason is that, last time we get to R = M, it's due to vi[M] >= targetYear.
    In case 2: L = M = R-1. Smiliar argument applies.

    In short, in lower_bound, L keeps increasing when vi[M] < targetYear thus finally gives us lower_bound. In upper_bound, L keeps increasing when vi[M] <= targetYear and once it reach a point that vi[L] > targetYear, since L <= M < R, L will never increase.
*/

int low_bound(int targetYear, vector<int> &vi){
    if(vi.back() < targetYear)  return -1;
    
    int L = 0, R = vi.size()-1, M;
    while(L < R){
        M = (L+R)/2;
        // when use vi[m] < targetYear, it's lower_bound
        // lower_bound gives the index of first element no less than the target value
        if(vi[M] < targetYear) L = M+1;
        else R = M;
    }

    return L;
}

int up_bound(int targetYear, vector<int> &vi){
    if(vi.back() < targetYear)  return -1;

    int L = 0, R = vi.size()-1, M;
    while(L < R){
        M = (L+R)/2;
        // when use vi[m] <= targetYear, it's upper_bound
        // upper_bound gives the index of the first element larger than target value
        if(vi[M] <= targetYear) L = M+1;
        else R = M;
    }

    return L;
}

int main(){ _
    int Y, N;
    while(cin >> Y){
        cin >> N;
        vector<int> vi(N, 0);
        for(int i = 0; i < N; ++i)   cin >> vi[i];

        int targetYear = 0, j = -1, length = -1, start, end; // j: index to the last Pope within in the constraint years
        for(int i = 0; i < N; ++i){
            targetYear = vi[i] + Y - 1;
            j = up_bound(targetYear, vi);
            if(j-i > length){
                length = j-i;
                start = i;
                end = j;
            }
        }

        cout << length << " " << vi[start] << " " << vi[end-1] << endl;
    }
    return 0;
}
