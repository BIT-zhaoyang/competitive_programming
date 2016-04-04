#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <climits>
#include <cmath>
#include <set>

#ifndef RBTREE
#define  RBTREE

#define red 1
#define black 0

class RBTree{
public:
    RBTREE(){
        root = nil;
        nil = Node();
    }

    ~RBTREE(){
        destroy(root);
    }

    void insert(int val);

    Node* search(int val);

private:
    struct Node{
        int key;
        Node *left, *right, *p;
        bool color;     // 0: Black     1: Red

        Node(): key(-1), left(0), right(0), p(0), color(black){}
        Node(int val): key(val), left(0), right(0), p(0), color(red){}
        Node(int val, Node *l, Node *r): key(val), left(l), right(r), p(0), color(red){}
    }*  root, nil;

    void fix(Node *x);
};

void RBTree::insert(int val){
    Node *n = new Node(val, nil, nil);

    Node *x = root;
    Node *y;
    while(x != nil){
        y = x;
        if(val < x->key)    x = x->left;
        else    x = x->right;
    }

    if(y == nil)    root = n;
    else if(val < y->key)    y->left = n;
    else    y->right = n;

    n->p = y;

    fix(n);
}

Node* BSTree::search(int val){
    Node *x = root;
    while(x != nil && x->key != val){
        if(val < x->key)    x = x->left;
        else    x = x->right;
    }
    return x;
}

void BSTree::fix(Node* z){
    while(z->p->color == red){
        if(z == z->p->p->left){
            Node *y = z->p->p->right;
            if(y->color == red){
                z->p->color = black;
                y->color = black;
                z->p->p->color = red;
                z = z->p->p;
            } else{
                if(z == z->p->right){
                    z = z->p;
                    left_rotate(z);
                }

            }
        }else{

        }
    }
}
#endif
