#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int dynamic_CD(vector<int> &vi, int N, vector<int>& ans){
    int sum;
    int T = vi.size();
    vector<int> table(N+1, 0);
    table[0] = -1;
    for(int i = 0; i < T; ++i){
        int val = vi[i];
        for(int j = N; j >= val; --j){
            if(table[j-val] != 0 && table[j] == 0)    table[j] = val;
        }
    }

    // cout << "print table: ";
    // for(int i = 0; i <= N; ++i)
    //     cout << table[i] << " ";
    // cout << endl;

    for(int i = N; i >= 0; --i){
        if(table[i]){
            sum = i;
            break;
        }
    }

    for(int i = sum; i != 0; ){
        ans.push_back(table[i]);
        i = i - table[i];
    }

    reverse(ans.begin(), ans.end());
    return sum;
}



int main(){
    int N, T, sum;
    while(cin >> N, !cin.eof()){
        cin >> T;
        vector<int> vi(T, 0);
        vector<int> ans;
        for(int i = 0; i < T; ++i){
            cin >> vi[i];
        }

        sum = dynamic_CD(vi, N, ans);
        for(int i = 0; i < ans.size(); ++i)
            cout << ans[i] << " ";
        cout << "sum:" << sum << endl;

    }
    return 0;
}
