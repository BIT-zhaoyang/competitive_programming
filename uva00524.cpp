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
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int n;
set<int> primes;

void recurse(vector<int> &order, vector<bool> &taken){
    int candidate;

    if(order.size() == n){
        candidate = order.front() + order.back();
        if(!primes.count(candidate))    return;

        for(int i = 0; i < n-1; ++i)    cout << order[i] << " ";
        cout << order[n-1] << endl;
        return;
    }

    for(int i = 2; i <= n; ++i){
        if(taken[i])    continue;

        candidate = order.back() + i;
        if(!primes.count(candidate))    continue;

        order.push_back(i); taken[i] = true;
        recurse(order, taken);
        order.pop_back();   taken[i] = false;
    }
}

int main(){ _
    for(int i = 0; i < 11; ++i) primes.insert(prime[i]);

    int count = 0;
    while(cin >> n){
        vector<int> vi(n+1, 0);
        vector<bool> taken(n+1, false);
        for(int i = 1; i <= n; ++i)  vi[i] = i;

        if(count)   cout << endl;
        cout << "Case " << ++count << ":" << endl;

        vector<int> order(1, 1);
        taken[1] = true;
        recurse(order, taken);
    }
    return 0;
}
