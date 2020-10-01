/// @file Main.cpp
/// @brief contains all the logic required for the main menu

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <cstring>
#include <time.h>
#include <cctype>
#include "Menu.h"
#include "playGame.h"

int main()
{
	srand(time(0)); // Generates a random-like number which is initialized at runtime
	
	bool exitFlag = false; /* Set to false by default to allow the do-while loop to
						   continuously run until it is set to true */

	do
	{
		int menuChoice = menuOptions();
		bool debug = false; /* If the boolean is set to true debug mode will run.
						In debug mode the player will be able to see what the word*/

		switch (menuChoice)
		{

		case 1:
			system("CLS");
			playGame(debug); // Will setup the game
			break;

		case 2:
			system("CLS");
			howToPlay(); /* Will run the howToPlay function teaching the user how to
						 play the game */
			break;

		case 3:
			system("CLS");
			std::cout << "Exiting..." << std::endl;
			Sleep(1000);
			exitFlag = true; // Will set the boolean to true and stop the do-while loop
			break;

		case 4:
			system("CLS");
			debug = true; // Will allow debug mode to run
			std::cout << std::setw(25) << "Entering Debug Mode..."
				<< std::endl;
			Sleep(2000);
			playGame(debug); // Will setup the game in debug mode
			break;

		default:
			system("CLS");
			std::cout << "This is an invalid option!" << std::endl;
			Sleep(1000);
			break;

		}

	} while (exitFlag == false);

	std::cin.get();
	return 0;
}