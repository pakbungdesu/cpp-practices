
#pragma once
#include <vector>
using namespace std;


string Name(int index){
  vector <string> name = {"Rei", 
                          "Asuka", 
                          "Shinji", 
                          "Kaworu", 
                          "Mari"};
  return name[index];
}

int AccNum(int index){
  vector <int> acc_number = {100, 101, 102, 103, 104};

  return acc_number[index];
}

string Password(int index){
  vector <string> passw = {"nothingjustmeow", 
                        "aggressivesometimes", 
                        "kaworusocool", 
                        "ikarisocute", 
                        "loveyouasuka"};

  return passw[index];
}

int Balance(int index){
  vector <int> balance = {100, 250, 200, 500, 100};

  return balance[index];
}

void CreateMap(map <string, int>& map_data){ // for index
  for(int i = 0; i < 5; i++){
    string name = Name(i);
    map_data[name] = i;
  }
}
