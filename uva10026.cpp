#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

/* Lesson learned: !!!!!
    How to decide which greedy feature to use in a greedy problem? (This (ONLY?) applies to greedy problem involving permutation.)
    In this problem, there are a lot of potential features to choose. For example: shortest time span, largest penalty, etc... But as we have seen in other problems, which feature should we choose? It looks like a guessing game!(In fact, the feature used in this problem is really less intuitive.)

    So, how do we choose the feature? Here I suggest that we process the problem backwards. Suppose we have a candidate sequence: <e_1 e_2 e_3 ... x y e_m e_m+1 ... e_n>. Suppose this sequence is generated following a greedy rule. What rule is it? We don't know now. Let's change the possition of x & y and see what happens. So the new sequence becomes: <e_1 e_2 e_3 ... y x e_m e_m+1 ... e_n>. We can notice that the penalty caused by sequences placed before x & y don't change. In another word, changing the order of x & y won't affect the cost caused by sequences placed before x&y. This conclusiong also applies to sequences placed after x&y. So only the cost caused by x & y themselves will be changed.

    Since we generate the first sequence under some greedy rule, and we assume this greedy rule will leads us to a correct solution, thus the second sequence which breaks the greedy rule will lead to a suboptimal solution. Thus, the cost of x&y in first sequence(According to last paragraph, we only need to focus on the cost caused by x&y) is: t*P_x + (t+x)*P_y. In second sequence, it is: t*P_y + (t+y)*P_x.(Suppose in sequence 1, x happens at time t. After exchange y, in sequence 2, y happens at time t). Then, we have t*P_x + (t+x)*P_y > t*P_y + (t+y)*P_x which must hold! After some operations, we get this formula: x/P_x < y/P_y which is the greedy rule we are looking for!(In some problem, there may be numerical issues. In these kind of problem, we can use P_x/x > P_y/y instead.)

    This analysis also applies to the Minimizing Lateness problem in Bjarki Agust's CP course.

    I haven't come up with an idea to generalize this greedy rule finding pattern to other problems. For now, !!!for selection problems,!!! just keep in mind, our goal is to prove that there will always be !!some!! optimal solution which always choose the greedy candidate. In another word, choosing a greedy candidate never leads to worse result. Then maybe we can try all the possible greedy rules?
*/

int main(){ _
    int TC; cin >> TC;
    while(TC--){
        int n;  cin >> n;
        int t, p;   vector< pair<double, int> > vd(n);
        for(int i = 0; i < n; ++i){
            cin >> t >> p;
            vd[i] = make_pair(t / double(p), i+1);
        }

        stable_sort(vd.begin(), vd.end());

        for(int i = 0; i < vd.size(); ++i){
            if(i)   cout << " ";
            cout << vd[i].second;
        }   cout << endl;

        if(TC)  cout << endl;
    }
    return 0;
}
