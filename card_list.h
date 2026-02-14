// card_list.h
// Author: Jaden Yang and Natasha
// All class declarations related to defining a BST that represents a player's hand
using namespace std;

#ifndef CARD_LIST_H
#define CARD_LIST_H

#include "card.h"
#include <iostream>

    class cardBST;
    class Iterator{
        public:
            Iterator(Node* root, cardBST* origi);
            Iterator& operator++();

            friend bool operator==(Iterator a, Iterator b);
            friend bool operator!=(Iterator a, Iterator b);

            Iterator& operator--();
            card& operator*();
            card* operator->();
            Node* getNode();
            cardBST* getbstClass();
        private:
            cardBST* original;
            Node* node;
    };


    class cardBST{
        public:
            ~cardBST();
            cardBST(); //DONE
            cardBST(card head); //DONE

            void insert(Node* head, card a); //DONE //DONE
            void remove(card a); //DONE // DONE
            bool contains(Node* head, card a); //DONE //DONE
            Node* getRoot(); //DONE //DONE

            Iterator* begin(); //DONE
            Iterator* end(); //DONE
            Iterator* rbegin(); //DONE
            Iterator* rend(); //DONE

            Node* find(Node* head, card number); //DONE //DONE
            
            void inOrder(Node* head);
            void preOrder(Node* head); 
            void postOrder(Node* head);
            Node* successor(Node* head); //DONE //DONE
            Node* predecessor(Node* head); // DONE // DONE
            
        private:
            void removeHelp(Node* head, card a); //DONE
            void destructHelp(Node* del);
            Node* root;
    };

    bool operator==(Iterator a, Iterator b);
    bool operator!=(Iterator a, Iterator b);

#endif


