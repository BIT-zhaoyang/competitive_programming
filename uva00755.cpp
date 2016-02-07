#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    map<char, char> dic;
    
    dic['A'] = '2';
    dic['B'] = '2';
    dic['C'] = '2';
    dic['2'] = '2';
    
    dic['D'] = '3';
    dic['E'] = '3';
    dic['F'] = '3';
    dic['3'] = '3';
    
    dic['G'] = '4';
    dic['H'] = '4';
    dic['I'] = '4';
    dic['4'] = '4';
    
    dic['J'] = '5';
    dic['K'] = '5';
    dic['L'] = '5';
    dic['5'] = '5';
    
    dic['M'] = '6';
    dic['N'] = '6';
    dic['O'] = '6';
    dic['6'] = '6';
    
    dic['P'] = '7';
    dic['R'] = '7';
    dic['S'] = '7';
    dic['7'] = '7';
    
    dic['T'] = '8';
    dic['U'] = '8';
    dic['V'] = '8';
    dic['8'] = '8';
    
    dic['W'] = '9';
    dic['X'] = '9';
    dic['Y'] = '9';
    dic['9'] = '9';
    
    dic['0'] = '0';
    dic['1'] = '1';
    
    int m;
    cin >> m;
    
    while(m--){
        int n;
        cin >> n;
        string str;
        vector<string> count;
        while(n--){
            string number;
            
            cin >> str;
            for(int i = 0; i < str.size(); ++i){
                if(str[i] == '-'){
                    continue;
                } else {
                    number += dic[str[i]];
                }
            }
            
            count.push_back(number);
        }
        
        sort(count.begin(), count.end());
        count.push_back("dummy");
        
        bool flag = false;
        int rep = 1;
        for(int i = 0; i < count.size()-1; ++i){
            if(count[i] == count[i+1]){
                rep += 1;
            } else if(rep != 1){
                cout << count[i][0] << count[i][1]
                << count[i][2] << "-"
                << count[i][3] << count[i][4]
                << count[i][5] << count[i][6] << " "
                << rep << endl;
                flag = true;
                rep = 1;
            }
        }
        if(!flag){
            cout << "No duplicates." << endl;
        }
        if(m != 0)
            cout << endl;
    }
    return 0;
}