#include <iostream>
#include <vector>
#include <string>
using namespace std;

class KMP{
public:
  void setPattern(string &P){
    this->P = P;
    m = P.size();
    kmpProcess();
  }

  void setText(string &T){
    n = T.size();
    this->T = T;
  }

  void kmpSearch(){
    cout << "The text is: " << T << endl;
    cout << "The pattern is: " << P << endl;

    int i = 0, j = 0;
    while(i < n){
      while(j >= 0 && T[i] != P[j]) j = table[j];
      ++i, ++j;
      if(j == m){
        cout << "Pattern was found at index: " << i - m << endl;
        j = table[j];
      }
    }
  }

private:
  void kmpProcess(){
    table.resize(m + 1, -1);

    int i = 0, j = -1;
    while(i < m){
      while(j >= 0 && P[j] != P[i]) j = table[j];
      ++i, ++j;
      table[i] = j;
    }

    cout << "reset table content:";
    for(int i = 0; i < table.size(); ++i){
      cout << " " << table[i];
    }
    cout << endl;
  }

private:
  int n, m;
  string P, T;
  vector<int> table;
};

int main() {
  string P, T;
  KMP kmpProcessor;
  while(getline(cin, T) && getline(cin, P)){
    kmpProcessor.setText(T);
    kmpProcessor.setPattern(P);
    kmpProcessor.kmpSearch();
    cout << endl;
  }
}
