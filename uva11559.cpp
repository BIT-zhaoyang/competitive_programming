//
//  uva11559.cpp
//  
//
//  Created by 赵洋 on 15/9/16.
//
//
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void check(int N, int B, int H, int W, vector< pair<int, int> >& hotel_price, int* capacity){
    
    for(int i = 0; i < H; ++i){
        if(hotel_price[i].first * N > B){
            cout << "stay home" << endl;
            return;
        }
        for(int j = 0; j < W; ++j){
            int idx = hotel_price[i].second;
            if(capacity[idx * W + j] > N){
                cout << N * hotel_price[i].first << endl;
                return;
            }
        }
    }
}


int main(){
    int N, B, H, W; // N: number of participants
                    // B: number of budget
                    // H: number of hotels
                    // W: number of weekends
    vector< pair<int, int> > hotel_price;   // pair<int, int>: price, index
    int price;

    int *capacity = NULL;
    int cap;
    
    while(cin >> N >> B >> H >> W, !cin.eof()){
        hotel_price.clear();
        capacity = new int[H*W];
        
        for(int i = 0; i < H; ++i){
            cin >> price;
            hotel_price.push_back(make_pair(price, i));
            
            for(int j = 0; j < W; ++j){
                cin >> cap;
                capacity[i*W + j] = cap;
            }
        }
        
        sort(hotel_price.begin(), hotel_price.end());
        
//        for(int i = 0; i < H; ++i){
//            cout << hotel_price[i].first <<  " " << hotel_price[i].second << endl;
//        }
        
//        for(int i = 0; i < H; ++i){
//            for(int j = 0; j < W; ++j){
//                cout << capacity[i*W + j] << " ";
//            }
//            cout << endl;
//        }
        
        check(N, B, H, W, hotel_price, capacity);
        delete []capacity;
        capacity = NULL;
    }
    
    return 0;
}