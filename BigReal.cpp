#include "BigReal.h"
using namespace std;

// dividing the number into two parts
void BigReal::divide_big_real(string& big_real) {
    size_t dot = big_real.find('.');


    if(dot == 0)            // dot at the first index so the integer part is 0 :  .12    ====     (0)  (12)
        integer_part = '0';
    else
        integer_part = big_real.substr(0,dot);

    if(dot != string::npos)
        other_part = big_real.substr(dot + 1,big_real.size() + 1);
    else                // there is no dot so the rational part is 0 :  12  -->  12 . 0
        other_part = '0';
}


// constructors :

// double constructor
BigReal::BigReal (double realNumber){

    string big_real = to_string(realNumber);

    divide_big_real(big_real);



}


BigReal::BigReal(string realNumber) {
    divide_big_real(realNumber);
}

BigReal::BigReal (BigDecimalInt bigInteger){
    integer_part = bigInteger.getNumber();
    other_part = '0';
}




// comparison operators

bool BigReal::operator<(BigReal &anotherReal) {
    BigDecimalInt num1_integer_part(integer_part);
    BigDecimalInt num1_other_part(other_part);
    BigDecimalInt num2_integer_part(anotherReal.integer_part);
    BigDecimalInt num2_other_part(anotherReal.other_part);

    if(num1_integer_part < num2_integer_part){
        return true;
    }
    else if (num1_integer_part > num1_other_part){
        return false;
    } else{         // the two integer parts are equal
        if(num1_other_part < num1_other_part){
            return true;
        }
        else{       // > or ==
            return false;
        }
    }



}
bool BigReal::operator>(BigReal &anotherReal) {
    BigDecimalInt num1_integer_part(integer_part);
    BigDecimalInt num1_other_part(other_part);
    BigDecimalInt num2_integer_part(anotherReal.integer_part);
    BigDecimalInt num2_other_part(anotherReal.other_part);


    if(num1_integer_part > num2_integer_part){
        return true;
    }
    else if (num1_integer_part < num1_other_part){
        return false;
    } else{         // the two integer parts are equal
        if(num1_other_part > num1_other_part){
            return true;
        }
        else{       // < or ==
            return false;
        }
    }

}


bool BigReal::operator==(BigReal &anotherReal) {
    BigDecimalInt num1_integer_part(integer_part);
    BigDecimalInt num1_other_part(other_part);
    BigDecimalInt num2_integer_part(anotherReal.integer_part);
    BigDecimalInt num2_other_part(anotherReal.other_part);

    if(num1_integer_part == num2_integer_part && num1_other_part == num2_other_part){
        return true;
    }
    else
        return false;

}

// overloading the output operator <<
ostream& operator << (ostream& out, BigReal &num){
    out << num.integer_part  << '.' << num.other_part;
    return out;
}


istream& operator >> (istream& in, BigReal &num){
    string big_real;
    in >> big_real;
    num.divide_big_real(big_real);
    return in;
}




// return 1 if the sign is positive or 0 if negative
int BigReal::sign() {
    // return the sign of the integer part
    BigDecimalInt A(integer_part);
    return A.sign();
}


