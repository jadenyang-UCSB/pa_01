    // card_list.cpp
    // Author: Jaden Yang and Natasha Doan
    // Implementation of the classes defined in card_list.h

    #include <iostream>
    #include "card.h"
    #include "card_list.h"
    class cardBST;

    // class Iterator{
    //     public:
    //         Iterator(Node* root, cardBST* origi);
    //         Iterator& operator++();

    //         friend bool operator==(Iterator a, Iterator b);
    //         friend bool operator!=(Iterator a, Iterator b);

    //         Iterator& operator--();
    //         card& operator*();
    //         card* operator->();
    //         Node* getNode();
    //     private:
    //         cardBST* original;
    //         Node* node;
    // };

    bool operator==(Iterator a, Iterator b){
        if(a.node == b.node){
            return true;
        }
        return false;
    }

    bool operator!=(Iterator a, Iterator b){
        return !(a == b);
    }


    // class cardBST{
    //     public:
    //         ~cardBST();
    //         cardBST(); //DONE
    //         cardBST(card head); //DONE

    //         void insert(Node* head, card a); //DONE //DONE
    //         void remove(card a); //DONE // DONE
    //         bool contains(Node* head, card a); //DONE //DONE
    //         Node* getRoot(); //DONE //DONE

    //         Iterator* begin(); //DONE
    //         Iterator* end(); //DONE
    //         Iterator* rbegin(); //DONE
    //         Iterator* rend(); //DONE

    //         Node* find(Node* head, card number); //DONE //DONE
            
    //         void inOrder(Node* head);
    //         void preOrder(Node* head); 
    //         void postOrder(Node* head);
    //         Node* successor(Node* head); //DONE //DONE
    //         Node* predecessor(Node* head); // DONE // DONE
            
    //     private:
    //         void removeHelp(Node* head, card a); //DONE
    //         void destructHelp(Node* del);
    //         Node* root;
    // };

    cardBST::cardBST(){
        root = nullptr;
    }

    cardBST* Iterator::getbstClass(){
        return original;
    }

    cardBST::cardBST(card head){
        root = new Node(head);
    }

    Node* cardBST::getRoot(){
        return root;
    }

    void cardBST::insert(card a){
        insertHelper(root, a);
    }

    void cardBST::insertHelper(Node* head, card a){
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
                insertHelper(head->left, a);
            }
        }
        else if(head->data < a){
            if(head->right == nullptr){
                head->right = new Node(a);
                head->right->parent = head;
                return;
            }
            else{
                insertHelper(head->right, a);
            }
        }

    }

    bool cardBST::contains(card a){
        return containsHelp(root, a);
    }

    bool cardBST::containsHelp(Node* head, card a){

        if(head == nullptr){
            return false;
        }

        if(head->data == a){
            return true;
        }
        else if(head->data > a){
            return containsHelp(head->left, a);
        }
        else{
            return containsHelp(head->right, a);
        }

    }

    Node* cardBST::successor(Node* head){
        if(!head){
            return nullptr;
        }
        
        if(!(contains(head->data))){
            return nullptr;
        }
        
        Node* edgeCase = root;
        while(edgeCase->right){
            edgeCase = edgeCase->right;
        }
        if(edgeCase == head){
            return nullptr;
        }

        Node* traverse = head;

        if(!traverse->right){
            while(traverse->parent != nullptr && traverse->data > traverse->parent->data){
                traverse = traverse->parent;
            }
        }

        if(!head->right){
            return traverse->parent;
        }


        Node* rightNode = head->right;
        while(rightNode->left){
            rightNode = rightNode->left;
        }

        return rightNode;
    }

    Node* cardBST::predecessor(Node* head){
        if(!head){
            return nullptr;
        }

        if(!(contains(head->data))){
            return nullptr;
        }

        Node* edgeCase = root;
        while(edgeCase->left){
            edgeCase = edgeCase->left;
        }

        if(edgeCase == head){
            return nullptr;
        }

        Node* traverse = head;
        if(!traverse->left){
            while(traverse->parent != nullptr && traverse->data < traverse->parent->data){
                traverse = traverse->parent;
            }
        }

        if(!head->left){
            return traverse->parent;
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

    void cardBST::inOrder(){
        inOrderHelp(root);
    }
    void cardBST::inOrderHelp(Node* head){
        if(head == nullptr){
            return;
        }
        inOrderHelp(head->left);
        cout << head->data << "\n";
        inOrderHelp(head->right);
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
        delete del;
    }

    Iterator::Iterator(Node* root, cardBST* ori){
        node = root;
        original = ori;
    }

    Node* Iterator::getNode(){
        return node;
    }

    Iterator* cardBST::begin(){
        Node* traverse = root;
        if(!root){
            return end();
        }
        while(traverse->left){
            traverse = traverse->left;
        }

        return new Iterator(traverse, this);
    }

    Iterator* cardBST::end(){
        return new Iterator(nullptr, this);
    }

    Iterator* cardBST::rend(){
        return new Iterator(nullptr, this);
    }

    Iterator* cardBST::rbegin(){
        Node* traverse = root;
        if(!root){
            return rend();
        }
        while(traverse->right){
            traverse = traverse->right;
        }

        return new Iterator(traverse, this);
    }

    Iterator& Iterator::operator++(){
        if(node != nullptr){
            Node* change = original->successor(node);
            node = change;
        }
        return *this;
    }

    Iterator& Iterator::operator--(){
        if(node != nullptr){
            Node* change = original->predecessor(node);
            node = change;
        }
        return *this;
    }

    card& Iterator::operator*(){
        return node->data;
    }

    card* Iterator::operator->(){
        return &(node->data);
    }

    card Iterator::getData(){
        return getNode()->data;
    }


void playGame(cardBST& a, cardBST& b){
  cardBST deleteCards;

  //Format for iterating
  auto it = a.begin();
  auto itEND = a.end();
  while(*it != *itEND){
      if(it && b.contains(*(*it))){
        deleteCards.insert(*(*it));
      }
      ++(*it);
  }
  delete it;


  bool alice_turn = true;
  card toDelete;
  auto deleteIterate = deleteCards.begin();
  auto deleteIterateEND = deleteCards.end();

  while(*deleteIterate != *deleteIterateEND){
    delete deleteIterate;
    delete deleteIterateEND;

    if (alice_turn) {
        Iterator* it = deleteCards.begin();
        toDelete = *(*it);
        delete it;
        cout << "Alice picked matching card " << toDelete << "\n";
    } else {
        Iterator* it = deleteCards.rbegin();
        toDelete = *(*it);
        delete it;
        cout << "Bob picked matching card " << toDelete << "\n";
    }
    a.remove(toDelete);
    b.remove(toDelete);
    deleteCards.remove(toDelete);
    alice_turn = !alice_turn;

    deleteIterate = deleteCards.begin();
    deleteIterateEND = deleteCards.end();
  }

  delete deleteIterate;
  delete deleteIterateEND;
  
  cout << "\n" << "Alice's cards:" << "\n";
  a.inOrder();
  cout << "\n" << "Bob's cards:" << "\n";
  b.inOrder();
}