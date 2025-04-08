#include <iostream>
#include <fstream>

#include "games.h"
#include "player.h"

using namespace std;

int main() {
  string typedName;
  cout << "Hello! Can you tell me your name?" << endl;
  cin >> typedName;
//dynamically allocate memory for a new Player object using a pointer
  auto* user = new Player; //auto protects memory from accidental duplicates
  user->name = typedName;  //entered name = 'name' field of the Player object
  user->chips = 1000;  //initial chip count




  int choice; //menu selection input

  bool play = true;       //Game loop control

  while (play) {
    cout << "Welcome to my Casino! Would you like to play a game?" << endl;
    cout<<"1. Blackjack (21)"<<endl;
    cout<<"2. Casino War"<<endl;
    cout<<"3. No (Quit)"<<endl;
    cout<< "Enter a 1, 2, or 3 and choose:"<<endl;
    cin>>choice;

    if (!(choice >= 1 && choice <= 3)) {  //validates against nonscripted inputs
      cin.clear();
      cin.ignore(1000, '\n');
      continue;
    }


    switch(choice) {
      case 1:
        playBlackjack(*user); //pointer from player struct for chip variable
      break;
      case 2:
        playCasinoWar(*user);
      break;
      case 3:
        play = false;
      break;
      default: cout << "Please choose 1, 2, or 3." << endl;
    }
  }

    ofstream outFile("casino_results.txt", ios::trunc); //text file is overwritten with current player info
    if (outFile.is_open()) {
      outFile << user->name << " | " << user->chips << endl;
      outFile.close();
    }
  cout << "Thank you for playing today "<< user->name << "! Come back soon to use " << user->chips <<  " chips." <<endl;

  delete user; //keeps memory stable for the next iteration


return 0;
  }




