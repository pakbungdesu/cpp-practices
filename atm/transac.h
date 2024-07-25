
#pragma once
using namespace std;

class Transac{
  public:
    string name;
    int index, balance, acc_num;
    string password;

    // create object if account found
    bool findAcc(string fName, int fNum, map <string,int> info, Transac& obj){

      if (info.find(fName) != info.end()) {

        obj.name = fName;
        obj.index = info[fName];
        obj.acc_num = AccNum(obj.index);
        obj.password = Password(obj.index);
        obj.balance = Balance(obj.index);
  
        if(obj.acc_num == fNum){
          cout << "Account found" << endl;
          return true;
        } else {
          cout << "Account not found" << endl;
          return false;
        }            
      } else {
        cout << "Account not found" << endl;
        return false;
      }
    }

    bool CheckPass(Transac obj, string pw){
      if(pw == obj.password){
        cout << "Password correct\nLog in successfully" << endl;
        return true;
      } else {
        cout << "Invalid password" << endl;
        return false;
      }
    }

    void Deposit(int money, Transac& obj){
      try {
        obj.balance += money;
        cout << "Updated balance: " << obj.balance << endl;
        cout << "\nTransaction successful" << endl;
      } catch(...){
        cout << "\nSomething went wrong. Transaction failed" << endl;
      }
    }

    void Withdraw(int money, Transac& obj){
      try{
        if(obj.balance >= money){
          obj.balance -= money;
          cout << "Updated balance: " << obj.balance << endl;
          cout << "\nTransaction successful" << endl;
        }else{
          cout << "\nThere is not enough money. Transaction failed" << endl;
        }
      }catch(...){
          cout << "\nSomething went wrong. Transaction failed" << endl;
        }
    }
  
    void Transfer(int money, Transac& obj1, Transac& obj2){
      try{
        if(obj1.balance >= money){
          
          obj1.balance -= money;
          obj2.balance += money;
          
          cout << "Updated balance: " << obj1.balance << endl;
          cout << "\nTransaction successful" << endl;
        } else {
          cout << "\nThere is not enough money. Transaction failed" << endl;
        }
      } catch(...){
        cout << "\nSomething went wrong. Transaction failed" << endl;
      }
    }
};
