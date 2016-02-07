//
//  uva11988.cpp
//  
//
//  Created by 赵洋 on 15/9/24.
//
//

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

struct Node{
    char ch;
    Node *next;
};

int main(){
    string str;
    while(cin >> str, !cin.eof()){
        Node *head, *tail, *insert;
        Node *dummy = new Node;
        dummy->next = NULL;
        head = dummy, tail = dummy, insert = dummy;
        for(int i = 0; i < str.length(); ++i){
            if(str[i] == '['){
                insert = head;
            } else if (str[i] == ']'){
                insert = tail;
            } else {
                Node *n = (Node *)new Node;
                n->ch = str[i];
                n->next = insert->next;
                insert->next = n;
                if(insert == tail){
                    insert = insert->next;
                    tail = insert;
                } else {
                    insert = insert->next;
                }
            }
        }
        
        insert = head->next;
        while(insert != NULL){
            cout << insert->ch;
            insert = insert->next;
        }
        cout << endl;
        
        // Need to release the nodes here
    }
    return 0;
}