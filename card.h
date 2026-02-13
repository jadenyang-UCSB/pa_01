// card.h
// Author: Your name
// All class declarations related to defining a single card go here

#ifndef CARD_H
#define CARD_H

// card.cpp
// Author: Your name
// Implementation of the classes defined in card.h
#include <iostream>
using namespace std;


class card{
    public:
        card();
        card(string cardInfo);  
        friend bool operator==(card a, card b);
        friend bool operator!=(card a, card b);
        friend bool operator<(card a, card b);
        friend bool operator>(card a, card b);
        friend ostream& operator<<(ostream& os, const card& a);
    private:
        string number;
        string rank; 
        
};

struct Node{
    card data;
    Node* parent;
    Node* left;
    Node* right;
    Node(card c) : data(c), parent(nullptr), left(nullptr), right(nullptr){}
};

bool operator==(card a, card b);
bool operator!=(card a, card b);
bool operator<(card a, card b);
bool operator>(card a,card b);
ostream& operator<<(ostream& os, const card& a);

#endif
