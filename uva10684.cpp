#include <iostream>
#include <vector>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;

int main(){ _
    int N;
    while(true){
        cin >> N;
        if(N == 0)  break;
        vector<int> vi(N, 0);
        vector<int> d(N, 0);
        for(int i = 0; i < N; ++i)
            cin >> vi[i];

        d[0] = vi[0];
        for(int i = 1; i < N; ++i)
            d[i] = max(vi[i], vi[i]+d[i-1]);

        int win = 0;
        for(int i = 0; i < N; ++i)
            win = max(win, d[i]);

        if(win) cout << "The maximum winning streak is " << win << "." << endl;
        else cout << "Losing streak." << endl;

    }


    // while(cin >> N, N != 0){
    //     int sum = 0, win = 0, num = 0;
    //     while(N--){
    //         cin >> num;
    //         sum += num;
    //         if(sum < 0){
    //             sum = 0;
    //         } else if(sum > win){
    //             win = sum;
    //         }
    //     }
    //
    //     if(win == 0){
    //         cout << "Losing streak." << endl;
    //     } else {
    //         cout << "The maximum winning streak is " << win << "." << endl;
    //     }
    // }
    return 0;
}
