//
//  uva00732.cpp
//
//
//  Created by 赵洋 on 15/10/6.
//
//
// Although I think my method will be pretty concise and fast, but it actually get a TLE...


#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <string>

using namespace std;

void output_oper(vector<int> &seq){
    // Not every generated potential seq will be really produced by stack
    // operation. So we keep them in a record "string oper". If it can be
    // generated, then we will output it.
    
    int n = seq.size();
    int count = 1;
    stack<int> si;
    string oper;
    for(int i = 0; i < n; ++i){
        while(count <= seq[i]){
            si.push(count++);
            oper += "i ";
        }
        
        if(si.top() != seq[i]){
            return;
        }
        
        si.pop();
        oper += "o ";
    }
    cout << oper << endl;
}


void gen_seq(map<char, vector<int> >& dict, vector<int>& seq, int i, string &output, vector<bool>& flag){
    char ch = output[i];
    for(int j = 0; j < dict[ch].size(); ++j){
        int idx = dict[ch][j];
        if(flag[idx]){
            continue;
        }
        
        seq[i] = idx;
        flag[idx] = true;
        if(i == output.length() - 1){
            output_oper(seq);
        } else {
            gen_seq(dict, seq, i+1, output, flag);
        }
        flag[idx] = false;
    }
}

int main(){
    string input, output;
    while(cin >> input, !cin.eof()){
        cin >> output;
        if(input.length() != output.length()){
            cout << "[\n]" << endl;
            continue;
        }
        
        map<char, vector<int> > dict;
        for(int i = 0; i < input.length(); ++i){
            char ch = input[i];
            dict[ch].push_back(i+1);
        }
        
        // check if input & output contains the same letters
        map<char, vector<int> >::iterator it;
        bool success = true;
        for(int i = 0; i < output.length(); ++i){
            it = dict.find(output[i]);
            if(it == dict.end()){
                success = false;
                break;
            }
        }
        if(!success){
            cout << "[\n]" << endl;
            continue;
        }
        
        // generate possible sequences and output it if it is excuteable
        vector<int> seq(input.length(), 0);
        vector<bool> flag(input.length()+1, false);
        
        cout << "[" << endl;
        gen_seq(dict, seq, 0, output, flag);
        cout << "]" << endl;
    }
    
    return 0;
}

