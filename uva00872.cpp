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

vector<int> nodes;
vector< vector<int> > edges;
vector<bool> visited;
bool flag;

bool valid(){
    int p, q;
    for(int i = 0; i < nodes.size(); ++i){
        p = nodes[i];
        if(!visited[p]){
            for(int j = 0; j < edges[p].size(); ++j){
                q = edges[p][j];
                if(visited[q])  return false;
            }
        }
    }
    return true;
}

void tps(vector<int> &ans){
    if(ans.size() == nodes.size()){
        flag = true;
        for(int i = 0; i < nodes.size(); ++i){
            if(i)   cout << " ";
            cout << char(ans[i] + 'A');
        }
        cout << endl;
        return;
    }

    int p, q;
    for(int i = 0; i < nodes.size(); ++i){
        p = nodes[i];
        if(!visited[p]){
            visited[p] = true;
            if(valid()){
                ans.push_back(p);
                tps(ans);
                ans.pop_back();
            }
            visited[p] = false;
        }
    }
}

int main(){ _
    int TC; cin >> TC;
    cin.ignore();
    stringstream ss;
    string str;
    vector<int> ans;
    while(TC--){
        getline(cin, str);  //read the blank line

        ans.clear();
        nodes.clear();
        visited.assign(26, false);
        edges.assign(26, vector<int> (0));

        getline(cin, str);
        ss.clear();
        ss.str("");
        ss << str;

        char ch;    int letter;
        while(ss >> ch){
            letter = ch - 'A';
            nodes.push_back(letter);
        }
        sort(nodes.begin(), nodes.end());

        getline(cin, str);
        ss.clear();
        ss.str("");
        ss << str;

        char ch1, op, ch2;  int letter1, letter2;
        while(ss >> ch1 >> op >> ch2){
            letter1 = ch1 - 'A';    letter2 = ch2 - 'A';
            edges[letter1].push_back(letter2);
        }

        flag = false;
        tps(ans);
        if(!flag)   cout << "NO" << endl;
        if(TC)  cout << endl;
    }
    return 0;
}
