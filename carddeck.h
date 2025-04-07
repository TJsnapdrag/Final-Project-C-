
#ifndef CARDDECK_H
#define CARDDECK_H
#include <vector>
#include <string>

using namespace std;
 struct Card {
   string suit;
   string rank;
   Card(string s, string r) {
   suit =s;
   rank = r;
   }
 };

 class Deck{
   private:
     vector<Card> cards;

   public:
     Deck();
     Card dealCard();
     void shuffleDeck();
     bool isEmpty();
 };

#endif //CARDDECK_H
