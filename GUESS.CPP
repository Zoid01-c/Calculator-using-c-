#include<iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
clrscr();
  time_t t;
  time(&t);
  srand((unsigned)t);

 
  int randomNumber = rand() % 100 + 1;

 
  int numberOfAttempts = 0;
  int userGuess = 0;

 
  while (userGuess != randomNumber) 
{
    cout << "Enter your guess between 1 and 100: ";
    cin >> userGuess;

    
    numberOfAttempts++;

  
    if (userGuess < randomNumber) 
{
      cout << "Your guess is too low. Try again." << endl;
    } 
else if (userGuess > randomNumber) 
{
      cout << "Your guess is too high. Try again." << endl;
    } 
else 
{
      cout << "Congratulations! You guessed the correct number in "
           << numberOfAttempts << " attempts." << endl;
    }
  }

  getch();

  return 0;
}