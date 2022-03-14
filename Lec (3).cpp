//Update: Smoother display, add loop notification
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <ctime>

using namespace std;

const int MAX_BAD_GUESSES =7;
string chooseWord();
void renderGame(string guessWord, int badGuessCount);
char readAGuess();
bool contain(string secretWord, char guess);
//new feature
bool loopGuess(string guessWord, char guess);
void notifyLoopGuess(char guess);
//
string update(string guessWord, string secretWord, char guess);

int main()
{
   srand(time(0));
   string secretWord =chooseWord();
   string guessWord =string(secretWord.size(), '-');
   int badGuessCount =0;
   do
   {
      renderGame(guessWord, badGuessCount);
      char guess =readAGuess();
      if (loopGuess(guessWord, guess))
      {
         notifyLoopGuess(guess);
         system("pause");
      }
      if (contain(secretWord, guess))
         guessWord =update(guessWord, secretWord, guess);
      else badGuessCount++;
   }
   while (badGuessCount <MAX_BAD_GUESSES && secretWord !=guessWord);

   renderGame(guessWord, badGuessCount);
   if (badGuessCount <MAX_BAD_GUESSES) cout <<"\nYou win!";
   else cout <<"\nFailed!";
   return 0;
}

const string WORD_LIST[] ={"book", "computer", "notebook"};
const int WORD_COUNT =sizeof(WORD_LIST) /sizeof(string);
string chooseWord()
{
   int randomIndex =rand() %WORD_COUNT;
   return WORD_LIST[randomIndex];
}

const string FIGURE[] ={
   "------------- \n"
   "|             \n"
   "|             \n"
   "|             \n"
   "|             \n"
   "|             \n"
   "-----         \n",

   "------------- \n"
   "|           | \n"
   "|             \n"
   "|             \n"
   "|             \n"
   "|             \n"
   "-----         \n",

   "------------- \n"
   "|           | \n"
   "|           O \n"
   "|             \n"
   "|             \n"
   "|             \n"
   "-----         \n",

   "------------- \n"
   "|           | \n"
   "|           O \n"
   "|           | \n"
   "|             \n"
   "|             \n"
   "-----         \n",

   "------------- \n"
   "|           | \n"
   "|           O \n"
   "|          /| \n"
   "|             \n"
   "|             \n"
   "-----         \n",

   "------------- \n"
   "|           | \n"
   "|           O \n"
   "|          /|\\\n"
   "|             \n"
   "|             \n"
   "-----         \n",

   "------------- \n"
   "|           | \n"
   "|           O \n"
   "|          /|\\\n"
   "|          /  \n"
   "|             \n"
   "-----         \n",

   "------------- \n"
   "|           | \n"
   "|           O \n"
   "|          /|\\\n"
   "|          / \\\n"
   "|             \n"
   "-----         \n",
   };

bool loopGuess(string guessWord, char guess)
{
   return (guessWord.find(guess) <guessWord.size() );
}
void notifyLoopGuess(char guess)
{
   cout <<' ' <<guess <<" have been guessed. Choose another guess!" <<endl;
}

void renderGame(string guessWord, int badGuessCount)
{
   system("cls");
   cout <<FIGURE[badGuessCount] <<endl;
   cout <<guessWord <<endl;
   cout <<"Number of wrong guesses: " <<badGuessCount <<endl;
}

char readAGuess()
{
   char c;
   cout <<"Your guess is: ";
   cin >>c;
   return c;
}

bool contain(string secretWord, char guess)
{
   return (secretWord.find(guess) <secretWord.size()) ;
}

string update(string guessWord, string secretWord, char guess)
{
   for (int i =0; i <secretWord.size(); i++)
      if (guess ==secretWord[i]) guessWord[i] =guess;
   return guessWord;
}
