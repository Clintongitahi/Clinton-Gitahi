#include <iostream>
using namespace std;

struct Fraction {
    int num;
    int den;
};

Fraction& largestFraction(Fraction& f1, Fraction& f2, Fraction& f3) {
    Fraction* largest = &f1;

    if (f2.num * largest->den > largest->num * f2.den)
        largest = &f2;

    if (f3.num * largest->den > largest->num * f3.den)
        largest = &f3;

    return *largest;
}

int main() {
    Fraction a, b, c;

    cout << "Enter first fraction (num den): ";
    cin >> a.num >> a.den;

    cout << "Enter second fraction (num den): ";
    cin >> b.num >> b.den;

    cout << "Enter third fraction (num den): ";
    cin >> c.num >> c.den;

    Fraction& maxFraction = largestFraction(a, b, c);

    cout << "Largest Fraction is: "
         << maxFraction.num << "/" << maxFraction.den << endl;

    return 0;
}
