#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void rotate(string &s1, string &s2, int n){
    for(int i = 0; i < n; ++i){
        for(int j = n-1; j >= 0; --j){
            s2 += s1[j*n + i];
        }
    }
}

void get_string(char *table, string &s, int idx, int N, int n){
    s.clear();
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            s += table[idx + i*N + j];
        }
    }
}

int main(){
    int N, n;
    while(cin >> N >> n, N && n){
        char *table = new char[N * N];
        char ch;
        cin.ignore();
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                scanf("%c", &ch);
                table[i*N + j] = ch;
            }
            scanf("%c", &ch);
        }
        
        char *net = new char[n*n];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                scanf("%c", &ch);
                net[i*n + j] = ch;
            }
            scanf("%c", &ch);
        }
        
        string s, s1, s2, s3, s4;
        int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                s1 += net[i*n + j];
            }
        }
        
        rotate(s1, s2, n);
        rotate(s2, s3, n);
        rotate(s3, s4, n);
        
        for(int i = 0; i < N - n + 1; ++i){
            for(int j = 0; j < N - n + 1; ++j){
                get_string(table, s, i*N+j, N, n);
                if(s == s1) c1 += 1;
                if(s == s2) c2 += 1;
                if(s == s3) c3 += 1;
                if(s == s4) c4 += 1;
            }
        }
        
        cout << c1 << " " << c2 << " " << c3 << " " << c4 << endl;
    }
    
    return 0;
}