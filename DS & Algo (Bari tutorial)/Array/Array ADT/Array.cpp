#include<iostream>
#include "Array.h"

using namespace std;

// Custom exception class for input invalidation
class IndexInvalidationException : public exception {
    
    public:
    virtual const char* what() const throw()
    {
        return "Invalid index inputted.";
    }
} indexInvalidationException;

// Custom exception class for unsorted array
class UnsortedArrayException : public exception {
    
    public:
    virtual const char* what() const throw()
    {
        return "Either one or both of the arrays are unsorted";
    }
} unsortedArrayException;

// Function for swapping a pair of element of any datatype
template<typename T>
void swap(T *a, T *b) {
    
    T temp = *a;
    *a = *b;
    *b = temp;
}

// No argument constructor
template<typename T>
Array<T> :: Array() {
    
    this -> size = 10;
    this -> length = 0;
    this -> ptr = new T[size];
}

// Constructor with size parameter
template<typename T>
Array<T> :: Array(int size) {
    
    this -> size = size;
    this -> length = 0;
    this -> ptr = new T[size];
}

// Accessor function for size
template<typename T>
int Array<T> :: getSize() {
    return this -> size;
}

// Accessor function for length
template<typename T>
int Array<T> :: getLength() {
    return this -> length;
}

// Function for displaying array
template<typename T>
void Array<T> :: display(){

    if(this -> length <= 0)
        cout << "Array is empty.";
    
    else {
        for(int i = 0; i < this -> length; i++)
            cout << this -> ptr[i] << " ";
    }
    cout << endl;
}

// Function for adding element to array
template<typename T>
void Array<T> :: add(const T x){

    if(this -> length == this -> size)
        cout << "Array is already filled." << endl;
    
    else {
        this -> ptr[length] = x;
        this -> length++;
    }
}

// Function for inserting element to array
template<typename T>
void Array<T> :: insert(const int index, const T x) {

    if(this -> length == this -> size)
        cout << "Array is already filled." << endl;
    if(index < 0 || index >= this -> length)
        cout << "Invalid input." << endl;
    
    else {
        for(int i = this -> length; i > index; i--)
            this -> ptr[i] = this -> ptr[i-1];
            
        this -> ptr[index] = x;
        this -> length++;
    }
}

// Function for removing a element from array
template<typename T>
void Array<T> :: remove(const int index){

    if(index < 0 && index >= this -> length)
        cout << "Invalid input" << endl;

    else {
        
        for(int i = index; i < this -> length-1; i++)
            this -> ptr[i] = ptr[i+1];
        
        this -> length--;
    }
}

// Function returns true if array is sorted
template<typename T>
bool Array<T> :: isSorted() {

    for(int i = 0; i < this -> length-1; i++) {

        if(this -> ptr[i] > this -> ptr[i+1])
            return false;
    }
    return true;
}

// For for inserting an element to sorted array
template<typename T>
void Array<T> :: insertSort(const T x) {

    if (!this -> isSorted()) {
        cout << "Array is unsorted." << endl;
        return;
    }

    if (length == size) {
        cout << "Array is already filled." << endl;
        return;
    }

    int i = length - 1;

    while (this -> ptr[i] > x && i >= 0) {
        
        this -> ptr[i+1] = this -> ptr[i];
        i--;
    }
    this -> ptr[i + 1] = x;
    length++;
}

// Function for searching for an element in array
template<typename T>
int Array<T> :: search(const T x) {

    if(this -> isSorted()) {
        
        int low = 0, high = length - 1, mid;

        while(low < high) {
            mid = (low + high) /2;

            if(mid == x)
                return mid;
            else if(x < mid)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
    else {
        for (int i = 0; i < this -> length; i++) {
            
            if(this -> ptr[i] == x) {
                
                swap(& this -> ptr[0], & this -> ptr[i]);
                return i;
            }
        }
        return -1;
    }
}

// Function for shrinking size of array equivalent to length
template<typename T>
void Array<T> :: shrinkSize() {
         
        this -> size = this -> length;

         T *temp = new T[this -> length];

        for (int i = 0; i < this -> length; i++)
            temp[i] = this -> ptr[i];
        
        this -> ptr = nullptr;
        this -> ptr = new T[length];

        for (int i = 0; i < this -> length; i++)
            this -> ptr[i] = temp[i];

        delete[] temp;

    cout << "Size shrunk to length." << endl;
}

// Function for changing size of array
template<typename T>
void Array<T> :: changeSize(const int newSize){

    if (newSize < this -> length)
        cout << "Invalid size input." << endl;
    
    if (newSize == this -> size)
        cout << "Size is already " << this -> size << endl;

    else {

        int x = this -> size;
        this -> size = newSize;

        T *temp = new T[length];

        for (int i = 0; i < this -> length; i++)
            temp[i] = this -> ptr[i];
        
        this -> ptr = nullptr;
        this -> ptr = new T[newSize];

        for (int i = 0; i < this -> length; i++)
            this -> ptr[i] = temp[i];

        delete[] temp;
        
        x < size ? cout << "Size increased to " << newSize << endl : cout << "Size decreased to " << newSize << endl;
    }
}

// Function for outputting element at given index of array (throws exception)
template<typename T>
T Array<T> :: get(int index) {

    if (index < 0 || index >= this -> length)
        throw indexInvalidationException;
    
    return this -> ptr[index];
}

// Function for changing element at given index in array
template<typename T>
void Array<T> :: set(int index, const T x){

    if (index < 0 && index >= this -> length)
        cout << "Invalid index." << endl;
    else
        this -> ptr[index] = x;
}

// Function for outputting element with the maximum value
template<typename T>
T Array<T> :: max() {

    if(this -> isSorted())
        return this -> ptr[length-1];    
    
    T max = this -> ptr[0];

    for (int i = 0; i < length; i++)
        this -> ptr[i] > max ? max = this -> ptr[i] : max = max;
    
    return max;
}

// Function for outputting element with the minimum value
template<typename T>
T Array<T> :: min() {

    if(this -> isSorted())
        return this -> ptr[0];    
    
    T min = this -> ptr[0];

    for (int i = 0; i < this ->  length; i++)
        this -> ptr[i] < min ? min = this ->  ptr[i] : min = min;
    
    return min;
}

// Function for outputting sum of all the elements
template<typename T>
T Array<T> :: sum() {
    
    T total = 0;
    
    for (int i = 0, j = this -> length - 1; i <= j; i++, j--)
        i == j ? total += this -> ptr[i] : total += this -> ptr[i] + this -> ptr[j];
    
    return total;
}

// Function for outputting average
template<typename T>
T Array<T> :: average() {
    return sum() / this -> length;
}

// Function for reversing the array
template<typename T>
void Array<T> :: reverse() {

    for (int i = 0, j = this -> length - 1; i <= j; i++, j--)
        swap(& this -> ptr[i], & this -> ptr[j]);
}

// Function for shifting the elements to left
template<typename T>
void Array<T> :: leftShift() {

    for (int i = 0; i < this -> length - 1; i++)
        this -> ptr[i] = this -> ptr[i+1];
    this -> ptr[length-1] = 0;
}

// Function for shifting the elements to right
template<typename T>
void Array<T> :: rightShift() {

    for (int i = this -> length-1; i > 0 ; i--)
        this -> ptr[i] = this -> ptr[i-1];
    this -> ptr[0] = 0;
}

// Function for rotating the elements to left
template<typename T>
void Array<T> :: leftRotate() {
    T temp = this -> ptr[0];

    for (int i = 0; i < length - 1; i++)
        this -> ptr[i] = this -> ptr[i+1];
    this -> ptr[length-1] = temp;
}

// Function for rotating the elements to right
template<typename T>
void Array<T> :: rightRotate() {
    T temp = this -> ptr[length-1];

    for (int i = this -> length-1; i > 0 ; i--)
        this -> ptr[i] = this -> ptr[i-1];
    this -> ptr[0] = temp;
}

// Function for merging two sorted arrays (Throws exception)
template<typename T>
Array<T> Array<T> :: merge(Array x) {
     
    if(!this -> isSorted() || !x.isSorted())
        throw unsortedArrayException;
    
    Array temp(this -> length + x.getLength());

    int i = 0, j = 0;

    while (i < this -> length && j < x.getLength()) {
        
        if (this -> ptr[i] < x.get(j)) {
            temp.add(this -> ptr[i]);
            i++;
        }
        else {
            temp.add(x.get(j));
            j++;
        }
    }
    
    for (; i < this -> length; i++)
        temp.add(this -> ptr[i]);
    
    for (; j < x.getLength(); j++)
        temp.add(x.get(j));
    
    return temp;
}

// Function for sorting the elements of array
template<typename T>
void Array<T> :: sort() {

    while (!this -> isSorted()) {
        for (int i = 0; i < length - 1; i++) {
            if (ptr[i] > ptr[i+1])
                swap(ptr[i], ptr[i+1]);
        }
    }
}

// Function for outputting union of two sets of arrays (Throws exception)
template<typename T>
Array<T> Array<T> :: setUnion(Array x) {

    if (!this -> isSorted() || !x.isSorted())
        throw unsortedArrayException;


    Array temp(this -> length + x.getLength());

    int i = 0, j = 0;

    while (i < this -> length && j < x.length) {

        if (this -> ptr[i] < x.get(j)) {
            temp.add(this -> ptr[i]);
            i++;
        }
        else if ( this -> ptr[i] > x.get(j)) {
            temp.add(x.get(j));
            j++;
        }
        else {
            temp.add(this -> ptr[i]);
            i++;
            j++;
        }
    }
        
    for (; i < this -> length; i++)
        temp.add(this -> ptr[i]);

    for (; j < x.getLength(); j++)
        temp.add(x.get(j));

    return temp;
}

// Function for outputting intersection of two sets of arrays (Throws exception)
template<typename T>
Array<T> Array<T> :: setIntersection(Array x) {

    if (!this -> isSorted() || !x.isSorted())
        throw unsortedArrayException;

    Array temp(this -> length + x.getLength());

    int i = 0, j = 0;

    while (i < this -> length && j < x.length) {

        if (this -> ptr[i] < x.get(j)) {
            i++;
        }
        else if ( this -> ptr[i] > x.get(j)) {
            j++;
        }
        else {
            temp.add(this -> ptr[i]);
            i++;
            j++;
        }
    }
    return temp;
}

// Function for outputting difference of two sets of arrays (Throws exception)
template<typename T>
Array<T> Array<T> :: setDifference(Array x) {

    if (!this -> isSorted() || !x.isSorted())
        throw unsortedArrayException;


    Array temp(this -> length + x.getLength());

    int i = 0, j = 0;

    while (i < this -> length && j < x.length) {

        if (this -> ptr[i] < x.get(j)) {
            temp.add(this -> ptr[i]);
            i++;
        }
        else if ( this -> ptr[i] > x.get(j)) {
            j++;
        }
        else {
            i++;
            j++;
        }
    }
        
    for (; i < this -> length; i++)
        temp.add(this -> ptr[i]);

    return temp;
}

// Function for overloading operator=
template<typename T>
Array<T> & Array<T> :: operator = (Array &arr) {

    Array temp(arr.getLength());

    for (int i = 0; i < arr.getLength(); i++)
        temp.add(arr.get(i));
    
    return temp;
}

// Destructor
template<typename T>
Array<T> :: ~Array() {
    delete[] ptr;
}