#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <climits>
#include <cmath>
#include <set>
#include <bitset>
#include <sstream>
#include <iomanip>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

/*
    The greedy rule is: always assign a member to a table with maximum !!current!! capacity. Which team member to assign is not critical.

    Proof:
        We will the answer in this form, each column represent a table, then the answer looks like:
            t1  t2  t3  t4  t5
            1   1   1        1
            2   2        2
            3       3
        something like this.

        Suppose there are 2 tables t1 & t2. Let's assume capacity(t2) < capacity(t1) always hold. (If cap(t2) becomes larger than cap(t1), then we can just exchange the roles of t1 & t2, so we can only consider the case cap(t1) > cap(t2)).
        When we are assigning a member, if we assign it to t2 rather than t1, and this assignment leads to a solution, we can just exchange the people on the two tables which will leads to another solution.
*/


bool mycomp(pair<int, int>& a, pair<int, int>& b){
    return a.first > b.first;
}

int main(){ _
    int M, N;
    while(cin >> M >> N){
        if(M + N == 0)  break;

        vector<int> team(M, 0);
        vector< pair<int, int> > table(N);
        for(int i = 0; i < M; ++i)  cin >> team[i];
        int temp;
        for(int i = 0; i < N; ++i){
            cin >> temp;
            table[i].first = temp;
            table[i].second = i+1;
        }

        bool possible = true;
        vector< vector<int> > ans(M);
        for(int i = 0; i < M; ++i){
            int num = team[i];

            sort(table.begin(), table.end(), mycomp);

            for(int j = 0; j < table.size() && num > 0; ++j){
                if(table[j].first > 0){
                    ans[i].push_back(table[j].second);
                    table[j].first -= 1;
                    --num;
                }
            }

            if(num > 0){
                possible = false;
                break;
            }
        }

        if(possible){
            cout << 1 << endl;
            for(int i = 0; i < M; ++i){
                for(int j = 0; j < ans[i].size(); ++j){
                    if(j)   cout << " ";
                    cout << ans[i][j];
                }
                cout << endl;
            }
        }else{
            cout << 0 << endl;
        }
    }
    return 0;
}
