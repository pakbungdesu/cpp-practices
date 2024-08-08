
#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
void genericSwap(T* a, T* b, size_t size) {
    T* tempMem = (T*)malloc(size);

    memcpy(tempMem, a, size);
    memcpy(a, b, size);
    memcpy(b, tempMem, size);
    free(tempMem);
}

template <typename T>
void printOut(T a, T b, string text) {
    cout << text << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
}

template <typename T>
void Input(T& a, T& b) {
    cout << "Insert a: " << endl;
    cin >> a;
    cout << "Insert b: " << endl;
    cin >> b;
}

int main() {
    int a, b, menu;
    double c, d;
    char p, q;
    string r, s;

    cout << "Pick a number from the menu\n1) Integer\n2) Double\n3) Char\n4) String" << endl;
    cin >> menu;

    if(menu == 1) {
        Input(a, b);
        printOut(a, b, "Before Swap");
        genericSwap(&a, &b, sizeof(int));
        printOut(a, b, "After Swap");

    } else if (menu == 2) {
        Input(c, d);
        printOut(c, d, "Before Swap");
        genericSwap(&c, &d, sizeof(double));
        printOut(c, d, "After Swap");

    } else if (menu == 3) {
        Input(p, q);
        printOut(p, q, "Before Swap");
        genericSwap(&p, &q, sizeof(char));
        printOut(p, q, "After Swap");
    } else {
        Input(r, s);
        printOut(r, s, "Before Swap");
        genericSwap(&r, &s, sizeof(string));
        printOut(r, s, "After Swap");
    }


    return 0;
}
