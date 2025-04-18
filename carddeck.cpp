#include "carddeck.h"   //declares the Deck and Card structures
#include <algorithm>
#include <random>

using namespace std;

//52 card constructor function
Deck::Deck(){ //create 4 suits and 13 ranks as strings
  const char* suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
  const char* ranks[] = { "2", "3", "4", "5", "6", "7", "8",
                                    "9", "10", "Jack", "Queen", "King", "Ace"};
    //nested loop iterates suits before looping a rank to every suit
  for (int suitcard = 0; suitcard < 4; suitcard++) {
    for (int rankcard = 0; rankcard < 13; rankcard++) {
      //adds a card from loops to a deck vector
      cards.emplace_back(suits[suitcard], ranks[rankcard]);
    }

  }
shuffleDeck(); //randomize deck order on every creation

}

//shuffle function toward created deck class objects
void Deck::shuffleDeck(){     //random device makes the returned value less predictable
  shuffle(cards.begin(), cards.end(), random_device());
}

//dealing top card from the deck
Card Deck::dealCard(){
  Card topCard = cards.back(); //get last vector card or the top deck value
  cards.pop_back();     //remove that card from the deck
  return topCard;  //return the dealt card to what called it

}