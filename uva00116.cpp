#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

#define maxN    10
#define maxM    100
#define BIG_VALUE 1<<28
int matrix[maxN][maxM];
int choice[maxN][maxM];

vector<int> backtrack(int ro, int col){
    vector<int> ans;
    while(col > 0){
        ans.push_back(ro);
        ro = choice[ro][col];
        --col;
    }
    ans.push_back(ro);
    // reverse(ans.begin(), ans.end());
    return ans;
}

int main(){ _
    int n, m;
    while(cin >> n >> m){
        for(int i = 0; i < n; ++i){
            for(int j = m-1; j >= 0; --j){
                cin >> matrix[i][j];
            }
        }

        for(int col = 1; col < m; ++col){
            for(int ro = 0; ro < n; ++ro){
                int val = BIG_VALUE, choose = BIG_VALUE;

                if(matrix[(ro+n-1)%n][col-1] <= val){
                    if(matrix[(ro+n-1)%n][col-1] == val)    choose = min(choose, (ro+n-1)%n);
                    else{
                        val = matrix[(ro+n-1)%n][col-1];
                        choose = (ro+n-1)%n;
                    }
                }

                if(matrix[ro][col-1] <= val){
                    if(matrix[ro][col-1] == val)    choose = min(choose, ro);
                    else{
                        val = matrix[ro][col-1];
                        choose = ro;
                    }
                }

                if(matrix[(ro+1)%n][col-1] <= val){
                    if(matrix[(ro+1)%n][col-1] == val)  choose = min(choose, (ro+1)%n);
                    else{
                        val = matrix[(ro+1)%n][col-1];
                        choose = (ro+1)%n;
                    }
                }

                matrix[ro][col] = val + matrix[ro][col];
                choice[ro][col] = choose;
            }
        }

        int ans = INT_MAX;
        for(int i = 0; i < n; ++i)  ans = min(ans, matrix[i][m-1]);


        vector<int> output;
        for(int i = 0; i < n; ++i){
            if(matrix[i][m-1] == ans){
                output = backtrack(i, m-1);
                break;
            }
        }

        for(int i = 0; i < output.size(); ++i){
            cout << output[i]+1;
            if(i != output.size()-1) cout << " ";
        }   cout << endl;
        cout << ans << endl;
    }
    return 0;
}
