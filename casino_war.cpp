#include <iostream>
#include "carddeck.h"   // Access Deck class to create a shuffled deck and deal cards
#include "player.h"     // Access Player class for tracking name and chip count

using namespace std;

//converts the string name of cards drawn into a numeric value for comparison
int getCardValue(const Card& card) {
	if (card.rank == "Ace") return 14;
	if (card.rank == "King") return 13;
	if (card.rank == "Queen") return 12;
	if (card.rank == "Jack") return 11;
	return stoi(card.rank); //remaining numbers converted to integers "7" to 7
}

//main casino war game logic
void playCasinoWar(Player &user) {

	char again = 'y'; //replay cin variable
while (again == 'y' || again == 'Y') {
	cout << "Starting Casino War..." << endl;
	Deck deck; // create a new shuffled deck for each game
	Card playerCard = deck.dealCard(); //deal one card to the player vector
	Card dealerCard = deck.dealCard(); //deal one card to dealer vector

	int wager;
	cout << "You have " << user.chips << "chips" << endl;
	cout << "Enter the amount you want to wager: " << endl;
	cin >> wager;

	//validate entered wager
	if (cin.fail() || wager <= 0 || wager > user.chips) {
		cin.clear(); // clear error state caused by invalid input
		cin.ignore(15, '\n'); // discard the invalid input
		cout << "Invalid wager. Please enter a valid positive number not greater than your chips."<< endl;
		break;
	}

	//reveal cards to player
	cout << "You draw: " << playerCard.rank << " of " << playerCard.suit << endl;
	cout << "Dealer draws: " << dealerCard.rank << " of " << dealerCard.suit << endl;

	int playerValue = getCardValue(playerCard);		//string of card in playerhand converted to an integer
	int dealerValue = getCardValue(dealerCard);		//string of card in dealerhand converted to an integer

	//compare card values and determine win/lose
	if (playerValue > dealerValue) {
		cout << "Nice! You won " << wager << " chips." << endl;
		user.chips +=wager;
	}
	else if (dealerValue > playerValue) {
		cout << "Dealer wins. " << wager << " chips." << endl;
		user.chips -= wager;
	}
	else {
		cout << "War! It's a draw!" << endl; //no chip change occurs
	}
	cout<<"Do you want to play again? Enter Y for yes or any other character for menu:" << endl;
	cin >> again;
}


}