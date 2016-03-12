#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

bool next_permute(vector<int> &A){
    //## partition A into three parts: prefix, pivot, suffix
    int pivot = -1;
    for(int i = A.size()-1; i > 0; --i){
        if(A[i] > A[i-1]){
            pivot = i-1;
            break;
        }
    }

    if(pivot == -1) return false;

    //## swap pivot and the smallest element in suffix which is larger than pivot to form the new suffix
    for(int i = A.size() - 1; i > pivot; --i){
        if(A[i] > A[pivot]){
            swap(A[pivot], A[i]);
            break;
        }
    }

    //## reverse the new suffix
    reverse(A.begin() + pivot+1, A.end());
    return true;
}

int main(){
    int k;
    cin >> k;
    while(k != 0){
        vector<int> S(k, 0);
        for(int i = 0; i < k; ++i){
            cin >> S[i];
        }

        vector<int> A(k, 0);
        fill(A.begin(), A.begin() + 6, 1);
        do{
            int counter = 0;
            for(int i = 0; i < k; ++i){
                if(A[i] == 1){
                    if(counter != 0){
                        cout << " ";
                    }
                    cout << S[i];
                    ++counter;
                }
            }
            cout << endl;
        }while(prev_permutation(A.begin(), A.end()));

        cin >> k;
        if(k != 0)  cout << endl;
    }

    return 0;
}
