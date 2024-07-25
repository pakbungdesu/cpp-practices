
#include <iostream>
#include <vector>
#include <map>
#include "data.h"
#include "transac.h"
using namespace std;


int main() {

  cout << "    ______   ________  __       __  \n"
          "   /      \\ /        |/  \\     /  | \n"
          "  /$$$$$$  |$$$$$$$$/ $$  \\   /$$ | \n"
          "  $$ |__$$ |   $$ |   $$$  \\ /$$$ | \n"
          "  $$    $$ |   $$ |   $$$$  /$$$$ | \n"
          "  $$$$$$$$ |   $$ |   $$ $$ $$/$$ | \n"
          "  $$ |  $$ |   $$ |   $$ |$$$/ $$ | \n"
          "  $$ |  $$ |   $$ |   $$ | $/  $$ | \n"
          "  $$ /  $$ /   $$ /   $$ /     $$ /  \n";

  // create info map
  map <string, int> info;
  CreateMap(info);

  // create method
  Transac acc1;
  bool res1, res2, res3;
  int new_money, menu, start_num, final_num;
  string acc_start, acc_final, password;

  // input account name
  cout << "\n\nInsert your account name: "; cin >> acc_start;
  cout << "Insert your account number: "; cin >> start_num;
  res1 = acc1.findAcc(acc_start, start_num, info, acc1);

  if (res1 == true){
    cout << "\nInsert your password: "; cin >> password;
    res2 = acc1.CheckPass(acc1, password);

    // finally log in
    if(res2 == true){ 

      while(true){
        cout << "\nCurrent balance: " << acc1.balance << endl;
        cout << "Select one number from the menus\n1) Deposit\n2) Withdraw\n3) Transfer\n4) Log out" << endl;
        cin >> menu;

        if(menu == 1){
          cout << "\nInsert deposit money: "; cin >> new_money;
          acc1.Deposit(new_money, acc1);
        } else if(menu == 2) {
          cout << "\nInsert withdraw money: "; cin >> new_money;
          acc1.Withdraw(new_money, acc1);
          
        } else if (menu == 3) {
          cout << "\nInsert the terminal account name: "; cin >> acc_final;
          cout << "Insert the terminal account number: "; cin >> final_num;

          Transac acc2; // second object to transfer
          res3 = acc2.findAcc(acc_final, final_num, info, acc2);

          if(res3 == true){
            cout << "Insert transfered money: "; cin >> new_money;
            acc1.Transfer(new_money, acc1, acc2);
          }
        } else {
          break;
        }
      }
    }
  }
}
