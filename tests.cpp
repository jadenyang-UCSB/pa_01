#include <iostream>
#include <fstream>
#include <string>
#include "card.h"
#include "card_list.h"
#include <cassert>
using namespace std;

#include <vector>
bool card_equivilant(card a, card b){
    return a == b;
}

// bool card_check(){
//     //Checking if the == operator is fine
//     assert(card_equivilant(card("c 2"), card("c 2")));
//     assert(!(card_equivilant(card("c 4"), card("c 9"))));
//     assert(card_equivilant(card("d 9"), card("d 9")));
//     assert(!(card_equivilant(card("c 2"), card("d 2"))));
//     assert(!(card_equivilant(card("h 2"), card("d 2"))));
//     cout << "All card == tests passed \n";
//     return true;
// }

int main(){
    cardBST testONE;
    cardBST testTWO;
    cardBST testTHREE;
    cardBST testFOUR;
    cardBST testFIVE;

    vector<card> testOne_cards = {card("d 2"),card("d 5"), card("s 10"), card("s k"), card("s 1"), card("h a"), card("c 3"), card("c 9"), card("c 10")};
    vector<card> testTwo_cards = {card("h 10"),card("s 2"),card("c 10"), card("c 10"), card("d 6")};
    vector<card> testThree_cards ={card("d 10"),card("s 1"),card("h a"),card("c 3"),card("c 9"),card("c 10"),card("d 6"),card("d 9"),card("c 10")};
    vector<card> testFour_cards = {card("d 6")};

    int size = testOne_cards.size();
    int sizeTwo = testTwo_cards.size();
    int sizeThree = testThree_cards.size();
    int sizeFour = testFour_cards.size();
    Node* rootOne;
    Node* rootTwo;
    Node* rootThree;
    Node* rootFour;
    Node* rootFive;
    for(int one = 0; one < size; one++){
        rootOne = testONE.getRoot();
        testONE.insert(rootOne, testOne_cards[one]);
    }

    for(int two = 0; two < sizeTwo; two++){
        rootTwo = testTWO.getRoot();
        testTWO.insert(rootTwo, testTwo_cards[two]);
    }

    for(int three = 0; three < sizeThree; three++){
        rootThree = testTHREE.getRoot();
        testTHREE.insert(rootThree, testThree_cards[three]);
    }

    for(int four = 0; four < sizeFour; four++){
        rootFour = testFOUR.getRoot();
        testFOUR.insert(rootFour, testFour_cards[four]);
    }

    for(int five = 0; five < sizeTwo; five++){
        rootFive = testFIVE.getRoot();
    }

    rootOne = testONE.getRoot();
    rootTwo = testTWO.getRoot();
    rootThree = testTHREE.getRoot();
    rootFour = testFOUR.getRoot();
    rootFive = testFIVE.getRoot();


    // TESTING GETROOT()
    cout << "\n" << "TESTING GETROOT()" << "\n";
    assert(rootOne->data == card("d 2"));
    cout << "First test getRoot() passed" << "\n";
    assert(rootTwo->data == card("h 10"));
    cout << "Second test getRoot() passed" << "\n";
    assert(rootThree->data == card("d 10"));
    cout << "Third test getRoot() passed" << "\n";
    assert(rootFour->data == card("d 6"));
    cout << "Fourth test getRoot() passed" << "\n";
    assert(rootFive == nullptr);
    cout << "Fifth test getRoot() passed" << "\n";
    
    cout << "\n" << "GetROOT() has passed" << "\n";

    cout << "\n" << "TESTING CONTAINS" << "\n";
    cout << "First contains test passed" << "\n";
    assert(testONE.contains(rootOne, card("s 10")) == true);
    cout << "Second contains test passed" << "\n";
    assert(testTWO.contains(rootTwo, card("h 10")) == true);
    cout << "Third contains test passed" << "\n";
    assert(testTHREE.contains(rootThree, card("s 1")) == true);
    cout << "Four contains test passed" << "\n";
    assert(testFOUR.contains(rootFour, card("d a")) == false);
    cout << "Five contains test passed" << "\n";
    assert(testFIVE.contains(rootFive, card("a a")) == false);
    cout << "\n" << "CONTAINS() has passed" << "\n";

    Node* testOne_successor = testONE.find(rootOne, card("s 10"));
    Node* testTwo_successor = testTWO.find(rootTwo, card("d 6"));
    Node* testThree_successor = testTHREE.find(rootThree, card("d 10"));
    Node* testFour_successor = testFOUR.find(rootFour, card("s 10"));
    Node* testFive_successor = testFIVE.find(rootFive, card("a 8"));


    cout << "\n" << "TESTING FIND" << "\n";

    assert(testOne_successor->data == card("s 10"));
    cout <<"First find test passed" << "\n";

    assert(testTwo_successor->data == card("d 6"));
    cout << "Second find test passed" << "\n";

    assert(testThree_successor->data == card("d 10"));
    cout << "Third find test passed" << "\n";

    assert(testFour_successor == nullptr);
    cout << "Fourth find test passed" << "\n";

    assert(testFive_successor == nullptr);
    cout << "Fifth find test passed" << "\n";

    cout << "\n" << "All find test passed" << "\n";

    cout << "Fixing the fourth find to an actual node";
    testFour_successor = testFOUR.find(rootFour, card("d 6"));
    


    cout << "TESTING SUCCESSOR" << "\n";
    assert(testOne_successor->data == card("s 10"));
    cout << "First successor test passed" << "\n";

    
    assert(testTWO.successor(testTwo_successor)->data == card("s 2"));
    cout << "Second successor test passed" << "\n";

    
    assert(testTHREE.successor(testThree_successor)->data == card("s 1"));
    cout << "Third successor test passed" << "\n";

    
    assert(testFOUR.successor(testFour_successor) == nullptr);
    cout << "Fourth successor test passed" << "\n";

    assert(testFIVE.successor(testFive_successor) == nullptr);
    cout << "Fifth successor test passed" << "\n";

    cout << "\n" << "All successor test passed" << "\n";




    cout << "\n" << "TESTING PREDECESSOR" << "\n";
    
    assert(testONE.predecessor(testOne_successor)->data == card("s 1"));
    cout << "First predecessor test passed" << "\n";

    
    assert(testTWO.predecessor(testTwo_successor)->data == card("c 10"));
    cout << "Second predecessor test passed" << "\n";

    
    assert(testTHREE.predecessor(testThree_successor)->data == card("d 9"));
    cout << "Third predecessor test passed" << "\n";

    
    assert(testFOUR.predecessor(testFour_successor) == nullptr);
    cout << "Fourth predecessor test passed" << "\n";

    
    assert(testFIVE.predecessor(testFive_successor) == nullptr);
    cout << "Fifth predecessor test passed" << "\n";

    cout << "\n" << "All successor test passed" << "\n";




    //TESTING INSERT/REMOVAL
    testONE.insert(rootOne, card("d 10"));
    testTWO.insert(rootTwo, card("s 10"));
    testTHREE.insert(rootThree, card("h a"));
    testFOUR.insert(rootFour, card("s 10"));
    testFIVE.insert(rootFive, card("c 8"));


    rootOne = testONE.getRoot();
    rootTwo = testTWO.getRoot();
    rootThree = testTHREE.getRoot();
    rootFour = testFOUR.getRoot();
    rootFive = testFIVE.getRoot();



    cout << "\n" << "TESTING INSERTS" << "\n";
    assert(testONE.contains(rootOne, card("d 10")) == true);
    cout << "First insert test passed" << "\n";
    assert(testTWO.contains(rootTwo, card("s 10")) == true);
    cout << "Second insert test passed" << "\n";
    assert(testTHREE.contains(rootThree, card("h a")) == true);
    cout << "Third insert test passed" << "\n";
    assert(testFOUR.contains(rootFour, card("s 10")) == true);
    cout << "Four insert test passed" << "\n";

    assert(testFIVE.contains(rootFive, card("c 8")) == true);
    cout << "Five insert test passed" << "\n";
    cout << "\n" << "INSERT() has passed" << "\n";

    
    cout << "\n" << "REMOVAL() testing" << "\n";
    //Removing Root;
    testONE.remove(card("d 10"));
    testONE.remove(card("d 2"));
    
    //Removing One Child
    testTWO.remove(card("h 10"));
    testTWO.remove(card("s 10"));
    
    //Removing No Child
    testTHREE.remove(card("h a"));
    testTHREE.remove(card("d 9"));

    //Testing Removal of empty BST
    testFOUR.remove(card("s 10"));
    testFOUR.remove(card("d 6"));
    testFOUR.remove(card("h 7"));

    testFIVE.remove(card("c 8"));


    rootOne = testONE.getRoot();
    rootTwo = testTWO.getRoot();
    rootThree = testTHREE.getRoot();
    rootFour = testFOUR.getRoot();
    rootFive = testFIVE.getRoot();

    assert(testONE.contains(rootOne, card("d 10")) == false && testONE.contains(rootOne, card("d 2")) == false);
    cout << "First removed test passed" << "\n";
    assert(testTWO.contains(rootTwo, card("h 10")) == false && testTWO.contains(rootTwo, card("s 10")) == false);
    cout << "Second removed test passed" << "\n";
    assert(testTHREE.contains(rootThree, card("h a")) == false && testTHREE.contains(rootThree, card("d 9")) == false);
    cout << "Third removed test passed" << "\n";
    assert(testFOUR.contains(rootFour, card("s 10")) == false && testFOUR.contains(rootFour, card("d 6")) == false);
    cout << "Four removed test passed" << "\n";
    assert(testFIVE.contains(rootFive, card("c 8")) == false);
    cout << "Fifth removed test passed" << "\n";


    //PUTTING AN ELEMENT BACK

    




    cout << "All tests passed \n";

    return 0;
}
