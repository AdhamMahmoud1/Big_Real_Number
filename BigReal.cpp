#include "BigReal.h"
using namespace std;

bool BigReal :: checkValidInput(string input)
{
    regex validInput("[-+]?[0-9]*.[0-9]*");
    return regex_match(input, validInput);
}


// dividing the number into two parts
void BigReal::divide_big_real(string& big_real) {
    size_t dot = big_real.find('.');
    bool valid = checkValidInput(big_real);
    if (!valid){cout << "Unvalid Number" << endl;}
    else{
        if(dot == 0){            // dot at the first index so the integer part is 0 :  .12    ====     (0)  (12)
            integer_part = new string ("0");
        }
        else{integer_part = new string (big_real.substr(0,dot));}

        if(dot != string::npos){
            if (dot == (big_real.size() - 1)){other_part = new string ("0"); }
            else {other_part = new string (big_real.substr(dot + 1,big_real.size() + 1));}
        }
        else{other_part = new string ("0");}              // there is no dot so the rational part is 0 :  12  -->  12 . 0 
    }
}


// constructors :

// default constructor
BigReal::BigReal (double realNumber){
    string big_real = to_string(realNumber);
    divide_big_real(big_real);
}

BigReal::~BigReal(){
    delete integer_part;
    delete other_part;
}


BigReal::BigReal(string realNumber) {
    divide_big_real(realNumber);
}

BigReal::BigReal (BigDecimalInt bigInteger){
    integer_part = new string (bigInteger.getNumber());
    other_part = new string("0");
}



// Copy constructor
BigReal::BigReal (const BigReal& another) {
    this->integer_part = another.integer_part;
    this->other_part = another.other_part;
}

// Move Constructor
BigReal::BigReal(BigReal&& another){
    this-> integer_part = another.integer_part;
    this-> other_part = another.other_part;
    another.integer_part = nullptr;
    another.other_part = nullptr;
}

// Assignment operator
BigReal& BigReal:: operator= (BigReal& another){
    delete integer_part;
    delete other_part;
    integer_part = another.integer_part;
    other_part = another.other_part;
    return *this;
}

// Move Assignment
BigReal& BigReal:: operator= (BigReal&& another){
    if (this != &another){
        delete integer_part;
        delete other_part;
        this-> integer_part = another.integer_part;
        this-> other_part = another.other_part;
        another.integer_part = nullptr;
        another.other_part = nullptr;
    }
    return *this;
}


// comparison operators

bool BigReal::operator<(BigReal &anotherReal) {
    BigDecimalInt num1_integer_part(*integer_part);
    BigDecimalInt num1_other_part(*other_part);
    BigDecimalInt num2_integer_part(*(anotherReal.integer_part));
    BigDecimalInt num2_other_part(*(anotherReal.other_part));

    if(num1_integer_part < num2_integer_part){
        return true;
    }
    else if ( num1_integer_part > num2_integer_part){
        return false;
    } else{         // the two integer parts are equal
        if( num1_other_part < num2_other_part){
            return true;
        }
        else{       // > or ==
            return false;
        }
    }



}

bool BigReal::operator>(BigReal &anotherReal) {
    BigDecimalInt num1_integer_part(*integer_part);
    BigDecimalInt num1_other_part(*other_part);
    BigDecimalInt num2_integer_part(*(anotherReal.integer_part));
    BigDecimalInt num2_other_part(*(anotherReal.other_part));


    if(num1_integer_part > num2_integer_part){
        return true;
    }
    else if (num1_integer_part < num2_integer_part){
        return false;
    } else{         // the two integer parts are equal
        if(num1_other_part > num2_other_part){
            return true;
        }
        else{       // < or ==
            return false;
        }
    }

}


bool BigReal::operator==(BigReal &anotherReal) {
    BigDecimalInt num1_integer_part(*integer_part);
    BigDecimalInt num1_other_part(*other_part);
    BigDecimalInt num2_integer_part(*(anotherReal.integer_part));
    BigDecimalInt num2_other_part(*(anotherReal.other_part));

    if(num1_integer_part == num2_integer_part && num1_other_part == num2_other_part){
        return true;
    }
    else
        return false;

}

// overloading the output operator <<
ostream& operator << (ostream& out, BigReal &num){
    out << *(num.integer_part)  << '.' << *(num.other_part);
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
    BigDecimalInt A(*integer_part);
    return A.sign();
}


BigReal BigReal::operator+ (BigReal& another){
    string n1_integer = *integer_part;
    string n1_other_part = *other_part;
    string n2_integer = *(another.integer_part);
    string n2_other_part = *(another.other_part); 

    int n1_sz = n1_other_part.size();
    int n2_sz = n2_other_part.size();

    if( n1_sz > n2_sz){
        for(int i = 0; i < (n1_sz - n2_sz);i++){
            n2_other_part.push_back('0');
        }
    }
    else if (n1_sz < n2_sz){
        for(int i = 0; i < (n2_sz - n1_sz);i++){
            n1_other_part.push_back('0');
        }
    }

    int sz = n1_other_part.size();

    string n1 = n1_integer + n1_other_part, n2 = n2_integer + n2_other_part;

    BigDecimalInt A(n1),B(n2);
    
    BigDecimalInt sum;
    sum = A + B;


    string sm = sum.getNumber();

    sm.insert(sm.begin() + (sm.size() - sz),'.');

    
    BigReal ans(sm);
    if(sum.sign() == 0){
        sm = "-" + sm;
        ans.divide_big_real(sm);
    }
    else{
        ans.divide_big_real(sm);
    }
 

    return ans;

}

 BigReal BigReal::operator- (BigReal& another){
    string n1_integer = *integer_part;
    string n1_other_part = *other_part;
    string n2_integer = *(another.integer_part);
    string n2_other_part = *(another.other_part); 

    int n1_sz = n1_other_part.size();
    int n2_sz = n2_other_part.size();
    if( n1_sz > n2_sz){
        for(int i = 0; i < (n1_sz - n2_sz);i++){
            n2_other_part.push_back('0');
        }
    }
    else if (n1_sz < n2_sz){
        for(int i = 0; i < (n2_sz - n1_sz);i++){
            n1_other_part.push_back('0');
        }
    }

    int sz = n1_other_part.size();

    string n1 = n1_integer + n1_other_part, n2 = n2_integer + n2_other_part;

    BigDecimalInt A(n1),B(n2);
    
    BigDecimalInt sum;
    sum = A - B;

    string sm = sum.getNumber();
    sm.insert(sm.begin() + (sm.size() - sz),'.');
    BigReal ans(sm);
    if(sum.sign() == 0){
        sm = "-" + sm;
        ans.divide_big_real(sm);
    }
    else{
        ans.divide_big_real(sm);
    }
  return ans;

}