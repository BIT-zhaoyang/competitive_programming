//
//  uva00481.cpp
//
//
//  Created by 赵洋 on 15/11/9.
//
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    vector<int> X;
    int input;
    while(cin >> input, !cin.eof()){
        X.push_back(input);
    }

    int n = X.size();
    vector<int> M(n+1, 0);  // M[i] stores the index of the smallest value X[k] which is the        last element ending at a sequence of length i
    vector<int> P(n, 0);    // P[i] stores the index of the previous element of X[k] in the increasing sequence

    int L = 0;  // the length of the LIS we have found
    for(int i = 0; i < n; ++i){
        int lo = 1, hi = L, mid;
        while(lo <= hi){
            mid = ceil((lo + hi) / 2);
            if(X[i] > X[M[mid]]){
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        M[lo] = i;
        P[i] = M[lo - 1];

        if(lo > L){
            L = lo;
        }
    }
    
    vector<int> answer(L, 0);
    int index = M[L];
    for(int i = L; i > 0; --i){
        answer[i-1] = X[index];
        index = P[index];
    }

    cout << L << endl;
    cout << "-" << endl;

    for(int i = 0; i < L; ++i){
        cout << answer[i] << endl;
    }
}
