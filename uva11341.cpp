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
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(2);
using namespace std;

/*
    Lesson Learned:
    At first, I thought this was a 分组背包问题. However, the limitation that each group(namely each course) should have one candidate be selected. Thus, this differs from the 分组背包问题.

    Also, the requirement, each selected candidate should be equal or larger than 5 otherwise there is no solution, makes the problem more complicated.

    Finally, I successfully solved this problem by setting each candidate which is less than 5 to a big negative value. This conversion implicitly forces the result to satisfy the requirement. Otherwise, the final result will be a large negative value which means there is no solution. Similar to uva00836. In other words, use negative value to represent illegal states.
*/


void fillTable(vector< vector<int> > &table, vector<int> &course, int id){    //id: course idx
    int M = course.size()-1;
    bool fail = true;
    for(int v = M; v > 0; --v){
        for(int i = 1; i <= v; ++i){
            table[id][v] = max(table[id][v], table[id-1][v-i] + course[i]);
        }
    }
}

void printTable(vector<int> &table){
    for(int i = 0; i < table.size(); ++i)   cout << table[i] << " ";
    cout << endl;
}


int main(){ _
    int TC; cin >> TC;
    while(TC--){
        int N, M;   cin >> N >> M;
        vector< vector<int> > table(N+1, vector<int> (M+1, -1e5));
        table[0].assign(M+1, 0);
        vector<int> course(M+1, 0);
        for(int i = 0; i < N; ++i){

            for(int j = 1; j <= M; ++j){
                cin >> course[j];
                if(course[j] < 5)   course[j] = -1e5;
            }

            fillTable(table, course, i+1);
            // printTable(table[i+1]);
        }
        double average = double(table[N][M]) / N + 0.0005;
        if(average < 5.0)   cout << "Peter, you shouldn't have played billiard that much." << endl;
        else cout << "Maximal possible average mark - " << fixed << average << "." << endl;
    }
    // double a = 9.6256;
    // cout << fixed << a << endl;
    return 0;
}
