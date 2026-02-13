// This file should implement the game using the std::set container class
// Do not include card_list.h in this file
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "card.h"

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }

  std::set<card> cardOne;
  std::set<card> cardTwo;

  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
    card c(line);
    cardOne.insert(c);
  }
  cardFile1.close();


  while (getline (cardFile2, line) && (line.length() > 0)){
    card c(line);
    cardTwo.insert(c);
  }
  cardFile2.close();
  

  bool aliceTurn = true;
  set<card> deleteCard;

  for(auto alice_begin = cardOne.begin(); alice_begin != cardOne.end(); alice_begin++){
      if(cardTwo.contains(*alice_begin)){
        deleteCard.insert(*alice_begin);
      }
  }

  while(!deleteCard.empty()){
    card picker;
    if(aliceTurn){
      picker = *deleteCard.begin();
      cout << "Alice picked matching card " << picker << "\n";
      aliceTurn = false;
    }
    else{
      picker = *deleteCard.rbegin();
      cout << "Bob picked matching card " << picker << "\n";
      aliceTurn = true;
    }
    cardTwo.erase(picker);
    cardOne.erase(picker);
    deleteCard.erase(picker);
  }
  cout << "\n";
  cout << "Alice's cards:" << "\n";
  for(card a: cardOne){
    cout << a << "\n";
  }

  cout << "\n";

  cout << "Bob's cards:" << "\n";
  for (card b: cardTwo){
    cout << b << "\n";
  }
  // if(found == true && aliceTurn == true){
  //   cout << "Alice picked a matching card: " << deleteCard;
  //   cardTwo.erase(deleteCard);
  //   cardOne.erase(deleteCard);
  //   aliceTurn = false;
  // }
  // else if(found == true && aliceTurn == false){
  //   cout << "Bob picked a matching card: " << deleteCard;
  //   cardTwo.erase(deleteCard);
  //   cardOne.erase(deleteCard);
  //   aliceTurn = true;
  // }

  return 0;
}




  // for(auto card: cardOne){
  //   cout << card;
  // }
  // cout << "This is alice's inital cards" << *alice_begin;
//Find the duplicates and remove. Backwards or forwards? Tell me after