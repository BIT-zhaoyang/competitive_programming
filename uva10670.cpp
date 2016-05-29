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

/* This may be the only formal proof of uva10670 on the whole Internet world!
   Get inspired by this article: http://abitofcs.blogspot.fi/2014/09/a-bit-of-greedy-uva-10670-work-reduction.html

   Now let's prove it formally.
   First, let's discuss the case N-M = 2^k.
   In this case, the obvious choice is that as long as B/(N/2) < A, we choose B. Namely, choose the one charge less for one unit work. This is intuitive and obvious.

   Then it's the more general second case:
    N = M*2^k + j   or N = (M+a)*2^b    (a < M should hold, or we can add 1 to b and reduce a by M)
   We notice that 2^(k+1)*M > N > 2^k*M and   2^(b+1)*M > N > 2^b*M   thus we have k = b;
   Thus, in first case, we have cost jA + kB, in second case we have aA + bB. Let's compare a & j. We have j = N - M*2^k = N - M*2^b = a*2^b. Thus, a < j. Thus, we should divide first, then minus second.

   Another question is, can we do operation like this: / - / - ?
   Let's see, if we have a sequence like this:
        A / B - C / D - E   which means we begin at A, then we do some half operation to get B, then we do minus 1 to get C, etc..
    we have, the value of A is 2^n(2^k(m+j) + l), B: 2^k(m+j)+l, C: 2^k(m+j), D: m+j, E; m
    Notice that, value A should be less that double value C.
    Solve this equation 2^n(2^k(m+j) + l) < 2^(k+1)(m+j)+l we get that n < 1 which is n = 0. Which means we can only start at B, which is the second case N = M*2^k + j. However, in this case, we should do half operation first.
    Thus, the sequence / - / - is not optimal.


    So, what's the lesson learned from this problem? Maybe it is: start from a very simple base case.(In this example, it's use only / - or - / not a mixture of / - / - etc) Then do the generalization. When do the generalization, find some contradiction.
*/


void parse_agency(string &line, map<string, pair<int, int> >& agency){
    string name;
    int i = 0;
    for(; i < line.size(); ++i){
        if(line[i] != ':')  name.push_back(line[i]);
        else{
            ++i;
            break;
        }
    }

    int unit = 0, half = 0;
    for(; i < line.size(); ++i){
        if(line[i] == ','){
            ++i;
            break;
        } else{
            unit = unit * 10 + (line[i] - '0');
        }
    }

    for(; i < line.size(); ++i){
        half = half * 10 + (line[i] - '0');
    }

    agency[name] = make_pair(unit, half);
}

int compute(int N, int M,
            map<string, pair<int, int> >::iterator &it){
    int half = (it->second).second;
    int unit = (it->second).first;

    if(N/2 < M) return (N-M)*unit;
    if(double(half)/(N/2) > unit) return (N-M)*unit;
    return compute(N/2, M, it) + half;
}

int main(){ _
    int TC; cin >> TC;
    int count = 0;
    while(TC--){
        cout << "Case " << ++count << endl;
        int N, M, L;    cin >> N >> M >> L;
        string line;
        map<string, pair<int, int> > agency;
        for(int i = 0; i < L; ++i){
            cin >> line;
            parse_agency(line, agency);
        }

        vector< pair<int, string> > ans;
        for(map<string, pair<int, int> >::iterator it = agency.begin(); it != agency.end(); ++it){
            int cost = compute(N, M, it);
            ans.push_back(make_pair(cost, it->first));
        }

        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); ++i)
            cout << ans[i].second << " " << ans[i].first << endl;
    }
    return 0;
}
