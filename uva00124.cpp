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

/* I didn't check Knuth's algorithm nor some other algorithm published in scientific papers because they are published so early so that their pseudocode, notations are really hard to read! In stead, I read some others' program on the Internet and come up/duplicate the following algorithm.

This algorithm deosn't feels like topological sort at all! It's just trying all permutations but cut the searching spaces early when it founds invalid candidates.
*/

vector<int> nodes;
vector<bool> visited(26, false);
vector< vector<int> > edge(26, vector<int> (0));
set< vector<int> > ans;

bool valid(){
    int q;
    for(int i = 0; i < nodes.size(); ++i){
        q = nodes[i];
        if(!visited[q]){
            for(int j = 0; j < edge[q].size(); ++j){
                if(visited[ edge[q][j] ])   return false;
            }
        }
    }

    return true;
}


void tps(vector<int>& cand){
    if(cand.size() == nodes.size()){
        for(int i = 0; i < cand.size(); ++i)    cout << char(cand[i] + 'a');
        cout << endl;
        return;
    }

    int p;
    for(int i = 0; i < nodes.size(); ++i){
        p = nodes[i];
        if(!visited[p]){
            visited[p] = true;
            if(valid()){
                cand.push_back(p);
                tps(cand);
                cand.pop_back();
            }
            visited[p] = false;
        }
    }
}

int main(){ _
    string str;
    int count = 0;
    while(getline(cin, str)){
        // read input
        nodes.clear();
        edge.assign(26, vector<int> (0));
        stringstream ss(str);
        char ch, from, to;
        while(ss >> ch){
            nodes.push_back(ch - 'a');
        }
        sort(nodes.begin(), nodes.end());

        getline(cin, str);
        ss.clear();
        ss.str("");
        ss << str;
        while(ss >> from >> to){
            edge[from - 'a'].push_back(to - 'a');
        }

        // tps
        vector<int> cand;
        if(count++)   cout << endl;
        tps(cand);
    }
    return 0;
}
