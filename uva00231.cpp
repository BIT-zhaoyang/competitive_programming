#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

int binarySearch(vector<int> &records, int val){
    int lo = 0, hi = records.size()-1, mid;
    while(lo <= hi){
        mid = (lo+hi)/2;
        if(records[mid] >= val) lo = mid+1;
        else    hi = mid-1;
    }
    return lo;
}

int LDS(const vector<int> &vi){
    vector<int> records(1, INT_MAX);
    vector<int>::iterator low;
    for(int i = 0; i < vi.size(); ++i){
        // for(int j = 0; j < records.size(); ++j){
        //     cout << records[j] << " ";
        // }cout << endl;

        int idx = binarySearch(records, vi[i]);
        if(idx == records.size())   records.push_back(vi[i]);
        else    records[idx] = vi[i];
    }
    return records.size() - 1;
}

int main(){ _
    int val, count = 0;
    vector<int> vi;
    while(cin >> val){
        if(val == -1)   break;
        else    vi.push_back(val);

        if(count)   cout << endl;

        while(cin >> val)
            if(val != -1)   vi.push_back(val);
            else    break;

        cout << "Test #" << ++count << ":" << endl;
        cout << "  maximum possible interceptions: " << LDS(vi) << endl;
        vi.clear();
    }
    return 0;
}
