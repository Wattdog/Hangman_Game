/// @file Menu.cpp
/// contains all the information required for the main menu

#include <iostream>
#include <iomanip>
#include <cstring>
#include <Windows.h>
#include "Menu.h"

int menuOptions()
{
	int optionChoice = 0; // User will enter 1, 2 or 3 to go to one of the options
						  // The user can type 4 which will enter them into debug mode

	system("CLS");

	std::cout << std::setw(20) << " - Hangman - " << std::endl;
	std::cout << std::endl;

	std::cout << std::setw(11) << "1."
		<< std::setw(6) << "Play" << std::endl;
	std::cout << std::setw(11) << "2."
		<< std::setw(13) << "How to Play" << std::endl;
	std::cout << std::setw(11) << "3."
		<< std::setw(6) << "Exit" << std::endl;

	std::cout << std::endl;

	std::cout << "Please select one of the options: ";
	std::cin >> optionChoice; // Asks the user to choose one of the options given

	return optionChoice;
}

void howToPlay()
{

	bool returnMenu = false;
	char returnMenuInput;

	// Gives the user a basic understanding of how to play Hangman
	while (returnMenu == false) // This will run until the user enters 'y' which will then return them to the menu
	{
		std::cout << std::setw(33) << " - How to Play - " << std::endl;
		std::cout << std::endl;

		std::cout << "- When you go to play the game you will be presented" << std::endl << std::setw(50) 
			<< "with four options (Easy, Medium, Hard, Animals)" << std::endl;

		std::cout << std::endl;

		std::cout << "- Each option will vary the length of the word e.g." << std::endl << std::setw(34)
			<< "Easy 3 letter words" << std::endl;

		std::cout << std::endl;

		std::cout << "- During the game the word will be hidden by this" << std::endl << std::setw(30)
			<< "symbol '*'" << std::endl;

		std::cout << std::endl;

		std::cout << "- You as the player will enter single characters," << std::endl <<
			std::setw(48) << "e.g. 'a', to see if they match the word given" << std::endl;

		std::cout << std::endl;

		std::cout << "- In addition to this you will have 6 guess to" << std::endl <<
			std::setw(50) << "guesses the hidden word. For each wrong guess one" << std::endl << std::setw(48)
			    << "will be taken away from you until it reaches 0" << std::endl;

		std::cout << std::endl;

		std::cout << "- For each correct guesses the symbol '*' will be" << std::endl << std::setw(47)
			<< "replaced with the character you have entered" << std::endl;

		std::cout << std::endl;

		std::cout << "- You win the game play guessing all the characters for" << std::endl << std::setw(55)
			<< "the word given and you lose by not guessing the word" << std::endl;


		std::cout << std::endl;
		std::cout << std::setw(45) << "Do you want to return to the menu? (Y/N): ";
		std::cin >> returnMenuInput;

		returnMenuInput = toupper(returnMenuInput);

		if (returnMenuInput == 'Y')
			returnMenu = true; // If the user enters 'y' it will return them to the main menu
		else // If the user enters anything apart from 'y' this message will appear
		{
			std::cout << std::setw(20) << "Invalid option" << std::endl;
			Sleep(2000);
			system("CLS");
		}
	}

}