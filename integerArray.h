//
// integerArray.h
// 2023-02-03
// Ivan Konishchev
//

#pragma once
#include <iostream>
#include "BadAnswer.h"
class integerArray
{
    int _size{0};
    int *_array = nullptr;
    bool _isEmpty{true};
    int _returnValue{0};

    // private method
    void erase();

public:
    integerArray() = default;
    integerArray(int size);
    integerArray(const integerArray &array); //  Copy construction
    ~integerArray();
    int count() const;
    bool isEmpty() const;
    void append(int number);             // append an element to end of the array
    void insertAt(int index, int value); // Inserts an element into an array by index
    const int *first() const;            // return first element from array
    const int *last() const;             // return last element from array
    const int *removeFirst();            // Removes the first element from the array and returns it
    const int *removeLast();
    const int *removeAt(const int index);
    const int *getFirstIndexWhere(int value); // Array search by value
    void inserFirst(int value);               // Adding an element to the beginning of the array
    void printArray() const;                  // принт array
    const int *operator[](const int index);
    void operator+(integerArray &array);
    integerArray &operator=(const integerArray &array);
    bool operator==(const integerArray &array);
};