#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;
vector<int> A, B, C;
int n, m, counter;

void printOne(char ch, vector<int>& A){
    cout << ch << "=>";
    if(A.size())    cout << "  ";
    for(int i = 0; i < A.size(); ++i){
        cout << " " << A[i];
    }
    cout << endl;
}

void printAll(){
    printOne('A', A);
    printOne('B', B);
    printOne('C', C);
    cout << endl;
}

void moveTower(int n, vector<int>& start, vector<int>& end, vector<int>& tmp){
    if(counter == m)  return;

    if(n == 1){
        int d = start.back();
        start.pop_back();
        end.push_back(d);
        ++counter;
        printAll();
    } else{
        moveTower(n-1, start, tmp, end);
        if(counter == m)  return;
        int d = start.back();
        start.pop_back();
        end.push_back(d);
        ++counter;
        printAll();
        moveTower(n-1, tmp, end, start);
    }
}

int main(){ _
    int T = 0;
    while(cin >> n >> m, n!= 0){
        A.clear(); B.clear(); C.clear(); counter = 0;
        A.assign(n, 0);
        for(int i = 0; i < n; ++i){
            A[i] = n-i;
        }
        cout << "Problem #" << ++T << endl << endl;
        printAll();

        moveTower(n, A, C, B);

    }
    return 0;
}
