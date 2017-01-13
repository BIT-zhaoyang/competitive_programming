#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

bool sanityCheck(string &str){
    char *cstr = new char[str.size() + 1];
    strcpy(cstr, str.c_str());

    // 1. check if there is any invalid characters
    if(strtok(cstr, "0123456789()+*") != NULL){
        delete []cstr;
        return false;
    }

    // 2. check balanced parenthesis
    // also ensure that no digits stands before '(' nor after ')'
    // count #op at the same time
    int nOpen = 0, nOp = 0;
    bool valid = true;
    for(int i = 0; i < str.size(); ++i){
        switch (str[i]) {
            case '(':
                ++nOpen;
                if(i - 1 >= 0 && isdigit(str[i - 1]))   return false;
                break;
            case ')':
                --nOpen;
                if(i + 1 < str.size() && isdigit(str[i + 1]))   return false;
                break;
            case '+':
            case '*':   ++nOp;   break;
        }
        if(nOpen < 0){
            delete []cstr;
            return false;
        }
    }

    // 3. check if #operation + 1 = #numbers
    int nNum = 0;
    char *pch = strtok(cstr, "()+*");
    while(pch != NULL){
        ++nNum;
        pch = strtok(NULL, "()+*");
    }
    delete []cstr;
    return nOp + 1 == nNum;
}

int processPlainExp(string str){
    // cout << "process " << str << endl;
    stack<int> nums;
    int num; char op;
    stringstream ss(str);
    while(ss >> num){
        nums.push(num);
        while(ss >> op){
            if(op == '+')   break;
            ss >> num;
            num *= nums.top();
            nums.pop();
            nums.push(num);
        }
    }
    int sum = 0;
    while(nums.size()){
        sum += nums.top();
        nums.pop();
    }
    return sum;
}

int processRawExp(string str){
    stack<char> raw;
    for(auto ch : str){
        if(ch == ')'){
            string plain;
            while(raw.top() != '('){
                plain = raw.top() + plain;
                raw.pop();
            }
            raw.pop();
            string val = to_string(processPlainExp(plain));
            for(auto ele : val) raw.push(ele);
        } else {
            raw.push(ch);
        }
    }
    string plain;
    while(raw.size()){
        plain = raw.top() + plain;
        raw.pop();
    }
    return processPlainExp(plain);
}

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        string str; cin >> str;

        if(!sanityCheck(str)){
            cout << "ERROR" << endl;
            continue;
        } else {
            cout << processRawExp(str) << endl;
        }
    }
    return 0;
}
