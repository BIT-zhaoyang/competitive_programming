//
//  uva00230.cpp
//
//
//  Created by 赵洋 on 15/9/19.
//
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define ONSHELF 0
#define OFFSHELF 1

using namespace std;


class Book{
public:
    Book(string t, string a){
        title = t;
        author = a;
        status = ONSHELF;
    }
    
    friend bool operator<(Book b1, Book b2){
        if(b1.author < b2.author){
            return true;
        }
        
        if(b1.author == b2.author && b1.title < b2.title){
            return true;
        }
        
        return false;
    }
    
    string get_title(){
        return title;
    }
    
    bool on_shelf(){
        return status == ONSHELF;
    }
    
    void borrowed(){
        status = OFFSHELF;
    }
    
    void returned(){
        status = ONSHELF;
    }
    
private:
    string title;
    string author;
    bool status;
};

void parse_book(string &line, string &title, string &author){
    for(int i = 1; i < line.length(); ++i){
        if(line[i] == '"'){
            string t(line, 1, i - 1);
            title = t;
            string a(line, i + 5);
            author = a;
            return;
        }
    }
}

void extract_title(string &line, string &title){
    string t(line, 8, line.length() - 9);
    title = t;
}

int main(){
    string line, title, author;
    int count = 0, idx;
    vector<Book> shelf;
    vector<Book> cart;
    map<string, int> m;
    while(true){
        getline(cin, line);
        if(line[0] == '"'){
            parse_book(line, title, author);
            shelf.push_back(Book(title, author));
        } else if(line[0] == 'E'){
            if(count == 0){
                sort(shelf.begin(), shelf.end());
                for(int i = 0; i < shelf.size(); ++i){
                    title = shelf[i].get_title();
                    m[title] = i;
                }
                ++count;
            } else {
                break;
            }
        } else if(line[0] == 'B'){
            extract_title(line, title);
            idx = m[title];
            shelf[idx].borrowed();
        } else if(line[0] == 'R'){
            extract_title(line, title);
            idx = m[title];
            cart.push_back(shelf[idx]);
        } else {
            if(cart.size() == 0){
                cout << "END" << endl;
            } else {
                sort(cart.begin(), cart.end());
                for(int i = 0; i < cart.size(); ++i){
                    title = cart[i].get_title();
                    idx = m[title];
                    int j = idx - 1;
                    for(; j >= 0; --j){
                        if(shelf[j].on_shelf()){
                            cout << "Put \"" << title << "\" after \"" << shelf[j].get_title()
                            << "\"" << endl;
                            break;
                        }
                    }
                    if(j == -1){
                        cout << "Put \"" << title << "\" first" << endl;
                    }
                    shelf[idx].returned();
                }
                cart.clear();
                cout << "END" << endl;
            }
        }
        //        cout << title << " by " << author << endl;
    }
    return 0;
}