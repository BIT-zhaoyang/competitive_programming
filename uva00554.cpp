#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define POS_INF 1 << 28
#define NEG_INF -1 << 28
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    const string alphabet = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    map<char, int> code;
    code[' '] = 0;
    for(char ch = 'A'; ch <= 'Z'; ++ch)
        code[ch] = int(ch - 64);

    vector<string> dict;
    string word, line, copy;
    while(cin >> word){
        if(word == "#") break;
        else    dict.push_back(word);
    }
    cin.ignore();
    getline(cin, line);

    int maxMatch = 0;
    string ans;
    for(int i = 0; i <= 26; ++i){
        copy = line;
        for(int j = 0; j < copy.size(); ++j){
            copy[j] = alphabet[(code[copy[j]] + i) % 27];
        }
        int nMatch = 0;
        for(auto ele : dict){
            size_t pos = 0;
            while(true){
                pos = copy.find(ele, pos);
                if(pos == string::npos) break;
                pos += ele.size();
                ++nMatch;
            }
        }
        if(nMatch > maxMatch){
            ans = copy;
            maxMatch = nMatch;
        }
    }

    int len = 0;
    stringstream ss(ans);
    while(ss >> word){
        if(len + word.size() + 1 <= 60){
            if(len != 0)    cout << " ";
            cout << word;
            len += word.size() + 1;
        } else{
            cout << endl;
            len = word.size();
            cout << word;
        }
    }
    cout << endl;
    return 0;
}
