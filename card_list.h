// card_list.h
// Author: Your name
// All class declarations related to defining a BST that represents a player's hand
using namespace std;

#ifndef CARD_LIST_H
#define CARD_LIST_H

#include "card.h"
#include <iostream>

    class Iterator{
        public:
            Iterator(Node* root);
            Iterator& operator++();
            Iterator& operator--();
            card& operator*();
            card* operator->();
        private:
            Node* node;
    };


    class cardBST{
        public:

            ~cardBST();
            cardBST(); //DONE
            cardBST(card head); //DONE

            void insert(Node* head, card a); //DONE
            void remove(card a);
            void removeHelp(Node* head, card a); //DONE
            bool contains(Node* head, card a); //DONE
            Node* getRoot();

            Iterator begin(); //DONE
            Iterator end(); //DONE
            Iterator rbegin(); //DONE
            Iterator rend(); //DONE

            Node* successor(Node* head); //DONE
            Node* predecessor(Node* head); // DONE
            Node* find(Node* head, card number); //DONE
            
            void inOrder(Node* head);
            void preOrder(Node* head);
            void postOrder(Node* head);
            
        private:
            void destructHelp(Node* del);
            Node* root;
    };


#endif


