#ifndef BIGREAL_H
#define BIGREAL_H
#include<bits/stdc++.h>
#include "BigDecimalIntClass.h"
using namespace std;

class BigReal {
private:
    string *integer_part;
    string *other_part;
    void divide_big_real(string& big_real);              // divide the number
    bool checkValidInput(string input);
public:
    BigReal (double realNumber = 0.0);                  // Default constructor
    BigReal (string realNumber);
    BigReal (BigDecimalInt bigInteger);
    BigReal (const BigReal& another); // Copy constructor
    BigReal (BigReal&& another); // Move constructor
    ~BigReal();
    BigReal& operator= (BigReal& another); // Assignment operator
    BigReal& operator= (BigReal&& another); // Move assignment
    BigReal& operator+ (BigReal& another);
    BigReal& operator- (BigReal& another);
    bool operator< (BigReal &anotherReal);
    bool operator> (BigReal &anotherReal);
    bool operator== (BigReal &anotherReal);
    int size();
    int sign();
    friend ostream& operator << (ostream& out, BigReal &num);
    friend istream& operator >> (istream& in, BigReal &num);
};

#endif
