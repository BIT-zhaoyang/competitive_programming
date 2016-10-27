#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

/* Lesson learned:
    1. If you can use system stack, for example, by doing recursion,
       then use it! Don't make a stack<T> and mock the process by yourself.
       You may easily make mistake about when to pop an element.
    2. This situation is likely to appear while processing a tree. 
       In recursion, it would be better to just return some value for processing base cases.
       Leave the complex logic judgement back to the non-base case calls. In another
       word, try to process logic judgement only in the current layer, don't push
       that judgement down to deeper recursions.
*/

// =============== Solution 1: build the tree explicitly ===============
// struct Node{
//     Node(int _val): val(_val){}
//     ~Node(){
//         if(left)    delete left;
//         if(right)   delete right;
//     }
//     int val;
//     Node *left, *right;
// };
//
// class Tree{
// public:
//     Tree(): root(NULL){}
//     ~Tree(){
//         if(root)    delete root;
//     }
//
//     void build_tree(){
//         root = build_node();
//     }
//
//     void inOrder(){
//         inOrder(root);
//         cout << endl;
//     }
//
//     bool find_sum(int target){
//         if(root == NULL)    return false;
//         return find_sum(root, 0, target);
//     }
// private:
//     Node *build_node(){
//         int val;    char ch;
//         cin >> ch;
//         Node *node = NULL;
//         if(cin >> val){
//             node = new Node(val);
//             node->left = build_node();
//             node->right = build_node();
//         } else {
//             cin.clear();
//         }
//         cin >> ch;
//         return node;
//     }
//
//     void inOrder(Node *node){
//         if(node){
//             inOrder(node->left);
//             cout << node->val << " ";
//             inOrder(node->right);
//         }
//     }
//
//     bool find_sum(Node *node, int sum, int target){
//         if(node == NULL)    return false;
//         if(node->left == NULL && node->right == NULL)   return (sum + node->val) == target;
//         else return(find_sum(node->left, sum + node->val, target) ||
//                     find_sum(node->right, sum + node->val, target));
//     }
//
// private:
//     Node *root;
// };
//
// int main(){ _
//     int target;
//     while(cin >> target){
//         Tree tree;
//         tree.build_tree();
//         if(tree.find_sum(target))   cout << "yes" << endl;
//         else    cout << "no" << endl;
//     }
//     return 0;
// }

// =============== Solution 2: don't build the tree ===============
bool get_value(int target, int sum, bool &found){
    int val;    char ch; bool getValueSuccess = true;
    cin >> ch;
    if(cin >> val){
        sum += val;
        bool hasChild = false;
        hasChild |= get_value(target, sum, found); //left child
        hasChild |= get_value(target, sum, found); //right child
        if(!hasChild)   found |= (sum == target); //if has no children, judge if the target is found
    } else {
        getValueSuccess = false;
        cin.clear();
    }
    cin >> ch;
    return getValueSuccess;
}

bool find_sum(int target){
    bool found = false;
    get_value(target, 0, found);
    return found;
}

int main(){ _
    int target;
    while(cin >> target){
        bool found = false;
        found = find_sum(target);
        if(found)   cout << "yes" << endl;
        else    cout << "no" << endl;
    }
}
