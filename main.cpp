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
    Node* root = a.getRoot();
    card c = card(line);
    a.insert(root, c);
  }
  Node* root = a.getRoot();
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
    card z = card(line);
    Node* root = b.getRoot();
    b.insert(root,z);
  }

  root = b.getRoot();
  card test = card("s 10");
  card testOne = card("h 10");
  card testTwo = card("c 2");
  card testThree = card("c 3");
  card testFour = card("d a");
  card testFive = card("d j");
  card testSix = card("h a");

  cout << "This is before" << "\n";
  b.preOrder(root);

  b.remove(test);
  b.remove(testOne);
  b.remove(testTwo);
  root = b.getRoot();
  b.remove(testThree);
  root = b.getRoot();
  b.remove(testFour);
  root = b.getRoot();
  b.remove(testFive);
  root = b.getRoot();
  b.remove(testSix);
  
  cout << "This is after" << "\n";
  root = b.getRoot();
  // cout << root->data;
  b.preOrder(root);
  cout << "There is nothing here" << "\n";

  cardFile2.close();

  return 0;
}
