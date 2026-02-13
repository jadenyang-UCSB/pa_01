    // card_list.cpp
    // Author: Your name
    // Implementation of the classes defined in card_list.h

    #include <iostream>
    #include "card.h"

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

    cardBST::cardBST(){
        root = nullptr;
    }

    cardBST::cardBST(card head){
        root = new Node(head);
    }

    Node* cardBST::getRoot(){
        return root;
    }

    void cardBST::insert(Node* head, card a){
        if(!root){
            root = new Node(a);
            return;
        }

        // if(!head){  // ✓ CHECK FOR NULL FIRST
        //     return;
        // }
        
        if(head->data == a){
            return;
        }

        if(head->data > a){
            if(head->left == nullptr){
                head->left = new Node(a);
                head->left->parent = head;
                return;
            }
            else{
                insert(head->left, a);
            }
        }
        else if(head->data < a){
            if(head->right == nullptr){
                head->right = new Node(a);
                head->right->parent = head;
                return;
            }
            else{
                insert(head->right, a);
            }
        }

    }

    bool cardBST::contains(Node* head, card a){

        if(head == nullptr){
            return false;
        }

        if(head->data == a){
            return true;
        }

        if(head->data > a){
            return contains(head->left, a);
        }
        else{
            return contains(head->right, a);
        }
    }

    Iterator cardBST::begin(){
        Node* traverse = root;
        while(traverse->left){
            traverse = traverse->left;
        }

        return Iterator(traverse);
    }

    Iterator cardBST::end(){
        Node* traverse = root;
        while(traverse->right){
            traverse = traverse->right;
        }

        return Iterator(traverse);
    }

    Iterator cardBST::rend(){
        Node* traverse = root;
        while(traverse->left){
            traverse = traverse->left;
        }

        return Iterator(traverse);
    }

    Iterator::Iterator(Node* root){
        node = root;
    }

    Iterator cardBST::rbegin(){
        Node* traverse = root;
        while(traverse->right){
            traverse = traverse->right;
        }

        return Iterator(traverse);
    }

    Node* cardBST::successor(Node* head){

        if(!(contains(root, head->data))){
            return nullptr;
        }

        Node* edgeCase = head;
        while(edgeCase->right){
            edgeCase = edgeCase->right;
        }

        if(edgeCase->data == head->data){
            return nullptr;
        }

        Node* traverse = head;
        if(!traverse->right){
            while(traverse->data > traverse->parent->data && traverse->parent != nullptr){
                traverse = traverse->parent;
            }
        }

        if(!head->right){
            return traverse;
        }

        Node* rightNode = head->right;
        while(rightNode->left){
            rightNode = rightNode->left;
        }

        return rightNode;
    }

    Node* cardBST::predecessor(Node* head){

        if(!(contains(root, head->data))){
            return nullptr;
        }

        Node* edgeCase = head;
        while(edgeCase->left){
            edgeCase = edgeCase->left;
        }

        if(edgeCase->data == head->data){
            return nullptr;
        }

        Node* traverse = head;
        if(!traverse->left){
            while(traverse->data > traverse->parent->data && traverse->parent != nullptr){
                traverse = traverse->parent;
            }
        }

        if(!head->left){
            return traverse;
        }

        Node* leftNode = head->left;
        while(leftNode->right){
            leftNode = leftNode->right;
        }

        return leftNode;
    }

    Node* cardBST::find(Node* root, card number){
        if(!root){
            return nullptr;
        }
        if(root->data == number){
            return root;
        }
        else if(root->data > number){
            return (find(root->left, number));
        }
        else{
            return(find(root->right, number));
        }
    }

    void cardBST::remove(card a){
        removeHelp(root, a);
        return;
    }

    void cardBST::removeHelp(Node* head, card number){
        Node* finder = find(head, number);

        if(!finder){
            return;
        }

        if(!finder->left && !finder->right){
            if(finder == root){
                if(head->parent && head->parent->left == head){
                    head->parent->left = nullptr;
                    delete finder;
                    return;
                }
                else if(head->parent && head->parent->right == head){
                    head->parent->right = nullptr;
                    delete finder;
                    return;
                }
                else{
                    delete finder;
                    root = nullptr;
                    return;
                }
            }
            else if(finder->parent->left == finder){
                finder->parent->left = nullptr;
            }
            else{
                finder->parent->right = nullptr;
            }
            finder->parent = nullptr;
            delete finder;
            return;
        }

        else if((finder->right && !finder->left) || (!finder->right && finder->left)){
            if(finder == root){
                if(finder->right){
                    root = finder->right;
                    root->parent = nullptr;
                    finder->right = nullptr;
                    delete finder;
                    return;
                }
                else{
                    root = finder->left;
                    root->parent = nullptr;
                    finder->left = nullptr;
                    delete finder;
                    return;
                }
            }

            if(finder->right){
                if(finder->parent->left == finder){
                    finder->parent->left = finder->right;
                    finder->right->parent = finder->parent;
                }
                else{
                    finder->parent->right = finder->right;
                    finder->right->parent = finder->parent;
                }
                delete finder;
                return;
            }
            else{
                if(finder->parent->left == finder){
                    finder->parent->left = finder->left;
                    finder->left->parent = finder->parent;
                }
                else{
                    finder->parent->right = finder->left;
                    finder->left->parent = finder->parent;
                }
                delete finder;
                return;
            }
        }
        else{
            Node* pre = predecessor(finder);
            Node* scope = find(head, number);
            card focus = pre->data;
            removeHelp(root, pre->data);
            scope->data = focus;
        }
    }

    void cardBST::inOrder(Node* head){
        if(head == nullptr){
            return;
        }
        inOrder(head->left);
        cout << head->data << "\n";
        inOrder(head->right);
        return;
    }

    void cardBST::preOrder(Node* head){
        if(head == nullptr){
            return;
        }
        cout << head->data << "\n";
        preOrder(head->left);
        preOrder(head->right);
        return;
    }

    void cardBST::postOrder(Node* head){
        if(head == nullptr){
            return;
        }
        postOrder(head->left);
        postOrder(head->right);
        cout << head->data << "\n";
        return;
    } 

    cardBST::~cardBST(){
        destructHelp(root);
    }

    void cardBST::destructHelp(Node* del){
        if(del == nullptr){
            return;
        }
        destructHelp(del->left);
        destructHelp(del->right);
        remove(del->data);
    }