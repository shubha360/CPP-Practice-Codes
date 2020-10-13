#include<iostream>
#include<math.h>

using namespace std;

class Term {

    public:

    int coeff;
    int exp;
    Term *next;
};

class Polynomial {

    public:
    Term *first_term;

    Polynomial();
    void display();
    void addTerm(int coeff, int exp);
    int evaluate(int value_of_x);
    void addAnother(Polynomial obj);
    ~Polynomial();
};

// COnstructor
Polynomial :: Polynomial() {

    first_term = new Term;

    first_term = nullptr;
}

// Display function
void Polynomial :: display() {

    if (first_term == nullptr)
        cout << "Polynomail is empty" << endl;
    
    else {
        
        Term *ptr = first_term;
        
        while (ptr) {
            
            cout << ptr -> coeff << "x" << ptr -> exp << " + ";
            ptr = ptr -> next;
        }
    }
}


// Adding new term
void Polynomial :: addTerm(int coeff, int exp) {

    Term *temp = new Term;
    temp -> coeff = coeff;
    temp -> exp = exp;
    temp -> next = nullptr;

    if (first_term == nullptr)
        first_term = temp;
    
    else {
     
        Term *ptr = first_term;

        while (ptr -> next != nullptr)
            ptr = ptr -> next;

        ptr -> next = temp;
    }
}

// Evaluating polynomial
int Polynomial :: evaluate(int value_of_x) {

    if (first_term == nullptr) {
        
        cout << "Polynomial is empty" << endl;
        return 0;
    }

    Term *ptr = first_term;
    int sum = 0;

    while (ptr) {
     
        sum += ptr -> coeff * pow(value_of_x, ptr -> exp);
        ptr = ptr -> next;
    }
    return sum;
}

// Destructor
Polynomial :: ~Polynomial() {

    Term *ptr = first_term;

    while (ptr) {
        
        first_term = first_term -> next;
        delete ptr;
        ptr = first_term;
    }
}


int main() {

    Polynomial p1, p2;

    p1.addTerm(3,2);
    p1.addTerm(4,3);
    p1.addTerm(1,4);
    p1.addTerm(5,1);

    p1.display();
    cout << endl;

    p2.addTerm(2,2);
    p2.addTerm(3,3);
    p2.addTerm(4,1);

    p2.display();
    cout << endl;

    cout << endl << "Sum is " << p1.evaluate(2) << endl;
    cout << endl << "Sum is " << p2.evaluate(3) << endl;

    return 0;
}