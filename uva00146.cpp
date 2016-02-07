//
//  uva00146.cpp
//  
//
//  Created by 赵洋 on 15/9/23.
//
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//int main(){
//    string str, next;
//    vector<char> vc;
//    bool flag;
//    while(cin >> str, str != "#"){
//        // reset to be clear from last loop
//        vc.clear();
//        next.clear();
//        flag = false;
//        
//        // Find from the end until we find the position which is
//        // bigger than its previous one
//        // Put all the scanned character into the vector
//        int i = str.length() - 1;
//        for(; i >= 1; --i){
//            vc.push_back(str[i]);
//            if(str[i] > str[i-1]){
//                flag = true;
//                break;
//            }
//        }
//        
////        cout << "vc: ";
////        for(int i = 0; i < vc.size(); ++i){
////            cout << vc[i];
////        }
////        cout << endl;
//        
//        // If we do find such a position
//        if(flag){
//            i -= 1; // Now i points to the smaller position, the sentinel
//            next.append(str, 0, i); // copy first part into next
////            cout << "next: " << next << endl;
//            sort(vc.begin(), vc.end()); // sort all the stored chars
//            for(int j = 0; j < vc.size(); ++j){
//                if(vc[j] > str[i]){     // find the smallest bigger one than our sentinel
//                    next.append(1, vc[j]);    // append it to next
//                    vc.erase(vc.begin() + j);   // erase it from vc since we have already used it
//                    vc.push_back(str[i]);   // put our sentinel into vc
//                    break;
//                }
//            }
//            sort(vc.begin(), vc.end()); // sort again
//            for(int j = 0; j < vc.size(); ++j){
//                next.append(1, vc[j]); // now we copy the biggest in the vc to next
//            }
//            
//            cout << next << endl;
//        } else {
//            cout << "No Successor" << endl;
//        }
//    }
//    return 0;
//}

int main(){
    string str;
    while(cin >> str, str != "#"){
        if(next_permutation(str.begin(), str.end())){
            cout << str << endl;
        } else {
            cout << "No Successor" << endl;
        }
    }
    retun 0;
}