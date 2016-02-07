#include <iostream>
using namespace std;

int main(){
    int s, q1, q2, q3;
    double result = 1080.0;
    while(cin >> s >> q1 >> q2 >> q3, !cin.eof()){
        if(!(s + q1 + q2 + q3)){
            return 0;
        }
        
        result = 1080.0;
        result += ((s + 40 - q1) % 40) * 9;
        result += ((q2 + 40 - q1) % 40) * 9;
        result += ((q2 + 40 - q3) % 40) * 9;
        cout << result << endl;
    }
    return 0;
}