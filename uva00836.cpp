#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

int matrix[25][25];
int column[25];

int max1Dsum(int n){
    int sum = 0, ans = 0;
    for(int i = 0; i < n; ++i){
        sum = max(column[i], sum+column[i]);
        ans = max(sum, ans);
    }
    return ans;
}

int max2Dsum(int n){
    for(int i = 0; i < n; ++i)
        for(int j = 1; j < n; ++j)
            matrix[i][j] += matrix[i][j-1];

    int ans = 0;
    for(int i = 0; i < n; ++i)
        for(int j = i; j < n; ++j){
            for(int k = 0; k < n; ++k){
                if(i)   column[k] = matrix[k][j] - matrix[k][i-1];
                else    column[k] = matrix[k][j];
            }

            ans = max(ans, max1Dsum(n));
        }
    return ans;
}

int main(){ _
    int TC; cin >> TC;
    cin.ignore();
    while(TC--){
        memset(matrix, 0, sizeof matrix);
        memset(column, 0, sizeof column);

        string str;
        getline(cin, str);  //read the blank line before each test case
        getline(cin, str);  // read first line
        int n = str.size();
        for(int i = 0; i < n; ++i){
            if(str[i] == '0')   matrix[0][i] = -1000;
            else    matrix[0][i] = 1;
        }
        for(int i = 1; i < n; ++i){
            getline(cin, str);
            for(int j = 0; j < n; ++j){
                if(str[j] == '0')   matrix[i][j] = -1000;
                else    matrix[i][j] = 1;
            }
        }

        cout << max2Dsum(n) << endl;
        if(TC)  cout << endl;
    }
    return 0;
}
