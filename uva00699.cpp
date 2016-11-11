#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

map<int, int> acc;
void read_input(int place){
    int num;    cin >> num;
    if(num == -1)   return;

    acc[place] += num;
    read_input(place - 1);
    read_input(place + 1);
}

void print(int tc){
    cout << "Case " << tc << ":" << endl;
    int n = 0;
    for(auto it = acc.begin(); it != acc.end(); ++it){
        if(n++) cout << " ";
        cout << it->second;
    }
    cout << endl << endl;
}

int main(){ _
    int tc = 0;
    while (true) {
        acc.clear();
        read_input(0);
        if(acc.size())  print(++tc);
        else    break;
    }
    return 0;
}
