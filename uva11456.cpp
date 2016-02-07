//
//  uva11456.cpp
//  
//
//  Created by 赵洋 on 15/11/9.
//
//

// A better solution: https://saicheems.wordpress.com/2013/09/01/uva-11456-trainsorting/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int LIS(int s, vector<int> &X){
    int n = X.size();
    int L = 0;
    
    vector<int> M(n+1, 0);
    for(int i = s; i < n; ++i){
        if(X[i] < X[s]) continue;
        
        int lo = 1, hi = L, mid;
        while(lo <= hi){
            mid = ceil((lo + hi) / 2);
            if(X[i] >= X[M[mid]]){
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        M[lo] = i;
        if(lo > L){
            L = lo;
        }
    }
    
    return L;
}

int LDS(int s, vector<int> &X){
    int n = X.size();
    int L = 0;
    
    vector<int> M(n+1, 0);
    for(int i = s; i < n; ++i){
        if(X[i] > X[s]) continue;
        
        int lo = 1, hi = L, mid;
        while(lo <= hi){
            mid = ceil((lo + hi) / 2);
            if(X[i] <= X[M[mid]]){
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        M[lo] = i;
        if(lo > L){
            L = lo;
        }
    }
    
    return L;
}




int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> X(n, 0);
        for(int i = 0; i < n; ++i){
            cin >> X[i];
        }
        
        int opt = 0;
        for(int i = 0; i < n; ++i){
            opt = max(opt, LIS(i, X) + LDS(i, X) - 1);
        }
        
        cout << opt << endl;
    }
}
