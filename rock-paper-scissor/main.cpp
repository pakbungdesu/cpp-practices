
#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;


void greeting(){
  cout <<
    " ____            _      ____                         ____       _                      _\n" 
    "|  _ \\ ___   ___| | __ |  _ \\ __ _ _ __   ___ _ __  / ___|  ___(_)___ ___  ___  _ __  | |\n"
    "| |_) / _ \\ / __| |/ / | |_) / _` | '_ \\ / _ \\ '__| \\___ \\ / __| / __/ __|/ _ \\| '__| | |\n"
    "|  _ < (_) | (__|   <  |  __/ (_| | |_) |  __/ |     ___) | (__| \\__ \\__ \\ (_) | |    |_|\n"
    "|_| \\_\\___/ \\___|_|\\_\\ |_|   \\__,_| .__/ \\___|_|    |____/ \\___|_|___/___/\\___/|_|    (_)\n"
    "                                  |_|                                                    \n";
  
}
  
void pics(int pic_index){
    string rock_pic = 
    "    _______\n"
    "---'   ____)\n"
    "      (_____)\n"
    "      (_____)\n"
    "      (____)\n"
    "---.__(___)\n";

    string paper_pic =
    "     _______\n"
    "---'    ____)____\n"
    "           ______)\n"
    "          _______)\n"
    "         _______)\n"
    "---.__________)\n";

    string scissor_pic =
    "    _______\n"
    "---'   ____)____\n"
    "          ______)\n"
    "       __________)\n"
    "      (____)\n"
    "---.__(___)\n";

  std::string all_pics[3] = {rock_pic, paper_pic, scissor_pic};
  cout << all_pics[pic_index];
}

int main() {

  greeting();
  
  int score[3][3] = {{1, 0, 2}, {2, 1, 0}, {0, 2, 1}};
  std::string hands[3] = {"Rock", "Paper", "Scissors"};
  int i = 1, total_user = 0, total_bot = 0;
  int user_num, user_score, bot_score;
  string con, user_hand;

  cout << "\nDo you want to continue or stop? "; cin >> con;
  
  while (con != "stop"){
    
    cout << "\nRound " << i;
    cout << "\nWhat do you choose?: "; cin >> user_hand;

    for (auto& x : user_hand) { 
        x = tolower(x); 
    } 

    if (user_hand == "rock"){
      user_num = 0;
    } else if (user_hand == "paper"){
      user_num = 1;
    } else {
      user_num = 2;
    }

    int bot_hand = rand() % 3;
    cout << "\nYour hand:\n";
    pics(user_num);
    cout << "\nBot hand:\n";
    pics(bot_hand);
    
    user_score = score[user_num][bot_hand];
    bot_score = score[bot_hand][user_num];

    cout << "\nYour score +" << user_score;
    cout << "\nBot score +" << bot_score;

    total_user += user_score;
    total_bot += bot_score;
    cout << "\nDo you want to continue or stop? "; cin >> con;
    i += 1;
  }
  cout << "\nYour total score: " << total_user;
  cout << "\nBot' total score: " << total_bot;

  if (total_user > total_bot){
    cout << "\nYou win! Congratulation ✨";
  } else if (total_user == total_bot) {
    cout << "\nIt's a tied match 🥊";
  } else {
    cout << "\nYou lost. Wanna give another try? 🔥";
  }
}
