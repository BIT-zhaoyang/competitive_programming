//
//  5072.cpp
//  
//
//  Created by 赵洋 on 15/9/5.
//
//

#include <iostream>
using namespace std;

//bool isConflict(int*, int*);
//bool isUnique(int*, int*);

int main(){
    int nLoop;
    cin >> nLoop;
    for( ; nLoop > 0; --nLoop){
        int nP, nE; //nP: number of politicians  nE: number of evidences
        cin >> nP >> nE;
//        if(nE == 0){
//            cout << "MULTIPLE" << endl;
//            continue;
//        }
        
        int* a = (int*)malloc((nP+1) * sizeof(int));
        for(int i = 0; i <= nP; ++i) a[i] = 0;
        int invalid = 0;
        
        int e1, e2;
        for(int i = 0; i < nE; ++i){
            cin >> e1 >> e2;
            if(e1 != e2){
                invalid += 1;
                continue;
            }
            if(e1 > 0){
                a[e1] += e1;
            } else {
                a[-e1] += e1;
            }
        }
        
        if(nE == invalid){
            cout << "MULTIPLE" << endl;
            continue;
        }
        
        bool flag = true;
        for(int i = 1; i <= nP; ++i){
            if(a[i] != (i*nE - invalid) && a[i] != (-i*nE + invalid)){
                cout << "CONFLICT" << endl;
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "UNIQUE" << endl;
        }
    }
}