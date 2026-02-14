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
        testONE.insert(testOne_cards[one]);
    }

    for(int two = 0; two < sizeTwo; two++){
        testTWO.insert(testTwo_cards[two]);
    }

    for(int three = 0; three < sizeThree; three++){
        testTHREE.insert(testThree_cards[three]);
    }

    for(int four = 0; four < sizeFour; four++){
        testFOUR.insert(testFour_cards[four]);
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
    assert(testONE.contains(card("s 10")) == true);
    cout << "Second contains test passed" << "\n";
    assert(testTWO.contains(card("h 10")) == true);
    cout << "Third contains test passed" << "\n";
    assert(testTHREE.contains(card("s 1")) == true);
    cout << "Four contains test passed" << "\n";
    assert(testFOUR.contains(card("d a")) == false);
    cout << "Five contains test passed" << "\n";
    assert(testFIVE.contains(card("a a")) == false);
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

    cout << "\n" << "All predecessor test passed" << "\n";




    //TESTING INSERT/REMOVAL
    testONE.insert(card("d 10"));
    testTWO.insert(card("s 10"));
    testTHREE.insert(card("h a"));
    testFOUR.insert(card("s 10"));
    testFIVE.insert(card("c 8"));


    rootOne = testONE.getRoot();
    rootTwo = testTWO.getRoot();
    rootThree = testTHREE.getRoot();
    rootFour = testFOUR.getRoot();
    rootFive = testFIVE.getRoot();



    cout << "\n" << "TESTING INSERTS" << "\n";
    assert(testONE.contains(card("d 10")) == true);
    cout << "First insert test passed" << "\n";
    assert(testTWO.contains(card("s 10")) == true);
    cout << "Second insert test passed" << "\n";
    assert(testTHREE.contains(card("h a")) == true);
    cout << "Third insert test passed" << "\n";
    assert(testFOUR.contains(card("s 10")) == true);
    cout << "Fourth insert test passed" << "\n";

    assert(testFIVE.contains(card("c 8")) == true);
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

    assert(testONE.contains(card("d 10")) == false && testONE.contains(card("d 2")) == false);
    cout << "First removed test passed" << "\n";
    assert(testTWO.contains(card("h 10")) == false && testTWO.contains(card("s 10")) == false);
    cout << "Second removed test passed" << "\n";
    assert(testTHREE.contains(card("h a")) == false && testTHREE.contains(card("d 9")) == false);
    cout << "Third removed test passed" << "\n";
    assert(testFOUR.contains(card("s 10")) == false && testFOUR.contains(card("d 6")) == false);
    cout << "Four removed test passed" << "\n";
    assert(testFIVE.contains(card("c 8")) == false);
    cout << "Fifth removed test passed" << "\n";


    //PUTTING AN ELEMENT BACK

    //TESTING ITERATOR SECTION
    Iterator* testFIVE_BEGIN = testFIVE.begin();
    Iterator* testFIVE_END = testFIVE.end();

    Iterator* testFIVE_RBEGIN = testFIVE.rbegin();
    Iterator* testFIVE_REND = testFIVE.rend();

    cout << "\n TESTING EQUALITY ON EMPTY TREE \n";

    assert(*testFIVE_BEGIN == *testFIVE_END);
    cout << ".begin() and .end() passed" << "\n";
    assert(*testFIVE_RBEGIN == *testFIVE_REND);
    cout << ".rbegin() and .rend() passed" << "\n";
    cout << "\n";

    cout << "TESTING ON EQUALITY \n";
    Iterator* testONE_BEGIN = testONE.begin();
    Iterator* testTWO_BEGIN = testONE.begin();

    Iterator* testONE_RBEGIN = testONE.rbegin();

    assert(*testONE_BEGIN == *testTWO_BEGIN);
    cout << "EQUALITY PASSED" << "\n";

    assert(*testONE_BEGIN != *testONE_RBEGIN);
    cout << "NOT EQUAL PASSED" << "\n";

    cout << "\n";

    cout << "EQUALITY PASSED" << "\n";

    cout << "\n";

    cout << "TESTING -- ON TREE" << "\n";
    while(testONE_RBEGIN && testONE_RBEGIN->getNode()){
        Node* previous = (testONE_RBEGIN->getNode());
        --(*testONE_RBEGIN);
        if(testONE_RBEGIN->getNode() == nullptr){
            cout << "\n";
            cout << "STOP IT NOW";
            cout << "\n";
        }
        else{
            cout << "Previously this: " << previous->data << ". Now, " << testONE_RBEGIN->getNode()->data << "\n";
            assert(previous->data == testONE_RBEGIN->getbstClass()->successor(testONE_RBEGIN->getNode())->data);
        }
    }
    cout << "\n";
    cout << "PASSED -- \n";

    cout << "\n";
    cout << "TESTING ++ ON TREE" << "\n";

    while(testONE_BEGIN && testONE_BEGIN->getNode()){
        Node* previous = (testONE_BEGIN->getNode());
        ++(*testONE_BEGIN);
        if(testONE_BEGIN->getNode() == nullptr){
            cout << "STOP IT NOW";
            cout << "\n";
        }
        else{
            cout << "Previously this: " << previous->data << ". Now, " << testONE_BEGIN->getNode()->data << "\n";
            assert(previous->data == testONE_BEGIN->getbstClass()->predecessor(testONE_BEGIN->getNode())->data);
        }
    }
    cout << "PASSED ++" << "\n";

    cout << "\n";
    cout << "TESTING SAFE BEHAVIOR ++" << "\n";

    cardBST t;
    auto e = t.end();     // node == nullptr
    ++(*e);               // should not crash
    ++(*e);               // still should not crash
    assert(e->getNode() == nullptr);
    cout << "Passed for empty ++" << "\n";

    e = t.rend();     // node == nullptr
    --(*e);               // should not crash
    --(*e);               // still should not crash
    assert(e->getNode() == nullptr);
    cout << "Passed for empty --" << "\n";



    cout << "TESTING PLAYGAME RIGHT NOW";


    //TESTING PLAYGAME
    vector<card> alice_testOne = {
        card("c a"),
        card("c 7"),
        card("d 3"),
        card("d q"),
        card("s 5"),
        card("s j"),
        card("h 2"),
        card("h 9"),
        card("h k")
    };

    vector<card> bob_testOne = {
        card("c 4"),
        card("c 7"),
        card("d 3"),
        card("d 10"),
        card("s j"),
        card("s a"),
        card("h 6"),
        card("h 9"),
        card("h q")
    };

    cardBST normal_one;
    cardBST normal_two;
    for(int insert_Alice = 0; insert_Alice < (int)alice_testOne.size(); insert_Alice++){
        normal_one.insert(alice_testOne[insert_Alice]);
    }

    for(int insert_Bob = 0; insert_Bob < (int)alice_testOne.size(); insert_Bob++){
        normal_two.insert(bob_testOne[insert_Bob]);
    }

    playGame(normal_one,normal_two);

    auto normalstart = *normal_one.begin();
    auto normalend = *normal_one.end();

    while(normalstart != normalend){
        assert(!(normal_two.contains(*normalstart)));
        cout << "Making sure no duplicates" << "\n";
        ++normalstart;
    }
    cout << "PASSED TEST ONE" << "\n";
    cout << "\n";
    

    // delete &normalstart;
    // delete &normalend;

    // cout << "Continue to test two EMPTY HAND" << "\n";
    // cout << "\n";

    // cardBST empty_one;
    // cardBST empty_two;

    // alice_testOne = {
    //     card("c a"),
    //     card("c 7"),
    //     card("d 3"),
    //     card("d q"),
    //     card("s 5"),
    //     card("s j"),
    //     card("h 2"),
    //     card("h 9"),
    //     card("h k")
    // };

    // bob_testOne = {};
    // for(int insert_Alice = 0; insert_Alice < (int)alice_testOne.size(); insert_Alice++){
    //     empty_one.insert(alice_testOne[insert_Alice]);
    // }

    // playGame(empty_one,empty_two);

    // for(int nullCheck = 0; nullCheck < alice_testOne.size(); nullCheck++){
    //     assert(empty_one.contains(alice_testOne[nullCheck]));
    // }
    // cout << "\n";
    // cout << "All tests passed \n";
    // return 0;
    }
