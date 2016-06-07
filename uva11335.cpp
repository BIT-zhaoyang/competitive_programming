#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <climits>
#include <cmath>
#include <set>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <queue>
#include <stack>

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

/* First, notice that, in order to catch the theif, the cop must reach the same speed as the theif. At this time, the cop and the theif are moving parallelly. Then, the cop continue to increase his speed so that the distance between them decreases.

Next, we notice that, the speed can increase only 1 by every move. Thus, the first move after they have the equal speed, their distance decreases by 1. After the second move, their distance decreases by 2.

Suppose they have a distance of 5. Then the optimal way is decrease this distance by 1 2 2. If the distance is 7, the optimal way to decrease the distance could be either 1 2 2 2 or 1 1 2 3. If D = 8, the optimal way is 1 2 2 3. How to decide the optimal way? The answer is simple after some consideration. Find the largest N such that sum(1, ... , N) <= D < sum(1, ..., N+1). Then, just add D - sum(1, ... , N) to the sequence 1, ... , N. Note that, D is not the initial distance between the cop and the theif. It's the distance between them when they have the same speed.

But what if the theif have different speed on x & y axis? Let's say dy > dx. Then, the optimal way depends on dy. Why is this case? Suppose dy and dx are independent. Which means we can image there are two theifs on x & y axis and two cops chase them seperately. One theif has speed dx and the other one has speed dy, dy > dx. Then, the time used to catch up the x theif is certainly shorter than catching up the y theif. Because on the y axis, the cop uses longer time to reach the speed dy and uses longer time to decrease the distance when they have the same speed. Thus, when the cop catches the y theif, the other cop should already catch the x theif. If the x cop want to catch the theif at the same time with the y cop, he can just do some other stuff to reduce his efficiency. Thus, in this problem, when dy != dx, the answer depends on the larger one.

So, how did I discover this solution? Well, start from a simpler problem first. Namely, consider only one axis. The one axis problem can be easily generated to two dimensions with the same speed dy == dx. Then we try to analyze the situation when dy != dx. After the abstraction we found in the simpler problem. It's not hard to come up with the insight to solve the more complext problem. One good thing to remember is that, forget about non-relevant details. In this example, knowing that there is always a way to catch up the theif on the slower axis is enough. Don't try to find how we can realize that. Just knowing it's possible and ignore that is enough for us to solve the problem.
*/

int main(){ _
    int a, u, v;
    while(cin >> a >> u >> v){
        // a special case
        if(a == 0)  cout << 0 << endl;
        else {
            // solve x-axis
            int Dx = a + u*u - u*(u+1)/2;
            int tx = u;
            for(int i = 1; Dx > 0; ++i){
                Dx -= i;
                ++tx;
            }

            // solve y-axis
            int Dy = v*v - v*(v+1)/2;
            int ty = v;
            for(int i = 1; Dy > 0; ++i){
                Dy -= i;
                ++ty;
            }

            cout << max(tx, ty) << endl;
        }
    }

    return 0;
}
