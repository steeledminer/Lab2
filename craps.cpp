#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

/*
This is a program to simulate craps, created by Andrew Hingst (5043535).
Player enters a bid within their range (0 to their total pot).
If they run out of cash they lose, but otherwise they can continue to play until they choose to cash out.
*/

int die();
bool playGame();
int roll();

int main() {
	char ans; //initialize variables
	bool done = false;
	bool win = false;
	bool valid = false;
	int pot = 50;
	int bid = 10;

	srand(time(NULL)); //seed the RNG

	while (! done) {
		cout << "Current Cash : " << pot << "\n"; //Show Cash
		cout << "Enter Bid : ";
		cin >> bid;
		valid = false;
		while (! valid) { 			//Get Valid Bid
			if (bid <= 0 || bid > pot){
				cout << "Invalid Bid, enter again: ";
				cin >> bid;
			} else valid = true;
		}
		cout << "\n";

		win = playGame(); 			//Run the game, get the win or loss result
		if (win) pot = pot + bid; 		//Win or remove bid
			else pot = pot - bid;
		cout << "Cash : " << pot << "\n";
		if (pot <= 0){ 				//Check if you lose
			cout << "Game Over. \n";
			done = true;
		}else{					//If still with cash, proceed to keep playing at user choice
			cout << " Play Again (y/n) ? ";
			cin >> ans;
			if ( ans == 'y' || ans == 'Y') done = false;
				else{
				cout << "Your winnings are : " << pot << "\n"; //Cash out
				done = true;
			}
		}
	}
	return 0;
}

bool playGame(){ 
	int total = roll(); //get roll
	bool win = false;
	switch(total){ //check the first roll
		case 2 : 
			win = false;
			break;
			
		case 3 : 
			win = false;
			break;

		case 7 : 
			win = true;
			break;

		case 11 :
			win = true;
			break;

		case 12 : 
			win = false;
			break;

		default :  //if the first roll isn't a win or loss, set the point
			int point = total;
			bool done = false;

			cout << "Point is " << point << "\n";
			while (! done) { //begin rolling until point or 7 is rolled.
				total = roll();
				if (total == 7) {
					win = false;
					done = true;
				} else if (total == point) {
					win = true;
					done = true;
				} else done = false;
			}
			break;
		
	}
		
	if (win == true) cout << "Player Wins! \n"; //output result
	else cout << "Player Loses! \n";
	
	return win; //return result;		
}

int roll(){
	int a = die(); //get 2 rolls
	int b = die();
	int total = a + b;
	cout << "player rolled " << a << " + " << b << " = " << total << "\n"; //output roll
	return total;
}

int die(){
	
	return ((rand()%6) + 1); //get dice value
}
