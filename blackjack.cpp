#include <iostream>
#include <vector>
#include "carddeck.h" // Accesses the Deck class and Card structure for card dealing and shuffling
#include "player.h"   // Accesses Player class for chip management and user information

using namespace std;

//function that converts the string name of a card to a usable number
int getBlackValue(const Card& card) {      //accesses all cards in a vector of cards
	if (card.rank == "Ace") return 11; //returns 11 originally, expanded later
	if (card.rank == "King" || card.rank == "Queen" || card.rank == "Jack") return 10; //all face cards are 10
	return stoi(card.rank); //the rest are converted from "2" or "5" -> 2 or 5


}

//calculates card total from hand vector, also checks for ace changes
int calculateTotal(vector<Card>& hand) {
	int total = 0, aces = 0; //initialized hand value / ace count to be zero
	for (auto& card : hand) {  //loops through each object present in a hand
		int value = getBlackValue(card);  //uses stoi config to get int value
		total += value;				//add each value to a total
		if (card.rank == "Ace") aces++;  //check for aces
}
	while (total > 21 && aces > 0) {   //if there are aces and player busted
		total -= 10;		//value from 11 to 1
		aces --;		//stops when runs out of aces
}
	return total;   //final hand value
}

//prints the cards in the players hand   (later does dealer as well)
void showHand(const vector<Card>& hand) {
	//loop through all cards in provided hand
	for (auto& card : hand) {
		cout << card.rank << " of " << card.suit << ", ";
  }
	cout << endl;
}


void playBlackjack(Player &user) {
	//int chips = user.getChips();
	char playAgain = 'y';
	while (playAgain == 'y' || playAgain == 'Y') {
		cout << "Starting Blackjack..." << endl;

		Deck deck;    //calls to deck in carddeck
		int wager = 0;
		cout << "You have " << user.chips << " chips. " << endl;
		cout << "Enter your chip wager: "<< endl;
		cin >> wager;
		if (cin.fail() || wager <= 0 || wager > user.chips) {
			cin.clear(); // clear error state caused by invalid input
			cin.ignore(15, '\n'); // discard the invalid input
			cout << "Invalid wager. Please enter a valid positive number not greater than your chips."<< endl;
			break;
		}

		vector<Card> playerHand, dealerHand;   //initialized a hand vector for player and dealer

		//deals the starting cards to both the player and dealer
		playerHand.push_back(deck.dealCard());
		dealerHand.push_back(deck.dealCard());
		playerHand.push_back(deck.dealCard()); //formated to increase fair output
		dealerHand.push_back(deck.dealCard());

		//reads the card ranks and suits to the player from hand vector
		cout << " Your hand is: "; showHand(playerHand);
		cout << " Dealer reveals: "; showHand(dealerHand);
		//does the same for the dealer hand vector

		//actual gameplay for player
		char choice;
		bool keepPlaying = true;

		while (keepPlaying && calculateTotal(playerHand) < 21) {	//if the player exceeds 21 or chooses to stand, the
			cout << "Hit (H) or Stand (S)? ";						//dealer's draw scenario begins
			cin >> choice;

			if (choice == 'H' || choice == 'h') {
				playerHand.push_back(deck.dealCard());	//takes top card from shuffled deck vector for player hand vector
				cout << "Your hand is "; showHand(playerHand);
			} else  if (choice == 'S' || choice == 's') {
				keepPlaying = false;	//ends current loop and starts dealer draw loop
			} else {
				cin.clear();
				cin.ignore(15, '\n');
				cout << "Sorry, please enter a valid choice." << endl;
			}
		}

		int playerTotal = calculateTotal(playerHand);	//adds the card int values together
		if (playerTotal > 21) {				//if the player busts (exceeds 21) they lose prematurely
			cout << "BUST! Sorry, you lost " << wager << " chips." << endl;
			user.chips -= wager;
			return;
		}

		cout << "Dealer's hand is: ";
		showHand(dealerHand);
		while (calculateTotal(dealerHand) < 17) {  //dealer will draw until its hand is >17
			dealerHand.push_back(deck.dealCard());
			cout << "Dealer draws: " << dealerHand.back().rank << " of " << dealerHand.back().suit << endl;
		}

		int dealerTotal = calculateTotal(dealerHand); //assigns int variable to the calculated hand total
		cout << "Dealer's total is: " << dealerTotal << endl;  //outputs the numerical worth of the dealers hand
		cout << "Your total is: " << playerTotal << endl;	//outputs the numerical worth of the players hand

		if (dealerTotal > 21 || playerTotal > dealerTotal) {	//if the dealer busts, or the player has a higher
			cout << "You win +" << wager << "chips!!!" << endl;	//score the player wins
			user.chips += wager;}
		else if (dealerTotal > playerTotal) {					//if the dealer has a higher score the player loses
			cout <<"The Dealer won this round!  -" << wager << endl;
			user.chips -= wager;}
		else {
			cout << "Wow! You tied with the dealer!" << endl;  //no chip changes
		}

		cout << "Would you like to play Blackjack again? Enter Y for yes or any other character to return to menu: " << endl;
	cin >> playAgain;
	}

}




