#include<iostream>

using namespace std;

class Rational {

    int nominator;
    int denominator;

    public:

    Rational(int nominator = 1, int denominator = 1) {

        setNominator(nominator);
        setDenominator(denominator);
    }

    void setNominator(int nominator) {

        this -> nominator = nominator;
    }

    
    void setDenominator(int denominator) {

        this -> denominator = denominator;
    }

    int getNominator() {

        return nominator;
    }

    
    int getDenominator() {

        return denominator;
    }

    friend Rational operator+ (Rational r1, Rational r2);

    friend ostream & operator>> (ostream &cout, Rational &r);
};

Rational operator+ (Rational r1, Rational r2) {

    Rational temp;

    temp.setNominator(r1.getNominator() * r2.getDenominator() + r1.getDenominator() * r2.getNominator());
    temp.setDenominator(r1.getDenominator() * r2.getDenominator()); 

    return temp;
}

ostream & operator<< (ostream &out, Rational &r) {

    out << r.getNominator() << "/" << r.getDenominator();

    return out;
}

int main() {

    Rational r1(3,4);
    Rational r2(2,5);
    Rational r3;

    cout << r1 << endl;
    cout << r2 << endl;
    cout << r3 << endl;

    r3 = r1 + r2;

    cout << "After addition : " << r3;

    return 0;
}