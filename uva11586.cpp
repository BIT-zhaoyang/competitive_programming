//
//  uva11586.cpp
//
//
//  Created by 赵洋 on 15/9/17.
//
//

//14:17
#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    char ch1, ch2, sep;
    int n, track[2], count;
    scanf("%d\n", &n);
    while(n--){
        track[0] = 0;
        track[1] = 0;
        count = 0;
        
        while(true){
            //            scanf("%c%c%c", &ch1, &ch2, &sep);
            scanf("%c", &ch1);
            scanf("%c", &ch2);
            scanf("%c", &sep);
//            cout << "ch1 = " << ch1 << endl;
//            cout << "ch2 = " << ch2 << endl;
//            cout << "track[0] = " << track[0] << endl;
//            cout << "track[1] = " << track[1] << endl;
            count += 1;
            if(ch1 == ch2){
                if(ch1 == 'M'){
                    track[0] += 2;
                } else {
                    track[1] += 2;
                }
            }
            if(sep == '\n'){
                break;
            }
        }
        
        if(track[0] == track[1] && count > 1){
            cout << "LOOP" << endl;
        } else {
            cout << "NO LOOP" << endl;
        }
    }
    
    return 0;
}