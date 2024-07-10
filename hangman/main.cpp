
#include <iostream>
#include <cstdlib> // random library
#include <ctime> // change the random every time
#include <cmath> // for ceil
#include <vector>
#include "data.h"
#include "myfunc.h"
using namespace std;


int main() {

  // random a word
  srand(time(0));
  int w = rand()%1023;
  string myword = words(w);
  int lengthW = myword.length();

  // specify the shown index
  int times = ceil(lengthW*0.4);
  std::vector <int> show_letter;
  
  for(int i=0;i < times;i++){
    int idx = rand()%lengthW;
    show_letter.push_back(idx);
  }


  char guess;
  int lives = 7;

  while (lives > 0){
    display(myword, lengthW, show_letter);
    cout << "\nYour lives: " << lives;
    cout << "\nGuess a letter: "; cin >> guess;

    bool check = contain2(myword, guess);
    if (check == false){
      cout << "\nYou're incorrect. There is no " << guess << " in the word!\n";
      lives -= 1;
      pics(lives);
    } else {
      cout << "\nYou're right!\n";
      show_letter = update_show(myword, lengthW, show_letter, guess);
    }
    
    if(show_letter.size() == lengthW){
      display(myword, lengthW, show_letter);
      cout << "\nYou win! Congratulation ✨";
      break;
    }
  }
  if(lives == 0){
    cout << "\nYou lost!\nThe word is " << myword << " 🔥";
  }
  return 0;
}
