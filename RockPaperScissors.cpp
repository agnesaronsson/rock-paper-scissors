#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

enum selection {rock, scissors, paper} playerMove, computerMove; 

void play(int* p);

int main()
{
	char answer;
	const int PLAYERS = 2;
	int score[PLAYERS] = { '\0' };
	int* p = score;
	
	srand(time(NULL)); // seed for rand() generator to vary outcome throughout the game
	
	cout << "\nPAPER, SCISSORS, ROCK" << endl
			 << "=====================\n" << endl;
	
	do
	{	
		while(score[0] < 10 && score[1] < 10) // keep going until someone has won 10 rounds
		{ 
			int input;
			cout << "Your move (Rock=0/Scissors=1/Paper=2) : ";
			cin >> input; // read users move from input
			playerMove = (selection)input; // case input to enum variable
			
			if(playerMove == rock || playerMove == scissors || playerMove == paper) // if players move equals any of the defined enum integer constants...
			{
				play(p); // ...play round
			} 
			else
			{
				cout << "0, 1 or 2 only. Please make your move!" << endl; // otherwise error
			}
		}
		
		if(score[0] == 10) // if player won..
		{
			cout << "You won the game by ";
		}
		else // else if computer won
		{
			cout << "You lost the game by ";
		}
		
		cout << score[0] << " - " << score[1] << endl; // print result
		
		cout << "One more time (Y/N)?";
		cin >> answer;
	} while(answer == 'y' || answer == 'Y');	
		
	return 0;
}

	// function to play a round, takes parameter that is a pointer to an array of integers
void play(int* p)
{
	int r = (rand() % 3); // generates a random integer between 0 and 2
	computerMove = (selection)r; // cast int to enum variable
	
	cout << "Computer picks " << computerMove << endl;
	
	if(playerMove == computerMove) // if player and computer refer to the same integer constant..
	{
		cout << "This round was a draw" << endl;
	}
	else if(playerMove == rock && computerMove == scissors || playerMove == scissors && computerMove == paper || playerMove == paper && computerMove == rock) // else if player beats the computer..
	{
		cout << "You won this round" << endl;
		p[0]++;
	}
	else // or the other way around
	{
		cout << "Computer won this round" << endl;
		p[1]++;
	} 
	
	cout << "Current score (Player - Computer): " << p[0] << " - " << p[1] << endl; // print current score at the end of each round
}
