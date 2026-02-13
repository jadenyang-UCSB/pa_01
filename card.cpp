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

card::card(){
    number = "1";
    rank = "c";
}

card::card(string cardInfo){
    rank = cardInfo[0];
    if(cardInfo.substr(2,4) == "10"){
        number = cardInfo.substr(2,4);
    }
    else{
        number = cardInfo[2];
    }
}

bool operator==(card a, card b){
    string a_number = a.number;
    string a_rank = a.rank;
    string b_number = b.number;
    string b_rank = b.rank;

    return ((a_number == b_number) && (b_rank == a_rank));
}

bool operator!=(card a, card b){
    return !(a == b);
}

bool operator<(card a, card b){
    string suits[4] = {"c","d","s","h",};
    string number[13] = {"a","2","3","4","5","6","7","8","9","10","j","q","k"};

    int indexA = 0;
    int indexB = 0;


    for(int i = 0; i < 5; i++){
        if(a.rank == suits[i]){
            indexA = i;
        }
    }
    for(int j = 0; j < 5; j++){
        if(b.rank == suits[j]){
            indexB = j;
        }
    }

    if(indexA == indexB){
        for(int k = 0; k < 13; k++){
            if(a.number == number[k]){
                indexA = k;
            }
        }
        for(int l = 0; l < 13; l++){
            if(b.number == number[l]){
                indexB = l;
            }
        }
    }

    return (indexA < indexB);
}

bool operator > (card a,card b){
    return !(a<b);
}

ostream& operator<<(ostream& os, const card& a){
    os << a.rank << " " << a.number;
    return os;
}