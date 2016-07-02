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
#include <queue>
#include <stack>
#include <tuple>

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

/* A useful thing learned is how to find the relations of these chars.
According to: http://www.algorithmist.com/index.php/UVa_200
To create the initial edges, compare two consecutive strings and find the first position at which the character (say u) in the first string is different from the character in the second string (say v). Create an edge (u,v) in the graph.
*/

vector<bool> nodes(26, false);
vector< vector<int> > edges(26, vector<int> (0));
vector<int> ans;

void tps(int p){
    nodes[p] = false;

    int q;
    for(int i = 0; i < edges[p].size(); ++i){
        q = edges[p][i];
        if(nodes[q])    tps(q);
    }
    ans.push_back(p);
}

int main(){ _
    string str1, str2;
    while(cin >> str1){
        nodes.assign(26, false);
        edges.assign(26, vector<int> (0));
        ans.clear();

        while(cin >> str2){
            if(str2 == "#") break;
            int ch1, ch2;
            for(int i = 0; i < min(str1.size(), str2.size()); ++i){
                ch1 = str1[i] - 'A'; ch2 = str2[i] - 'A';
                nodes[ch1] = true;  nodes[ch2] = true;
                if(ch1 != ch2){
                    edges[ch1].push_back(ch2);
                    break;
                }
            }
            str1 = str2;
        }

        for(int i = 0; i < 26; ++i){
            if(nodes[i])    tps(i);
        }

        for(int i = ans.size() - 1; i >= 0; --i){
            cout << char('A' + ans[i]);
        }   cout << endl;
    }
    return 0;
}
