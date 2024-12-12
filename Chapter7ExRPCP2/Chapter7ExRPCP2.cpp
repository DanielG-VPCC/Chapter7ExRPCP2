/*
Title:Chapter 7 Rock Paper Scissors Part 2
File name:Chapter7ExRPCP2_Daniel_Geesaman.cpp
Programmer:Daniel Geesaman
Date:12/12/2024
Requirements:

Rock, Paper, Scissors Game

Write a program that lets the user play the game of Rock, Paper, Scissors against the computer. The program should work as follows:

1. When the program begins, a random number in the range of 1 through 3 is generated. If the number is 1, then the computer has chosen rock.
If the number is 2, then the computer has chosen paper. If the number is 3, then the computer has chosen scissors.
(Don’t display the computer’s choice yet.)
2. The user enters his or her choice of “rock”, “paper”, or “scissors” at the keyboard. (You can use a menu if you prefer.)
3. The computer’s choice is displayed.
4. A winner is selected according to the following rules:

  • If one player chooses rock and the other player chooses scissors, then rock wins. (The rock smashes the scissors.)

  • If one player chooses scissors and the other player chooses paper, then scissors wins. (Scissors cuts paper.)

  • If one player chooses paper and the other player chooses rock, then paper wins. (Paper wraps rock.)

  • If both players make the same choice, the game must be played again to determine the winner.

Be sure to divide the program into functions that perform each major task.


AMENDED: Chapter 7 Rock Paper Scissors Part 2.

revised on 12/12/2024

Revise the rock paper scissors using an array to store multiple games, each with the best score for the player.
*/

#include <iostream>
#include <string>
#include <random>
#include <time.h>
using namespace std;

int computerMove();
int userChoice(string names[]);
int userMove();
int resultsOfGame(int Guess, int CPU);

int main()
{
	int gamesPlayed = 0;
	string names[3] = { "Daniel", "Dave", "Mark" };
	int numberOfWins[3] = { 0, 0, 0 };
	char keepPlaying;
	int winner;

	while (true)
	{
		int userSelect = userChoice(names);

		gamesPlayed++;
		int CPU = computerMove();
		int Guess = userMove();

		while (Guess == CPU)
		{
			cout << "Tie! Must go again to determine a winner." << endl;
			CPU = computerMove();
			Guess = userMove();
		}
		winner = resultsOfGame(Guess, CPU);
		if (winner == 2)
		{
			numberOfWins[userSelect]++;
		}
		cout << endl << endl << "would you like to play again? (y or n)" << endl;
		cin >> keepPlaying;
		while (keepPlaying == 'n')
		{
			cout << "Names " << "Wins" << endl;
			for (int j = 0; j < 3; j++)
			{
				cout << " " << names[j] << " " << numberOfWins[j] << endl;
			}
			return false;
		}
	}
}

int computerMove()
{
	int CPU;
	srand(time(NULL));
	CPU = 1 + (rand() % 3);
	return CPU;
}

int userMove()
{
	int Guess;
	cout << "1. Rock" << endl << "2. Paper" << endl << "3. Scissors" << endl;
	cin >> Guess;
	while (Guess < 1 || Guess > 3)
	{
		cout << "Please make a valid selection. " << endl << endl;
		cout << "1. Rock, 2. Paper, 3. Scissors" << endl;
		cin >> Guess;
	}
	return Guess;
}

/*
1. ROCK
2. PAPER
3. SCISSORS
*/

int resultsOfGame(int Guess, int CPU)
{
	if (Guess == 1 && CPU == 2)
	{
		cout << "User played rock, computer played paper." << endl << "Computer wins!";
		return 1;
	}
	else if (Guess == 1 && CPU == 3)
	{
		cout << "User played rock, computer played scissors." << endl << "User wins!";
		return 2;
	}
	else if (Guess == 2 && CPU == 3)
	{
		cout << "User played paper, computer played scissors." << endl << "Computer wins!";
		return 1;
	}
	else if (Guess == 2 && CPU == 1)
	{
		cout << "User played paper, computer played rock." << endl << "User wins!";
		return 2;
	}
	else if (Guess == 3 && CPU == 1)
	{
		cout << "User played scissors, computer played rock." << endl << "Computer wins!";
		return 1;
	}
	else if (Guess == 3 && CPU == 2)
	{
		cout << "User played scissors, computer played paper." << endl << "User wins!";
		return 2;
	}
}

int userChoice(string names[]) 
{
	int userSelect;

	for (int j = 0; j < 3; j++)
	{
		cout << j << ". " << names[j] << endl;
	}
	cout << "which user are you? (0, 1, 2)" << endl;
	cin >> userSelect;
	while (userSelect < 0 || userSelect>2)
	{
		cout << "Please enter a valid choice" << endl;
		cin >> userSelect;
	}
	return userSelect;
}
