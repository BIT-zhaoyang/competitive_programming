//
//  uva11507.cpp
//  
//
//  Created by 赵洋 on 15/9/17.
//
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    map<string, map<string, string> > table;
    table["+x"]["+y"] = "+y";
    table["+x"]["-y"] = "-y";
    table["+x"]["+z"] = "+z";
    table["+x"]["-z"] = "-z";

    table["-x"]["+y"] = "-y";
    table["-x"]["-y"] = "+y";
    table["-x"]["+z"] = "-z";
    table["-x"]["-z"] = "+z";
    
    table["+y"]["+y"] = "-x";
    table["+y"]["-y"] = "+x";
    table["+y"]["+z"] = "+y";
    table["+y"]["-z"] = "+y";
    
    table["-y"]["+y"] = "+x";
    table["-y"]["-y"] = "-x";
    table["-y"]["+z"] = "-y";
    table["-y"]["-z"] = "-y";
    
    table["+z"]["+y"] = "+z";
    table["+z"]["-y"] = "+z";
    table["+z"]["+z"] = "-x";
    table["+z"]["-z"] = "+x";
    
    table["-z"]["+y"] = "-z";
    table["-z"]["-y"] = "-z";
    table["-z"]["+z"] = "+x";
    table["-z"]["-z"] = "-x";
    
    string axis, direct;
    int n;
    while(cin >> n, n!= 0){
        axis = "+x";
        for(int i = 0; i < n - 1; ++i){
            cin >> direct;
            if(direct == "No"){
                continue;
            }
            axis = table[axis][direct];
        }
        cout << axis << endl;
    }
    
    
    return 0;
}
