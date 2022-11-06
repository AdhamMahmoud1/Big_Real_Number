#ifndef BIGREAL_H
#define BIGREAL_H
#include<bits/stdc++.h>
#include "BigDecimalIntClass.h"
using namespace std;

class BigReal {
private:
    string integer_part;
    string other_part;
    void divide_big_real(string &big_real);              // divide the number
public:
    BigReal (double realNumber = 0.0);                  // Default constructor
    BigReal (string realNumber);
    BigReal (BigDecimalInt bigInteger);
    BigReal (const BigReal& other); // Copy constructor
    BigReal (BigReal&& other); // Move constructor
    BigReal& operator= (BigReal& other); // Assignment operator
    BigReal& operator= (BigReal&& other); // Move assignment
    BigReal& operator+ (BigReal& other);
    BigReal& operator- (BigReal& other);
    bool operator< (BigReal &anotherReal);
    bool operator> (BigReal &anotherReal);
    bool operator== (BigReal &anotherReal);
    int size();
    int sign();
    friend ostream& operator << (ostream& out, BigReal &num);
    friend istream& operator >> (istream& in, BigReal &num);

};

#endif