
#pragma once
#include <vector>
using namespace std;


bool contain1(std::vector <int> find_array, int check_idx){
  for(int f: find_array){
    if(f == check_idx){
      return true;
    }
  }
  return false;
}

bool contain2(string word, char guess_check){
  for(char x: word){
    if(x == guess_check){
      return true;
    }
  }
  return false;
}


void display(string myword, int w_length, std::vector <int> show_char){
  cout << "\n";
  for (int i = 0;i < w_length;i++){
    if (contain1(show_char, i)){
      cout << myword[i] << " ";
    }else{
      cout << "_ ";
    }
  }
}


std::vector <int> update_show(string myword, int w_length, std::vector <int> show_char, char guess){
  std::vector <int> unique;
  
  for(int i=0;i < w_length;i++){
    if(myword[i] == guess){
        show_char.push_back(i);
    }
  }

  for(int j: show_char){
    if(!contain1(unique, j)){
      unique.push_back(j);
    }
  }
  return unique;
}
