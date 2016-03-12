#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

struct record{
    string name;
    int low, high;

    record(string _name, int _low, int _high){
        name = _name;
        low = _low;
        high = _high;
    }
};


int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int N;
        cin >> N;
        vector<record> vec;
        string name;
        int low, high;
        for(int i = 0; i < N; ++i){
            cin >> name >> low >> high;
            vec.push_back(record(name, low, high));
        }

        int nQuery;
        cin >> nQuery;
        int price;
        while(nQuery--){
            cin >> price;
            int counter = 0, maker = -1;
            for(int i = 0; i < N; ++i){
                if(vec[i].low <= price && vec[i].high >= price){
                    ++counter;
                    maker = i;
                }
                if(counter > 1) break;
            }

            if(counter > 1 || counter == 0) cout << "UNDETERMINED" << endl;
            else cout << vec[maker].name << endl;
        }
        cout << endl;
    }
    return 0;
}
