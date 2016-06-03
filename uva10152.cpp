#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

/* super super excellent explanation at:
https://moodcoder.wordpress.com/2011/07/14/solving-shellsort-uva-10152-pc-110407/

What have I learned from this blog and problem? I don't exactly know...
I know we should simplify problem by considering the most basic case. I have to make a supplement now: simplify also includes use a better representation. I like the idea to use numbers to represent strings. I also did that while I was trying to solve the problem.

One point I didn't come up with is that treating the desired ordering as sorted. This makes the analysis much more intuitive and visualizable. What I did when I was analysis is consider a & b, suppose a is above b, then in our desired ordering, a may be still above b or it may be lower than b. Then I want to dicuss these situations. This is not very clear and indeed leads me to nowhere. Treating the desired ordering as sorted as the blog did makes the problem much easier. I think this may be another application of solving problem backwards.

In case the page is lost, I copied the blog at the end of the code.
*/

struct data{
    string str;
    int id;
    data(){
        str = "";
        id = -1;
    }
};

bool mycomp(data &a, data &b){
    return a.id < b.id;
}

int main(){ _
    int TC; cin >> TC;
    while(TC--){
        int n;  cin >> n;
        vector<data> vs(n);
        map<string, int> str2id;

        cin.ignore();
        string str;

        // Read the original order
        for(int i = 0; i < n; ++i){
            getline(cin, str);
            vs[i].str = str;
        }

        // Read the desired order
        for(int i = 0; i < n; ++i){
            getline(cin, str);
            str2id[str] = i;
        }

        // Write the correct id for the original order
        for(int i = 0; i < n; ++i){
            vs[i].id = str2id[vs[i].str];
        }

        // A turtle is said to be in reverse if its number is less than
        // the biggest number of the turtles above it
        int biggest = -1, biggestBreak = -1;
        for(int i = 0; i < n; ++i){
            if(vs[i].id < biggest){
                biggestBreak = max(biggestBreak, vs[i].id);
            } else {
                biggest = max(biggest, vs[i].id);
            }
        }

        // sort the data in correct order for us to output
        sort(vs.begin(), vs.end(), mycomp);

        while(biggestBreak >= 0){
            cout << vs[biggestBreak].str << endl;
            --biggestBreak;
        }
        cout << endl;
    }
    return 0;
}


/*
Analysis

Before we move on, I would like to remind that a turtle can only move to the top of the stack. We just pop an element and push it back to the top. This means, it doesn’t matter much if all elements are at the wrong position, what matters is if they follow a sequence. Take this as an example:

Desired Ordering / Original Ordering:

A / B
B / C
C / D
D / E
E / A

All elements are at the wrong position, but we can with a single move make it back to the desired ordering. We just have to move A to the top, this is the minimum ammount of moves we can make. So what’s the maximum? Is there a maximum ammount of moves to achieve the minimum ammount of necessary moves to fix the original ordering? Yes! We can convert any stack to any other stack doing n-1 moves, where n is the size of the stack. This means that if we didn’t have to always find the minimal solution, we could always print out the reversed desired stack without the last element to solve it. For the example above moving D, C, B and A also generates the desired ordering.

Here’s an example to demonstrate the maximum moves case:

Desired Ordering / Original Ordering:

1 / 1
2 / 2
3 / 3
4 / 4
5 / 5
6 / 6
7 / 8
8 / 7

In this case we have to make the maximum number of moves to put 7 at it’s right place even though the only elements wrong are 7 and 8. We have to move 7, 6, 5, 4, 3, 2 and 1. Interesting to notice is that once an element has been identified as wrong, we also have to move all elements above it in the desired ordering. 7 was wrong, so we had to move all numbers bigger than 7.

So what do we have to look for? What defines an element as wrong?(See my note for additional explanation) Let’s use the two examples above again. Notice how the sequence is increasing from B to E, this is great. What happens then is that A breaks the increasing order. This is bad. This means we have to fix A. A is supposed to be the first element, so we just move it to the top and everything is alright. Now at the 2nd example, everything is ok from 1 to 8, but then 7 shows up to mess our stack. We now had to move 7 numbers to get it at it’s right position.

Now let’s go back to the original input and rename all our turtles into numbers to make it easier to understand what’s wrong.

Desired ordering / Original Ordering:

1 / 1
2 / 4
3 / 3
4 / 5
5 / 6
6 / 2
7 / 7
8 / 8
9 / 9

The numbers should be in increasing order. From 1 to 4 ok, 3 then messes it up. Let’s write 3 down for now. 5 and 6 are ok, 2 is smaller than the biggest number so it breaks the increasing order too. Let’s write it down too. 7, 8 and 9 are ok. So the numbers we have to fix are 3 and 2. As 2 is smaller than 3, when we fix 3 we will have automatically fixed it too. So the solution is to move 3, 2 and 1.

That is, we don’t actually need to modify any of the stacks, once we know the biggest number that breaks the increasing order, we have the solution to the problem.



PS: what is really a wrong ordering?
A turtle is said to be in reverse if its number is less than the biggest number of the turtles above it

For example, take this example.
Desired/Original
1 / 1
2 / 2
3 / 3
4 / 4
5 / 7
6 / 5
7 / 6

6 is considered to be a wrong ordering since 6 < 7 even 6 > 5 in our original ordering.
*/
