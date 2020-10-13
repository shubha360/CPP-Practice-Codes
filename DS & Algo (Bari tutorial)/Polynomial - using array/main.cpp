#include<iostream>
#include<math.h>

using namespace std;

class Term {

    private:

    int coefficient;
    int exponent;

    public:

    int getCoefficient();
    int getExponent();
    void setCoefficient(int coefficient);
    void setExponent(int exponent);
};

int Term :: getCoefficient() {
    return coefficient;
}

int Term :: getExponent() {
    return exponent;
}

void Term :: setCoefficient(int coefficient) {
    this -> coefficient = coefficient;
}

void Term :: setExponent(int exponent) {
    this -> exponent = exponent;
}

class Polynomial {

    private:

    int valueOfX;
    int actualTerms;
    int numberOfTerms;
    Term * termStorage;

    public:

    Polynomial(int valueOfX, int numberOfTerms);

    int evaluate();

    Polynomial operator+ (Polynomial &obj);

    friend istream & operator>> (istream &is, Polynomial &obj);
    friend ostream & operator<< (ostream &os, Polynomial &obj);

    ~Polynomial();
};

Polynomial :: Polynomial(int valueOfX, int numberOfTerms) {
    
    this -> valueOfX = valueOfX;
    this -> numberOfTerms = numberOfTerms;
    this -> actualTerms = numberOfTerms;
    this -> termStorage = new Term[numberOfTerms];

    for (int i = 0; i < actualTerms; i++) {
        
        termStorage[i].setCoefficient(0);
        termStorage[i].setExponent(0);
    }
}

int Polynomial :: evaluate() {

    int sum = 0;
    for (int i = 0; i < actualTerms; i++) {

        int temp = termStorage[i].getCoefficient() * (pow(valueOfX, termStorage[i].getExponent()));
        sum += temp;
    }

    return sum;
}

Polynomial Polynomial :: operator+ (Polynomial &obj) {

    if (this -> valueOfX != obj.valueOfX) {

        cout << "Value of x doesn't match." << endl;
        return Polynomial(0,0);
    }

    Polynomial * sum = new Polynomial(this -> valueOfX, (this -> actualTerms + obj.actualTerms));

    int i, j, k;
    i = j = k = 0;

    while (i < this -> numberOfTerms && j < obj.numberOfTerms) {

        if (this -> termStorage[i].getExponent() > obj.termStorage[j].getExponent()) {

            sum -> termStorage[k].setCoefficient(termStorage[i].getCoefficient());
            sum -> termStorage[k].setExponent(termStorage[i].getExponent());
            k++;
            i++;
        }
        
        else if (this -> termStorage[i].getExponent() < obj.termStorage[j].getExponent()) {

            sum -> termStorage[k].setCoefficient(obj.termStorage[j].getCoefficient());
            sum -> termStorage[k].setExponent(obj.termStorage[j].getExponent());
            k++;
            j++;
        }
        else {
            sum -> termStorage[k].setCoefficient(termStorage[i].getCoefficient() + obj.termStorage[j].getCoefficient());
            sum -> termStorage[k].setExponent(termStorage[i].getExponent());
            k++;
            i++;
            j++;
        }
    }

    for (; i < this -> numberOfTerms; i++) {

        sum -> termStorage[k].setCoefficient(termStorage[i].getCoefficient());
        sum -> termStorage[k].setExponent(termStorage[i].getExponent());
        k++;
    }

    for (; j < obj.numberOfTerms; j++) {
        
        sum -> termStorage[k].setCoefficient(termStorage[j].getCoefficient());
        sum -> termStorage[k].setExponent(termStorage[j].getExponent());
        k++;
    }

    sum -> actualTerms = k;
    return * sum;
}

istream & operator>> (istream &is, Polynomial &obj) {

    for (int i = 0; i < obj.actualTerms; i++) {
        
        int coefficientInput, exponentInput;
        cout << "Enter coefficient and exponent for term " << i+1 << " : ";
        is >> coefficientInput >> exponentInput;
        obj.termStorage[i].setCoefficient(coefficientInput);
        obj.termStorage[i].setExponent(exponentInput);
    }
    return is;
}

ostream & operator<< (ostream &os, Polynomial &obj) {

    for (int i = 0; i < obj.actualTerms; i++)
        os << obj.termStorage[i].getCoefficient() << "x" << obj.termStorage[i].getExponent() << " + ";

    os << endl << "Where value of x is " << obj.valueOfX;
    return os;
}

Polynomial :: ~Polynomial() {
    delete[] termStorage;
}

int main() {

    Polynomial p1(2,3);
    Polynomial p2(2,4);

    cin >> p1;
    cin >> p2;

    cout << p1;
    cout << endl;
    cout << p2;
    cout << endl;

    auto p3 = p1 + p2;

    cout << p3;
    cout << endl;

    cout << endl;
    cout << "Result of polynomial 1 is " << p1.evaluate();
    cout << endl;
    cout << "Result of polynomial 2 is " << p2.evaluate();
    cout << endl;
    cout << "Result of polynomial 3 is " << p3.evaluate();

    return 0;
}