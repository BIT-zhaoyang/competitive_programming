#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

/* I can't write a formal proof and I didn't found one either. I can write part of my proof and intuition.

    First, reference to this page:
    http://math.stackexchange.com/questions/125065/partitioning-a-natural-number-n-in-order-to-get-the-maximum-product-sequence-o
    we notice that, if we don't require the group to have different size, then the best set consists of 3 with or without 2.

    But since we need to have different size, after selecting 2 & 3, we need other values. It seems we should keep spliting a number as small as possible until we reach the least number larger than the used ones. So, we need to find a sequence of 2, 3, ... , m such what the sum is less than or equal to n.If there are remainders, in theory, (x+1)*y > x*(y+1), we should assign the reminder to the smaller numbers. But this will lead to repeat useage of numbers. For example, add 1 to 2 gives us 3, which is already used. So, we can only start from the largest, and gives only 1 to it since this will create a space by using least remainders. Then we iterate to the smaller numbers and assign 1 to them.
*/

int main(){ _
    int TC; cin >> TC;
    while(TC--){
        int n;  cin >> n;

        vector<int> vi;
        int sum = 0;
        for(int i = 2; sum + i <= n; ++i){
            vi.push_back(i);
            sum += i;
        }

        int rem = n - sum, sz = vi.size();
        for(int i = sz-1; rem > 0; --i){
            i = (i + sz) % sz;
            vi[i] += 1;
            rem -= 1;
        }

        for(int i = 0; i < sz; ++i){
            if(i)   cout << " ";
            cout << vi[i];
        }
        cout << endl;

        if(TC)  cout << endl;

    }
    return 0;
}
