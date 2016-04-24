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

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;

struct Quadtree{
    vector<bool> tree;
    string str;
    int size;

    Quadtree(string &rep){
        tree.assign(1024, false);
        str = rep;
        size = 0;
        int idx = -1;
        buildTree(idx, 0, 1024);
    }

    void buildTree(int &idx, int start, int end){
        ++idx;
        if(str[idx] == 'p'){
            int chunk = (end - start) / 4;
            for(int i = 0; i < 4; ++i){
                buildTree(idx, start + i*chunk, start + (i+1)*chunk);
            }
        } else if(str[idx] == 'f'){
            for(int i = start; i < end; ++i){
                tree[i] = true;
                size += 1;
            }
        } else if(str[idx] == 'e'){
            return;
        }
    }

    int getSize(){
        return size;
    }
};

int main(){ _
    int T;  cin >> T;
    while(T--){
        string a, b;
        cin >> a >> b;
        Quadtree one(a);    // cout << one.getSize() << endl;
        Quadtree two(b);    // cout << two.getSize() << endl;

        int count = 0;
        for(int i = 0; i < 1024; ++i){
            count += one.tree[i] | two.tree[i];
        }

        cout << "There are " << count << " black pixels." << endl;

    }
    return 0;
}
