//
//  uva00573.cpp
//  
//
//  Created by 赵洋 on 15/9/16.
//
//

#include <iostream>
using namespace std;

int main(){
    double height, up, down, fatigue;
    double initial_height, distance_climbed, height_after_climb, height_after_slide;
    double reduce;
    while(cin >> height >> up >> down >> fatigue, height != 0){
        initial_height = 0;
        distance_climbed = up;
        reduce = up * fatigue / 100;
        for(int i = 1; ; ++i){
            height_after_climb = initial_height + distance_climbed;
            if(height_after_climb > height){
                cout << "success on day " << i << endl;
                break;
            }
            
            height_after_slide = height_after_climb - down;
            if(height_after_slide < 0){
                cout << "failure on day " << i << endl;
                break;
            }
            
            distance_climbed -= reduce;
            if(distance_climbed < 0){
                distance_climbed = 0.0;
            }
            
            initial_height = height_after_slide;
        }
        
    }
    
    return 0;
}
