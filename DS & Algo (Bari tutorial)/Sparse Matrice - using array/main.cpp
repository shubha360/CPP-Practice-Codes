#include<iostream>

using namespace std;

// Element class
class Element {
    
    private:
    int row;
    int column;
    int value;

    public:
    int getRow();
    int getColumn();
    int getValue();
    void setRow(int row);
    void setColumn(int column);
    void setValue(int value);
};

int Element :: getRow() {
    return row;
}

int Element :: getColumn() {
    return column;
}

int Element :: getValue() {
    return value;
}

void Element :: setRow(int row) {
    this -> row = row;
}

void Element :: setColumn(int column) {
    this -> column = column;
}

void Element :: setValue(int value) {
    this -> value = value;
}

// Sparse class
class Sparse {

    private:
    int totalRow;
    int totalColumn;
    int totalValue;
    Element * storage;

    public:
    Sparse (int totalRow, int totalColumn, int totalValue);

    Sparse operator+ (Sparse &obj);

    friend istream & operator>> (istream &is, Sparse &obj);
    friend ostream & operator<< (ostream &os, Sparse &obj);

    ~Sparse();
};

Sparse :: Sparse(int totalRow, int totalColumn, int totalValue) {

    this -> totalRow = totalRow;
    this -> totalColumn = totalColumn;
    this -> totalValue = totalValue;
    this -> storage = new Element[this -> totalValue];

    for (int i = 0; i < this -> totalValue; i++) {
     
        storage[i].setRow(0);
        storage[i].setColumn(0);
        storage[i].setValue(0);
    }
}

Sparse :: ~Sparse() {
    delete[] storage;
}

Sparse Sparse :: operator+ (Sparse &obj) {

    if (this -> totalRow != obj.totalRow || this -> totalColumn != obj.totalColumn) {

        cout << "Dimensions doesn't match" << endl;
        return Sparse(0,0,0);
    }

    int i, j ,k;
    i = j = k = 0;

    Sparse * sumOfSparse = new Sparse(totalRow, totalColumn, totalValue + obj.totalValue);

    while (i < totalValue && j < obj.totalValue) {

        if (this -> storage[i].getRow() < obj.storage[j].getRow()) {
            
            sumOfSparse -> storage[k].setRow(storage[i].getRow());
            sumOfSparse -> storage[k].setColumn(storage[i].getColumn());
            sumOfSparse -> storage[k].setValue(storage[i].getValue());
            k++;
            i++;
        }
        
        else if (this -> storage[i].getRow() > obj.storage[j].getRow()) {
            
            sumOfSparse -> storage[k].setRow(obj.storage[j].getRow());
            sumOfSparse -> storage[k].setColumn(obj.storage[j].getColumn());
            sumOfSparse -> storage[k].setValue(obj.storage[j].getValue());
            k++;
            j++;
        }
        
        else if (this -> storage[i].getRow() == obj.storage[j].getRow()) {

            if (this -> storage[i].getColumn() < obj.storage[j].getColumn()) {

                sumOfSparse -> storage[k].setRow(storage[i].getRow());
                sumOfSparse -> storage[k].setColumn(storage[i].getColumn());
                sumOfSparse -> storage[k].setValue(storage[i].getValue());
                k++;
                i++;
            }
            
            else if (this -> storage[i].getColumn() > obj.storage[j].getColumn()) {

                sumOfSparse -> storage[k].setRow(obj.storage[j].getRow());
                sumOfSparse -> storage[k].setColumn(obj.storage[j].getColumn());
                sumOfSparse -> storage[k].setValue(obj.storage[j].getValue());
                k++;
                j++;
            }

            else if (this -> storage[i].getColumn() == obj.storage[j].getColumn()) {

                sumOfSparse -> storage[k].setRow(storage[i].getRow());
                sumOfSparse -> storage[k].setColumn(storage[i].getColumn());
                sumOfSparse -> storage[k].setValue(storage[i].getValue() + obj.storage[j].getValue());
                k++;
                i++;
                j++;
            }
        }
    }

    for (; i < this -> totalValue; i++) {

        sumOfSparse -> storage[k].setRow(storage[i].getRow());
        sumOfSparse -> storage[k].setColumn(storage[i].getColumn());
        sumOfSparse -> storage[k].setValue(storage[i].getValue());
        k++;
    }

    for (; j < obj.totalValue; j++) {
        
        sumOfSparse -> storage[k].setRow(storage[j].getRow());
        sumOfSparse -> storage[k].setColumn(storage[j].getColumn());
        sumOfSparse -> storage[k].setValue(storage[j].getValue());
        k++;
    }
    
    return * sumOfSparse;
}

istream & operator>> (istream &is, Sparse &obj) {

    for (int i = 0; i < obj.totalValue; i++) {
        
        int row, column, value;
        cout << "Enter row-column-value of element " << i+1 << " : ";
        is >> row >> column >> value;
        
        if ((row >= 1 && row <= obj.totalRow) && (column >= 1 && column <= obj.totalColumn)) {
            
            obj.storage[i].setRow(row);
            obj.storage[i].setColumn(column);
            obj.storage[i].setValue(value);
        }
        else {
            cout << "Invalid row or column enetred." << endl;
            return is;
        }
    }
    return is;
}

ostream & operator<< (ostream &os, Sparse &obj) {
    
    int k = 0;

    for (int i = 1; i <= obj.totalRow; i++) {
        for (int j = 1; j <= obj.totalColumn; j++) {

            if (i == obj.storage[k].getRow() && j == obj.storage[k].getColumn()) {
                os << obj.storage[k].getValue() << " ";
                k++;
            }
            else
             cout << "0 ";
        }
        cout << endl;
    }   
    return os;
}

int main() {

    Sparse sp1(3,3,3);
    Sparse sp2(3,3,3);

    cin >> sp1;
    cin >> sp2;

    cout << sp1;
    cout << endl;
    cout << sp2;
    cout << endl;

    auto sp3 = sp1 + sp2;

    cout << sp3;

    return 0;
}