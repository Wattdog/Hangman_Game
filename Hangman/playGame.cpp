/// @file playGame.cpp
/// @brief contains all the logic required for the game

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <Windows.h>
#include <time.h>
#include "playGame.h"

int difficultyOption()
{
	int difficultyChoice = 0; // User will enter 1, 2 or 3 to go to one of the options

	system("CLS");

	std::cout << std::setw(20) << " - Hangman - " << std::endl;
	std::cout << std::endl;

	std::cout << std::setw(11) << "1."
		<< std::setw(6) << "Easy" << std::endl;
	std::cout << std::setw(11) << "2."
		<< std::setw(8) << "Medium" << std::endl;
	std::cout << std::setw(11) << "3."
		<< std::setw(6) << "Hard" << std::endl;
	std::cout << std::setw(11) << "4."
		<< std::setw(9) << "Animals" << std::endl;
	std::cout << std::setw(11) << "5."
		<< std::setw(7) << "Bands" << std::endl;

	std::cout << std::endl;

	std::cout << "Please select one of the options: ";
	std::cin >> difficultyChoice;

	return difficultyChoice;
}

void playGame(bool _debugMode)
{
	hangmanGame game;

	bool setupGame = false;
	int difficultyChoice = difficultyOption();
	int i = rand() % 30; // generates a number between the amount of words that are in the listOfWords

	// Libary of wors for the easy difficulty
	char easyWords[][10] = { "cat", "dog", "bet", "hut", "rib", "act", "ear", "rub", "cut", "pet",
							 "cut", "air", "run", "key", "jar", "zoo", "rod", "car", "pan", "sin",
							 "ray", "gun", "ant", "lay", "use", "sky", "lab", "dip", "mop", "cot" };

	// Libary of wors for the medium difficulty
	char mediumWords[][10] = { "take", "cuff", "dice", "crop", "help", "drip", "dish", "wipe", "idol",
							   "prop", "rave", "bird", "wake", "bank", "gold", "rust", "size", "rice",
							   "cook", "seek", "hook", "pump", "stow", "bash", "unit", "list", "back",
							   "junk", "half", "lump" };

	// Libary of wors for the hard difficulty
	char hardWords[][10] = { "assign", "hammer", "hybrid", "record", "wisdom", "stride",
							 "gunner", "copper", "sudden", "inform", "sleigh", "planet",
							 "spiral", "refuge", "Number", "Silent", "attain", "alight",
							 "clever", "grower", "ravage", "design", "secret", "depend",
							 "coming", "should", "logger", "scribe", "failed", "single" };
	
	// Libary of wors for the animals theme
	char animals[][10] = { "lion", "parrot", "monkey", "zebra", "panda", "koala", 
						   "cow", "hamster", "bull", "dolphin", "tiger",
						   "rhino", "camel", "rat", "bear", "beaver", "owl",
						   "rabbit", "pig", "sheep", "horse", "whale",
						   "penguin", "racoon", "tuna", "badger",
						   "donkey", "deer", "hedgehog", "kangroo"};

	char bands[][10] = { "queen", "kiss", "gorillaz", "oasis", "avicii", "nirvana",
						"coldplay", "shinedown", "skillet", "beartooth", "rush" 
						"blur", "muse", "eminem", "starset",
						"incubus", "pendulum", "slipknot", "mgmt", "grandson",
						"kasabian", "aerosmith", "red", "metallica",
						"radiohead", "disturbed", "ministry", "rammstein",
						"slayer", "motorhead", "abba" };

	do
	{
		switch (difficultyChoice)
		{
		/* Copies over each indivdual word from the libary
		to the array that has been delcared in the hangman
		structure */
		case 1:
			std::cout << std::setw(25) << "Starting Game..."
				<< std::endl;
			randomWord(easyWords, game.m_displayWord, i); /* Will assign a random word to the m_displayWord array from the
														   easy difficulty array */
			strcpy_s(game.m_hiddenWord, 10, easyWords[i]); /* Will take the same word that has been selected from the chosen difficulty/theme
															array and copy it to the m_hiddenWord array.*/
			// Checks to see if the _debugMode has been set to true
			if (_debugMode == true)
			{
				strcpy_s(game.m_debugWord, 10, easyWords[i]);
			}
			Sleep(2000);
			system("CLS");
			setupGame = true;
			break;
		case 2:
			std::cout << std::setw(25) << "Starting Game..."
				<< std::endl;
			randomWord(mediumWords, game.m_displayWord, i); /* Will assign a random word to the m_displayWord array from the
														   medium difficulty array */
			strcpy_s(game.m_hiddenWord, 10, mediumWords[i]);
			if (_debugMode == true)
			{
				strcpy_s(game.m_debugWord, 10, mediumWords[i]);
			}
			Sleep(2000);
			system("CLS");
			setupGame = true;
			break;
		case 3:
			std::cout << std::setw(25) << "Starting Game..."
				<< std::endl;
			randomWord(hardWords, game.m_displayWord, i); /* Will assign a random word to the m_displayWord array from the
														   hard difficulty array */
			strcpy_s(game.m_hiddenWord, 10, hardWords[i]);
			if (_debugMode == true)
			{
				strcpy_s(game.m_debugWord, 10, hardWords[i]);
			}
			Sleep(2000);
			system("CLS");
			setupGame = true;
			break;
		case 4:
			std::cout << std::setw(25) << "Starting Game..."
				<< std::endl;
			randomWord(animals, game.m_displayWord, i); /* Will assign a random word to the m_displayWord array from the
														   animals theme array */
			strcpy_s(game.m_hiddenWord, 10, animals[i]);
			if (_debugMode == true)
			{
				strcpy_s(game.m_debugWord, 10, animals[i]);
			}
			Sleep(2000);
			system("CLS");
			setupGame = true;
			break;
		case 5:
			std::cout << std::setw(25) << "Starting Game..."
				<< std::endl;
			randomWord(bands, game.m_displayWord, i); /* Will assign a random word to the m_displayWord array from the
														   animals theme array */
			strcpy_s(game.m_hiddenWord, 10, bands[i]);
			if (_debugMode == true)
			{
				strcpy_s(game.m_debugWord, 10, bands[i]);
			}
			Sleep(2000);
			system("CLS");
			setupGame = true;
			break;
		default:
			system("CLS");
			std::cout << "This is an invalid option!" << std::endl;
			Sleep(1000);
			break;
		}


	} while (setupGame == false);

	int guesses = 6; // Number of guesses
	bool gameState = false; /* Will be set false to allow the game to play, but will be to true
							once the game is over */
	int j = 0; // Used to assign the letters entered by the user to the correct index position in the letters array
	bool test = false; // Will test to see if the letter has already been used
	char input; // Will take the letter entered by the user to see if they want to play again
	bool *bptr = nullptr; // Used in the test to see if the letter has already been used
	char letterGuess = 0; /* Takes the character used by the player and is run through multiple functions e.g.
					      guessWord */
	char letters[26] = { 0 }; // Holds all of the letters entered by the user

	int length = strlen(game.m_hiddenWord); // Gets the length of the word

	bptr = new bool[26]; // Assign a dynamic array to the boolean pointer

	// Assigns each value in the dynamic array to false
	for (int i = 0; i < 26; ++i)
	{
		*(bptr + i) = false;
	}

	// Loop will run while the gameState boolean = false and the guesses is greater than zero
	while (gameState == false && guesses > 0)
	{
		if (strcmp(game.m_displayWord, game.m_hiddenWord) != 0) /* Compares the two array's to see
																if they don't match. This will
																then run the game*/ 
		{
			drawHangMan(guesses); // draws hangman depending on the number of remaining guesses
			std::cout << std::setw(16) << game.m_displayWord << std::endl;

			// If the _debugMode is set to true it will display the word that has been selected
			if (_debugMode == true)
			{
				std::cout << std::setw(16) << game.m_debugWord << std::endl;
			}

			std::cout << std::setw(15) << letters << std::endl; // Displays all of the characters used

			std::cout << std::setw(22) << "Enter a character: "; /* player will enter a character which will then
																 be checked by the guessWord function*/
			std::cin >> letterGuess;

			// Assigns the letter entered by the user to the letters array starting at index position 0
			for (int i = 0; i < 26; ++i)
			{
				letters[j] = letterGuess;
			}

			letterGuess = tolower(letterGuess); // Will change the letter from uppercase to lowercase

			guessWord(game.m_hiddenWord, game.m_displayWord, guesses, length, letterGuess, test, bptr); /* checks each of the individual characters
																				            in the word to see if they match the 
																				            character entered */

			char *cptr = nullptr; /* creates a pointer to check the character entered to see if it matches with
								  any of the characters in the original word*/
			cptr = strchr(game.m_hiddenWord, letterGuess);

			if (cptr == 0) /* strchr will return 0 if the character entered doesn't match any of the
						   characters from the original word*/
			{
				guesses--; // takes one away from the guesses if the character doesn't match
			}

			if (guesses == 0) /* This will only run if the player doesn't guess the
							  correct word with the guesses given*/
			{
				system("CLS");
				drawHangMan(guesses);
				std::cout << std::setw(16) << game.m_displayWord << std::endl;
				std::cout << "\t   " << letters << std::endl;
				std::cout << std::setw(18) << "You Lose!" << std::endl;
				std::cout << std::setw(17) << "The word was: " << game.m_hiddenWord
					<< std::endl;
				Sleep(2000);
			}

			system("CLS");
		}
		else
		{
			drawHangMan(guesses); // draws hangman depending on the number of remaining guesses
			std::cout << std::setw(16) << game.m_displayWord << std::endl;
			std::cout << std::setw(15) << letters << std::endl;
			std::cout << std::endl;
			if (strcmp(game.m_displayWord, game.m_hiddenWord) == 0) /* Will only show if the user
																	has guessed the correct word*/
			{
				std::cout << std::setw(18) << "You Win!" << std::endl;
				Sleep(2000);
				gameState = true;
				system("CLS");
			}
			
		}
		j++;
	}

	// Will ask the user if they want to play again
	std::cout << "Do you want to play again? (Y/N): ";
	std::cin >> input;
	input = toupper(input);
	if (input == 'Y')
	{
		playGame(_debugMode);
	}

	delete[] bptr;
}

void drawHangMan(int _lives)
{
	// Will draw the hangman depending on how many guesses are remaining
	if (_lives == 6)
	{
		std::cout << std::setw(22) << "Guesses Remaining: " <<
			_lives << std::endl;
		std::cout << std::endl;

		std::cout << std::setw(20) << "+--------------" << std::endl;
		std::cout << std::setw(6) << "|" << std::setw(8) << "|" << std::endl;

		for (int i = 0; i < 7; ++i)
		{
			std::cout << std::setw(6) << "|" << std::endl;
		}

		std::cout << std::setw(25) << "---+-------------------" << std::endl;
	}

	if (_lives == 5)
	{
		std::cout << std::setw(22) << "Guesses Remaining: " <<
			_lives << std::endl;
		std::cout << std::endl;

		std::cout << std::setw(20) << "+--------------" << std::endl;
		std::cout << std::setw(6) << "|" << std::setw(8) << "|" << std::endl;
		std::cout << std::setw(6) << "|" << std::setw(8) << "O" << std::endl;

		for (int i = 0; i < 5; ++i)
		{
			std::cout << std::setw(6) << "|" << std::endl;
		}

		std::cout << std::setw(25) << "---+-------------------" << std::endl;
	}

	if (_lives == 4)
	{
		std::cout << std::setw(22) << "Guesses Remaining: " <<
			_lives << std::endl;
		std::cout << std::endl;

		std::cout << std::setw(20) << "+--------------" << std::endl;
		std::cout << std::setw(6) << "|" << std::setw(8) << "|" << std::endl;
		std::cout << std::setw(6) << "|" << std::setw(8) << "O" << std::endl;
		std::cout << std::setw(6) << "|" << std::setw(8) << "|" << std::endl;

		for (int i = 0; i < 4; ++i)
		{
			std::cout << std::setw(6) << "|" << std::endl;
		}

		std::cout << std::setw(25) << "---+-------------------" << std::endl;
	}

	if (_lives == 3)
	{
		std::cout << std::setw(22) << "Guesses Remaining: " <<
			_lives << std::endl;
		std::cout << std::endl;

		std::cout << std::setw(20) << "+--------------" << std::endl;
		std::cout << std::setw(6) << "|" << std::setw(8) << "|" << std::endl;
		std::cout << std::setw(6) << "|" << std::setw(8) << "O" << std::endl;
		std::cout << std::setw(6) << "|" << std::setw(8) << "/|" << std::endl;

		for (int i = 0; i < 4; ++i)
		{
			std::cout << std::setw(6) << "|" << std::endl;
		}

		std::cout << std::setw(25) << "---+-------------------" << std::endl;
	}

	if (_lives == 2)
	{
		std::cout << std::setw(22) << "Guesses Remaining: " <<
			_lives << std::endl;
		std::cout << std::endl;

		std::cout << std::setw(20) << "+--------------" << std::endl;
		std::cout << std::setw(6) << "|" << std::setw(8) << "|" << std::endl;
		std::cout << std::setw(6) << "|" << std::setw(8) << "O" << std::endl;
		std::cout << std::setw(6) << "|" << std::setw(9) << "/|\\" << std::endl;

		for (int i = 0; i < 4; ++i)
		{
			std::cout << std::setw(6) << "|" << std::endl;
		}

		std::cout << std::setw(25) << "---+-------------------" << std::endl;
	}

	if (_lives == 1)
	{
		std::cout << std::setw(22) << "Guesses Remaining: " <<
			_lives << std::endl;
		std::cout << std::endl;

		std::cout << std::setw(20) << "+--------------" << std::endl;
		std::cout << std::setw(6) << "|" << std::setw(8) << "|" << std::endl;
		std::cout << std::setw(6) << "|" << std::setw(8) << "O" << std::endl;
		std::cout << std::setw(6) << "|" << std::setw(9) << "/|\\" << std::endl;
		std::cout << std::setw(6) << "|" << std::setw(7) << "/" << std::endl;

		for (int i = 0; i < 3; ++i)
		{
			std::cout << std::setw(6) << "|" << std::endl;
		}

		std::cout << std::setw(25) << "---+-------------------" << std::endl;
	}

	if (_lives == 0)
	{
		std::cout << std::setw(22) << "Guesses Remaining: " <<
			_lives << std::endl;
		std::cout << std::endl;

		std::cout << std::setw(20) << "+--------------" << std::endl;
		std::cout << std::setw(6) << "|" << std::setw(8) << "|" << std::endl;
		std::cout << std::setw(6) << "|" << std::setw(8) << "O" << std::endl;
		std::cout << std::setw(6) << "|" << std::setw(9) << "/|\\" << std::endl;
		std::cout << std::setw(6) << "|" << std::setw(9) << "/ \\" << std::endl;

		for (int i = 0; i < 3; ++i)
		{
			std::cout << std::setw(6) << "|" << std::endl;
		}

		std::cout << std::setw(25) << "---+-------------------" << std::endl;
	}

}

char *randomWord(char _randWord[][10], char _hiddenWord[], int _num)
{
	// Selects a random word the m_listofWords array
	strcpy_s(_hiddenWord, 10, _randWord[_num]);
	int len = strlen(_hiddenWord); // gets length of the random word

	hideWord(_hiddenWord, len);
	return _hiddenWord;
}

void hideWord(char _hide[], int _len)
{
	for (int i = 0; i < _len; ++i)
	{
		_hide[i] = '*'; // replaces all of the characters in the word with *
	}
}

void guessWord(char _word[], char _displayWord[], int _lives, int _length, char _letterGuessed, bool _test, bool *_bptr)
{
	// Checks to see if the character entered by the user matches with the selected word
	if (_lives >= 0)
	{
		for (int i = 0; i < _length; ++i)
		{
			if (_word[i] == _letterGuessed)
			{
				_displayWord[i] = _letterGuessed;
			}
		}
		// Will test to see if the letter has already been used
		_test = testUsed(_letterGuessed, _bptr);
		if (_test == false)
		{
			std::cout << std::setw(18) << "Already used" << std::endl;
			Sleep(2000);
		}
	}
}

bool testUsed(unsigned char _letter, bool *_ptr)
{
	// Tests to see if the character has already been used
	bool test = false;

	// Takes away ascii value of a away from the letter entered
	_letter = _letter - 'a';

	// Checks to see if the letter entered is false (not been used yet)
	if (*(_ptr + _letter) == false)
	{
		*(_ptr + _letter) = true;
		test = true;
	}
	// If the letter has already been used the test will return false
	else
	{
		test = false;
	}
	return test;
}