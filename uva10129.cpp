#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

vector<int> tour, in, out;
vector< list<int> > AdjList;

void init(){
    AdjList.assign(26, list<int> (0));
    in.assign(26, 0);
    out.assign(26, 0);
    tour.clear();
}

int get_root(){
    int nStart = 0, nEnd = 0, middle = 0, others = 0, root = -1;
    for(int i = 0; i < 26; ++i){
        int diff = out[i] - in[i];
        switch (diff) {
            case 1: ++nStart;   break;
            case 0: ++middle;   break;
            case -1: ++nEnd;    break;
            default: ++others;  break;
        }
    }

    if(nStart > 1 || nEnd > 1 || others > 0)  return root;
    if(nStart == 1){
        for(int i = 0; i < 26; ++i)
            if(out[i] - in[i] == 1)
                return root = i;
    } else {
        for(int i = 0; i < 26; ++i)
            if(out[i])
                return root = i;
    }
}

void euler_tour(int u){
    if(u == -1) return;
    while(AdjList[u].size()){
        int v = *AdjList[u].begin();
        AdjList[u].pop_front();
        euler_tour(v);
    }
    tour.push_back(u);
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        init();
        int m;  cin >> m;
        for(int i = 0; i < m; ++i){
            string word;    cin >> word;
            int u = word[0] - 'a', v = word.back() - 'a';
            AdjList[u].push_back(v);
            out[u] += 1;
            in[v] += 1;
        }

        euler_tour(get_root());

        if(m + 1 != tour.size())    cout << "The door cannot be opened." << endl;
        else    cout << "Ordering is possible." << endl;
    }
    return 0;
}
