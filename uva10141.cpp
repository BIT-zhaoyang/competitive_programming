/*
    LESSON LEARNT FROM THIS EXERCISE:
    When you use getline(istream, variable) after a cin, you should
    use cin.ignore() to ignore the unexpected characteristis from last
    cin(Usually the '\n' character). However, if you are using getline()
    consequtivly, you don't have to use the cin.ignore() since this will
    incur a lose of characteristic.
 */

#include <iostream>
#include <string>

using namespace std;

int main(){
    string waste;
    int nEquip, nBinder;
    
    string name, maxName;
    double price, minPrice;
    int nAccomp, maxNAccomp;
    for(int n = 1; ; ++n){
        cin >> nEquip >> nBinder;
        if(nEquip == 0){
            break;
        }
        
        cin.ignore();
        for(int i = 0; i < nEquip; ++i){
            getline(cin, waste);
        }
        
        maxNAccomp = 0;
        for(int i = 0; i < nBinder; ++i){
            getline(cin, name);
            cin >> price;
            cin >> nAccomp;
            if(nAccomp > maxNAccomp){
                maxNAccomp = nAccomp;
                maxName = name;
                minPrice = price;
            } else if(nAccomp == maxNAccomp){
                if(price < minPrice){
                    maxName = name;
                    minPrice = price;
                }
            }

            cin.ignore();
            for(int j = 0; j < nAccomp; ++j){
                getline(cin, waste);
            }
        }
        if(n > 1){
            cout << endl;
        }
        cout << "RFP #" << n << endl;
        cout << maxName << endl;
    }
    
    return 0;
}
