// Skynet HK-Aerial.cpp : Defines the entry point for the console application.
// 03 Assignment: Skynet HK-Aerial
// Write a program in C++ for the Skynet HK - Aerial
// You should initialize a grid search of 8x8.
// On each run, your program should choose a random numbered square on the grid numbered 1 - 64 to indicate where the enemy is located.
// The enemy does not move in this simulation.
// This program should be able to search for ground based enemies faster then when in the current linear search HK mode, however, you do not need to code in this comparison.
// This program is for it's internal AI only and does not require human other other AI players.
// This program should keep track of each turn and display this.
// This program should use an unpredictable search pattern to the human on the ground.
// The AI should used a Binary Search Pattern.
// This program should loop unitl the Grid that the enemy is on is found by the Skynet HK - Aerial.At that point the found and engaging enemy status is displayed along with other information such as how long it took to find them by showing how many grids the HK searched before finding the enemy, what where the cordinates of the grids the HK looked at, and how large the search grid was.
// This code will be upgraded often to stay ahead of the enemy.Be sure to comment each line of code except cout statements, write very readable code using good coding standards.
// The Grid does not need to be displayed.
// Put this project into your GitHub and take a screenshot of it.


// Standard Input / Output Streams Libraries
#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Std stands for standard library
using namespace std;

//The program always start at the main function
//This also applies to C#, Java, and other languages
//The int before the main stands for integer
//Integer is the return type
//The end of the main function is return 0;
//0 is an integer, that data type must match
//If you see the void main () , you will only see a return.
int main()
{
	srand(static_cast<unsigned int>(time(0)));

	//Integers
	int enemyLocation = rand() % 100 + 1;
	int tries = 0;
	int binaryPrediction;
	int searchGridHighNumber = 64;
	int searchGridLowNumber = 1;

	//Header
	cout << "\8X8 Grid Enemy Search \n\n";
	do
	{

		/*cout << "Enter a guess: ";
		cin >> guess;*/
		// Algorithm code to use for our binary search
		binaryPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
		++tries;

		if (binaryPrediction > enemyLocation)
		// Cout for number guess being too high
		{
			cout << binaryPrediction << " is too high, enemy location is at " << enemyLocation << endl;
			cout << "Resetting search grid high number from " << searchGridHighNumber;
			searchGridHighNumber = binaryPrediction;
			cout << " to " << searchGridHighNumber << endl;
		}
		else if (binaryPrediction < enemyLocation)
		// Cout for number guess being too low
		{
			cout << binaryPrediction << " is too low, enemy location is at " << enemyLocation << endl;
			cout << "Resetting search grid low number from " << searchGridLowNumber;
			searchGridLowNumber = binaryPrediction;
			cout << " to " << searchGridLowNumber << endl;
		}
		else if (binaryPrediction == enemyLocation)
		// Cout for location found
		{
			cout << "Found location! Accomplished in " << tries << " attempts\n";
		}
		else
		// Cout for error
		{
			cout << "\nError, something went wrong!" << endl;
		}
	} while (binaryPrediction != enemyLocation);

	// Stops debugger from closing
	system("pause");

	return 0;
}

