
#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int convert(string s, int i) {
    if(isalpha(s.at(i))) {
        return int(s.at(i)) - 55;
    } else {
        return s.at(i) - '0';
    }
}

string base10toany(int d, int any) {
    char cmod;
    if (d == 0) {
        return "";
    } else {
        int mod = d % any;
        if( mod >= 0 && mod <= 9) {
            cmod = mod + '0';
            return base10toany(d/any, any) + cmod;
        } else {
            cmod = mod - 10 + 'A';
            return base10toany(d/any, any) + cmod;
        }
    }
}

int anytobase10(string s, int base) {
    int res = 0, expo = 0;
    for(int i = s.length() - 1; i >= 0; i--) {
        int d = convert(s, i);
        int pos = d * pow(base, expo);
        expo += 1;
        res += pos;
    }
    return res;
}

int main(){
    string start, dest;
    int startb, destb;
  
    cout << "Insert start number:"; cin >> start;
    cout << "Insert start base:"; cin >> startb;
    cout << "Insert destination base:"; cin >> destb;
    
    int res1 = anytobase10(start, startb);
    string res2 = base10toany(res1, destb);
    
    cout << "Destination number:" << res2 << endl;

    return 0;
}
