#ifndef ARRAY_H
#define ARRAY_H

// Class : Array (can be of any data type)
template<typename T>
class Array {
    
    private:
    
    T *ptr;
    int size, length;

    public:

    // Constructors
    Array();
    Array(int size);

    // Accessors
    int getSize();
    int getLength();

    // General functions
    void display();
    void add(const T x);
    void insert(const int index, const T x);
    void remove(const int index);
    bool isSorted();
    void insertSort(const T x);
    int search(const T x);
    void shrinkSize();
    void changeSize(const int newSize);
    T get(int index); // Throws input invalidation exception
    void set(int index, const T x);
    T max();
    T min();
    T sum();
    T average();
    void reverse();
    void leftShift();
    void rightShift();
    void leftRotate();
    void rightRotate();
    void reArrange();
    Array merge(Array x); // Throws unsorted array exception.
    void sort();

    // Set functions
    Array setUnion(Array x); // Throws unsorted array exception.
    Array setIntersection(Array x); // Throws unsorted array exception.
    Array setDifference(Array x); // Throws unsorted array exception.

    // Operator overloading
    Array & operator = (Array &arr);

    // Destructor
    ~Array();
};

#endif