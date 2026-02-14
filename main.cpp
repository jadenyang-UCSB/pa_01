// This file should implement the game using a custom implementation of a BST (based on your earlier BST implementation)
#include <iostream>
#include <fstream>
#include <string>
#include "card.h"
#include "card_list.h"
//Do not include set in this file

using namespace std;

int main(int argv, char** argc){

  cardBST a;
  cardBST b;

  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
    card c = card(line);
    Node* root = a.getRoot();
    a.insert(root, c);
  }
  // Node* root = a.getRoot();
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
    card z = card(line);
    Node* root = b.getRoot();
    b.insert(root,z);
  }

  cardFile2.close();


  cardBST deleteCards;

  //Format for iterating
  auto it = a.begin();
  while(it && it->getNode() != nullptr){
      if(b.contains(b.getRoot(),it->getNode()->data)){
        deleteCards.insert(deleteCards.getRoot(),it->getNode()->data);
      }
      ++(*it);
  }
  delete it;


  bool alice_turn = true;
  Node* toDelete = nullptr;
  while(deleteCards.getRoot() != nullptr){
    if(alice_turn){
      toDelete = deleteCards.begin()->getNode();
      cout << "Alice picked matching card " << toDelete->data << "\n";
      alice_turn = false;
    }
    else{
      toDelete = deleteCards.rbegin()->getNode();
      cout << "Bob picked matching card " << toDelete->data << "\n";
      alice_turn = true;
    }
    a.remove(toDelete->data);
    b.remove(toDelete->data);
    deleteCards.remove(toDelete->data);
  }
  cout << "\n" << "Alice's cards:" << "\n";
  a.inOrder(a.getRoot());
  cout << "\n" << "Bob's cards:" << "\n";
  b.inOrder(b.getRoot());
  return 0;
}

  // root = b.getRoot();
  // card test = card("s 10");
  // card testOne = card("h 10");
  // card testTwo = card("c 2");
  // card testThree = card("c 3");
  // card testFour = card("d a");
  // card testFive = card("d j");
  // card testSix = card("h a");

  // cout << "This is before" << "\n";
  // b.preOrder(root);

  // b.remove(test);
  // b.remove(testOne);
  // b.remove(testTwo);
  // root = b.getRoot();
  // b.remove(testThree);
  // root = b.getRoot();
  // b.remove(testFour);
  // root = b.getRoot();
  // b.remove(testFive);
  // root = b.getRoot();
  // b.remove(testSix);
  
  // cout << "This is after" << "\n";
  // root = b.getRoot();
  // // cout << root->data;
  // b.preOrder(root);
  // cout << "There is nothing here" << "\n";

    
  // for(auto it = b.begin(); it && it->getNode() != nullptr; ++(*it)){
  //   // cout << it;
  //   // if(it != nullptr){
  //   if(it->getNode() != nullptr){
  //       cout << it->getNode()->data << "\n";
  //   }
  //   // }
  // }
  //Format
  // auto ITERATION = b.begin();
  // cout << b.rbegin()->getNode()->data << "\n"; 
  // cout << ITERATION->getNode() << "\n";
  // ++(*ITERATION);
  // cout << ITERATION->getNode() << "\n";
  // cout << (*ITERATION).getNode()->data << "\n";
    // Node* root = b.getRoot();
  // cout << root->data;
  // // cout << b.predecessor(root);
  // // cout << "I did it";
  // // cout << b.successor(root);

    // auto it = b.rbegin();
  // while(it && it->getNode()){
  //     --(*it);
  //     if(it->getNode() == nullptr){
  //       cout << "STOP IT NOW" << "\n";
  //     }
  //     else{
  //       cout << "This is my node" << it->getNode()->data << "\n";
  //     }
  // }