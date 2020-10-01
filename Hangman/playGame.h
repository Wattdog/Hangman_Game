/// \file playGame.h
/// \brief contains the initiliasation of the functions for the playGame.cpp file
/// \author Aaron Harrison-Watt

#pragma once
#ifndef _PLAY_GAME_H_

struct hangmanGame
{
	char m_displayWord[10];
	char m_hiddenWord[10];
	char m_debugWord[10];
};

void drawHangMan(int _lives);
char *randomWord(char _randWord[][10], char _hiddenWord[], int _num);
void hideWord(char _hide[], int _len);
void guessWord(char _word[], char _displayWord[], int _lives, int _length, char _letterGuessed, bool _test, bool *_bptr);
bool testUsed(unsigned char _letter, bool *_ptr);
int difficultyOption();
void playGame(bool _debugMode);

#endif // !_PLAY_GAME_H_