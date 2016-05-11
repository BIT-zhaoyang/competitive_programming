#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

void parse(string &ele, int &r, int &c){
    r = 0, c = 0;
    for(int i = 0; i < ele.size(); ++i){
        if(ele[i] >= 'A')   c = c*26 + ele[i]-'A'+1;
        else    r = r*10 + ele[i] -'0';
    }
    c -= 1;
    r -= 1;
}

int replace(vector< vector<string> > &input, vector< vector<int> > &output, int ro, int col){
    if(input[ro][col] == "replaced")    return output[ro][col];

    string cell(input[ro][col]);
    if(cell[0] == '='){
        string ele;
        int _ro, _col, sum = 0;
        for(int i = 1; i < cell.size(); ++i){
            if(cell[i] == '+'){
                parse(ele, _ro, _col);
                sum += replace(input, output, _ro, _col);
                ele = "";
            } else {
                ele += cell[i];
            }
        }
        parse(ele, _ro, _col);
        sum += replace(input, output, _ro, _col);
        output[ro][col] = sum;
        input[ro][col] = "replaced";
    } else{
        int sum;
        stringstream ss;
        ss << cell;
        ss >> sum;
        output[ro][col] = sum;
        input[ro][col] = "replaced";
    }

    return output[ro][col];
}

int main(){ _
    int TC; cin >> TC;
    while(TC--){
        int n, m;   cin >> n >> m;
        vector< vector<string> > input(m, vector<string> (n));
        vector< vector<int> > output(m, vector<int> (n));

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                cin >> input[i][j];

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                replace(input, output, i, j);

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                cout << output[i][j];
                if(j + 1 < n)   cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
