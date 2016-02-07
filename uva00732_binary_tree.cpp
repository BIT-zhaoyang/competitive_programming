//
//  uva00732_binary_tree.cpp
//  
//
//  Created by 赵洋 on 15/10/6.
//
//
// almost copied from https://saicheems.wordpress.com/2013/08/26/uva-732-anagrams-by-stack/
// but now I understand this program


#include <iostream>
#include <string>

using namespace std;

string in, out;
void process(string _in, string _out, string stack, string path, int n){
    if(n == in.length() * 2) {
        if( _out == out ){
            cout << path << endl;
            return;
        }
    }
    
    // the push and pop operation mimics a stack.
    // it uses a string + operations to mimic a stack rather than using
    // a real stack.
    // this mimic will save time.
    
    // lessons learned:
    // the critial difference between different data structure is not
    // fully relied on what is the underlying phsical organization but
    // more on operation used on this structure.
    
    // push
    if(_in.length() > 0)
        process(_in.substr(1, _in.length() - 1),\
                _out,\
                stack + _in[0],\
                path + "i ",\
                n+1);
    
    // pop
    if(stack.length() > 0 && stack[stack.length() - 1] == out[_out.length()] )
    process(_in,\
            _out + stack[stack.length() - 1],\
            stack.substr(0, stack.length() - 1),\
            path + "o ",\
            n+1);
}




int main(){
    while(cin >> in >> out){
        
        cout << "[" << endl;
        process(in, "", "", "", 0);
        cout << "]" << endl;
    }
    return 0;
}