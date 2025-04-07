
#ifndef CARDDECK_H
#define CARDDECK_H
#include <vector>
#include <string>

using namespace std;
 struct Card {  //represents one card object in the deck
   string suit;
   string rank;
   Card(string s, string r) {   //constructior for the card's suit and rank nomination
   suit =s;
   rank = r;
   }
 };

 class Deck{
   private:
     vector<Card> cards; //holds all 52 cards in Deck

   public:
     Deck();  //constructor for initializing and shuffleing
     Card dealCard(); //administers topcard to dealer or playerhand
     void shuffleDeck();  //randomly shifts card order

 };

#endif //CARDDECK_H
