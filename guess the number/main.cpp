
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

  cout << 
  "   .d8888b.                                          888    888                   888b    888                        888                      \n"
  "  d88P  Y88b                                         888    888                   8888b   888                        888                      \n"
  "  888    888                                         888    888                   88888b  888                        888                      \n"
  "  888        888  888  .d88b.  .d8888b  .d8888b      888888 88888b.   .d88b.      888Y88b 888 888  888 88888b.d88b.  88888b.   .d88b.  888d888\n"
  "  888  88888 888  888 d8P  Y8b 88K      88K          888    888 \"88b d8P  Y8b     888 Y88b888 888  888 888 \"888 \"88b 888 \"88b d8P  Y8b 888P   \n"  
  "  888    888 888  888 88888888 \"Y8888b. \"Y8888b.     888    888  888 88888888     888  Y88888 888  888 888  888  888 888  888 88888888 888    \n"
  "  Y88b  d88P Y88b 888 Y8b.          X88      X88     Y88b.  888  888 Y8b.         888   Y8888 Y88b 888 888  888  888 888 d88P Y8b.     888    \n"  
  "   Y8888P88  \"Y88888  \"Y8888   88888P'  88888P'      \"Y888  888  888\"Y8888        888    Y888  \"Y88888 888  888  888 88888P\"   \"Y8888  888 \n";   
  
  string level;
  int lives, guess;
  cout << "\n\nI'm thinking of a number between 1 and 100.\n";
  cout << "Choose a difficulty. Type 'easy' or 'hard'\n";
  cin >> level;

  if(level == "easy"){
    lives = 10;
  }else{
    lives = 7;
  }
  
  srand(time(0));
  int n = rand() % 101;

  while(lives > 0){
    cout << "You have " << lives << " attempts remaining to guess the number\n";
    cout << "Make a guess\n";
    cin >> guess;

    if(guess > n){
      cout << "Too high. Guess again.\n";
    }else if(guess < n){
      cout << "Too low. Guess again.\n";
    }else{
      cout << "You got it! The answer was " << n;
      break;
    }

    lives -= 1;
  }
}
