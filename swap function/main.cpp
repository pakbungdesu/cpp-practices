
#include <iostream>
using namespace std;

void swapTemp(int* a, int* b) {
    int temp = *ptr2;
    *ptr2 = *ptr1;
    *ptr1 = temp;
}

void swapIntsNoThird1(int* a, int* b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void swapIntsNoThird2(int* a, int* b) {
   try {
   *a = *a * *b;
    *b = *a / *b;
    *a = *a / *b;
   } catch (...){
      cout << "Exception occurred" << endl;
   }
}

void input(int& a, int& b) {
    cout << "Insert a"; cin >> a;
    cout << "Insert b"; cin >> b;
}

void output(int a, int  b, string name) {
    cout << name << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
}

int main() {
    int a, b;

    // 1
    input(a, b);
    swapIntsNoThird1(&a, &b);
    output(a, b, "swapTemp");

    // 2
    input(a, b);
    swapIntsNoThird1(&a, &b);
    output(a, b, "swapIntsNoThird1");

    // 3
    input(a, b);
    swapIntsNoThird2(&a, &b);
    output(a, b, "swapIntsNoThird2");

    return 0;
}
