#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

/* A seemingly easy problem but with many subtleties.
    ======================================================
    First, I made a mistake on the algorithm.. Since I know this is classified as a greedy problem, thus I intially think that the greedy rule is: keeping multiply by 2 until we are going to get larger than s. Namely,
        while(n*2 < s){
            n *= 2;
            ++count;
        }
    then, we compare
        min(abs(s - n), abs(n+2 - s)+1).

    This works for the sample input 7, which misleads me strongly. The given solution is
            1 -> 2 -> 4 -> 8 -> 7
    However, another solution could be
            1 -> 2 -> 3 -> 6 -> 7
    Thus, it's not optimal to multiply by 2 as long as we can. Clearly, our greedy rule used above is not correct.
    ======================================================
    Then I saw the blog at here: https://tausiq.wordpress.com/2011/01/01/uva-11567-moliu-number-generator/
    It gives me a very bright hint. (However, I don't fully agree with his solution though it works.) After seeing this hint, I prefer to do this in a DP way and I think this DP solution is the optiaml one.

    When I implement the DP solution, there is another tricky part. The recursion is:
        talbe[n] = min(table[n-1], table[n+1]) + 1
    But when we computing table[n], we don't know table[n+1] yet! How could we solve this? Well, this is fairly easy. We can do:
        talbe[n] = min(table[n-1], table[(n+1)/2]+1) + 1
    since (n+1)/2 <= n.

    Pay attention to the '=' in (n+1)/2 <= n. I didn't notice this at my first try. I initialized my map only by map[0] = 0. Then my function goes to Segmentation Fault (caused by infinite recusion call). The reason is that, when I compute table[1], the formula becomes:
        table[1] = min(table[0, table[1]+1) + 1
    So the rec(1) will keep calling himself again and again. The recusion goes infinitly.

    ======================================================
    Lesson learned:
    1. When you face a problem of going from some point to another point and you can't find an easy, elegant way, try to solve the problem backwards.

    2. Don't rely on the given input that much. Think if there are other optimal/alternative solution to the same given input. When you are looking for alternative solution, you may found bugs in your code or some other bright insights! Use this problem as example, for a given number s=2n+1. The previous step before getting s could be any of s+1 -> s, s-1 -> s, 2s -> s, s/2 ->s.
    In my first try, I missed s+1 -> s, that's why I get the wrong greedy rule.

    3. Think clearly about the basic cases. Go through some basic cased manually. As the guy in Google interview video said: When you go through the code, don't assume it works. Go through it as if you are looking at other's code and you have no idea what's going on, what algorithm he/she is using. Go through the code line by line and execute exactly what's written there.
*/

int rec(long long s, map<long long, int> &mii){
    if(mii.count(s))    return mii[s];

    int ans = 0;
    if(s % 2 == 0){
        ans = rec(s/2, mii) + 1;
    } else {
        ans = 1;    // for the +1/-1 operation
        ans += min( rec(s-1, mii), rec( (s+1)/2, mii)+1 );  // the +1 in the second rec() is for /2
    }

    mii[s] = ans;
    return ans;
}


int main(){ _
    long long s;
    map<long long, int> mii;
    mii[0] = 0, mii[1] = 1, mii[2] = 2;
    while(cin >> s){
        cout << rec(s, mii) << endl;
    }
    return 0;
}
