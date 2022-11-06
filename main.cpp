#include <iostream>
#include "BigDecimalIntClass.cpp"
#include "BigReal.cpp"


using namespace std;
int main(){



    BigReal A("500.5");
    BigReal B(".21");
    cout << "Enter a value for A : ";
    cin >> A;
    cout << "Enter a value for B : ";
    cin >> B;
    cout << "A > B :" << (A > B) << endl;
    cout << "A < B :" << (A < B) << endl;
    cout << "A == B :" << (A == B) << endl;
    cout << "the sign of A and B  : " <<  A.sign() << ',' << B.sign() << endl;
//    cout << "A + B = " << A + B << endl;
//    BigReal C("1555");
//    BigReal D(455.3);
//    BigReal F (BigDecimalInt("456456323"));
//    cout << A << endl;
//    cout << B << endl;
//    cout << C << endl;
//    cout << D << endl;
//    cout << F << endl;



    return 0;
  
}
