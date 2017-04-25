#include <bits/stdc++.h>
using namespace std;

char table[26] = {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5',
'6', '6', '6', '7', '7', '7', '7', '8', '8', '8', '9', '9', '9', '9'};
vector<string> nums, codes;
set<string> exts;

string str2num(string &first, string &last){
  string result;
  result.push_back(table[tolower(first[0]) - 'a']);
  for(int i = 0; i < last.size(); ++i){
    result.push_back(table[tolower(last[i]) - 'a']);
  }
  return result;
}

void search(string &dial){
  if(exts.count(dial)){
    cout << dial << endl;
    return;
  }

  vector<string> result;
  for(int i = 0; i < nums.size(); ++i){
    int n = dial.size();
    if(nums[i].substr(0, n) == dial){
        result.push_back(codes[i]);
    }
  }

  if(result.empty()){
    cout << "0" << endl;
  } else {
    for(int i = 0; i < result.size(); ++i){
      cout << result[i];
      if(i + 1 != result.size())  cout << " ";
      else  cout << endl;
    }
  }
}

int main() {
  string first, last, ext, dial;
  while(cin >> first){
    if(isdigit(first[0])){
      dial = first;
      search(dial);
    } else {
      cin >> last >> ext;
      string num = str2num(first, last);
      nums.push_back(num);
      codes.push_back(ext);
      exts.insert(ext);
    }
  }

  return 0;
}
