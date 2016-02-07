//
//  uva00111.cpp
//  
//
//  Created by 赵洋 on 15/11/8.
//
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int LCS(vector<int> &X, vector<int> &Y){
    int n = X.size();
    
//    for(int i = 0; i < n; ++i){
//        cout << X[i] << " ";
//    }
//    cout << endl;
//    
//    for(int i = 0; i < n; ++i){
//        cout << Y[i] << " ";
//    }
//    cout << endl;
    

    vector< vector<int> > table(2, vector<int> (n+1, 0));
    int previous = 0, current = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(X[i-1] == Y[j-1]){
                table[current][j] = table[previous][j-1] + 1;
            } else {
                table[current][j] = max(table[previous][j], table[current][j-1]);
            }
//            cout << table[current][j] << " ";
        }
//        cout << endl;
        int temp = current;
        current = previous;
        previous = temp;
    }
    
    return table[previous][n];
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    
    string input;
    vector<int> record(n, 0);
    getline(cin, input);
    
    stringstream ss;
    ss << input;
    for(int i = 1; i <= n; ++i){
        int idx;
        ss >> idx;
        record[idx-1] = i;
    }
    
    vector<int> answer(n, 0);
    while(getline(cin, input)){
        ss.str("");
        ss.clear();
        
        ss << input;
        for(int i = 1; i <= n; ++i){
            int idx;
            ss >> idx;
            answer[idx-1] = i;
        }
    
        cout << LCS(record, answer) << endl;
    }
    
    return 0;
    
}
//
//#include<cstdio>
//#define MAX(a,b) (a<b?b:a)
//int events,i,j,idx;
//int oford[20];
//int stord[20];
//int lcs[21][21];
//int main(void){
//    scanf("%d",&events);
//    for(i = 1; i <= events; i++){
//        scanf("%d",&idx);
//        oford[idx-1] = i;
//    }
//    while(scanf("%d",&idx)!=EOF){
//        stord[idx-1] = 1;
//        for(i = 2; i <= events; i++){
//            scanf("%d",&idx);
//            stord[idx-1] = i;
//        }
//        for(i = 0; i <= events; i++) lcs[i][0] = lcs[0][i] = 0;
//        for(i = 1; i <= events; i++)
//            for(j = 1; j <= events; j++)
//                if(oford[i-1] == stord[j-1]) lcs[i][j] = lcs[i-1][j-1]+1;
//                else lcs[i][j] = MAX(lcs[i-1][j],lcs[i][j-1]);
//        printf("%d\n",lcs[events][events]);
//    }
//    return 0;
//}
