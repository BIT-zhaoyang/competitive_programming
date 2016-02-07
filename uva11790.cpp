//
//  uva11790.cpp
//
//
//  Created by 赵洋 on 15/11/9.
//
//

// reference: https://saicheems.wordpress.com/2013/09/02/uva-11790-murcias-skyline/


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int count = 1; count <= T; ++count){
        int n;
        cin >> n;
        vector<int> h(n + 1, 0);
        vector<int> w(n + 1, 0);
        
        for(int i = 1; i <= n; ++i){
            cin >> h[i];
        }
        
        for(int i = 1; i <= n; ++i){
            cin >> w[i];
        }
        
        vector<int> acc(n + 1, 0);
        vector<int> dec(n + 1, 0);
        int _inc = 0, _dec = 0;
        for(int i = 1; i <= n; ++i){
            acc[i] = dec[i] = w[i];
            for(int j = 1; j < i; ++j){
                if(h[i] > h[j]){
                    acc[i] = max(acc[i], acc[j] + w[i]);
                }
                
                if(h[i] < h[j]){
                    dec[i] = max(dec[i], dec[j] + w[i]);
                }
            }
            _inc = max(_inc, acc[i]);
            _dec = max(_dec, dec[i]);
        }
        
        
        
        
        cout << "Case " << count << ". ";
        if(_inc >= _dec){
            cout << "Increasing (" << _inc << "). Decreasing (" << _dec << ")." << endl;
        } else {
            cout << "Decreasing (" << _dec << "). Increasing (" << _inc << ")." << endl;
        }
        
    }
    return 0;
}

