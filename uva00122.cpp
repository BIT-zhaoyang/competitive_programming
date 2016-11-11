#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

bool valid;
int nNodes;
map<int, int> nodes;

int left(int u) {return u << 1;}
int right(int u) {return (u << 1) + 1;}
int parent(int u) {return u >> 1;}
void init(){
    nodes.clear();
    valid = true;
    nNodes = 0;
}

bool process(int val, string &seq){
    int idx = 1;
    for(int i = 0; i < seq.size() - 1; ++i){    // seq contains the ending ")"
        if(seq[i] == 'L')   idx = left(idx);
        else idx = right(idx);
    }

    // cout << "val = " << val << "    idx = " << idx << endl;
    if(nodes.count(idx)) return false;
    else{
        nodes[idx] = val;
        return true;
    }
}

bool sanity_check(){
    if(!valid)  return valid;

    int idx, val, p;
    for(auto it = nodes.begin(); it != nodes.end(); ++it){
        idx = it->first;    val = it->second;
        p = parent(idx);
        if(p != 0 && nodes.count(p) == 0) return false;
    }

    return true;
}

void execute(){
    if(!sanity_check()){
        cout << "not complete" << endl;
        return;
    }

    for(auto it = nodes.begin(); it != nodes.end(); ++it){
        cout << it->second;
        --nNodes;
        if(nNodes)  cout << " ";
    }
    cout << endl;
}

int main(){ _
    char leftBracket, rightBracket, comma;
    int val;    string seq;
    string input;
    init();
    while(cin >> input){
        if(input == "()"){
            execute();
            init();
            continue;
        }

        stringstream ss(input);
        ss >> leftBracket >> val;
        if(ss.bad()){
            valid = false;
            continue;
        } else {
            ss >> comma >> seq;
            ++nNodes;
            valid = valid && process(val, seq);
            // if(!valid)  cout << "invalid since " << input << endl;
        }
    }
    return 0;
}
