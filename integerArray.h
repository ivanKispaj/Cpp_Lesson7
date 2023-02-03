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
    void erase();

public:
    integerArray() = default;
    integerArray(int size);
    integerArray(const integerArray &array);
    ~integerArray();

    int count() const;
    bool isEmpty() const;
    void append(int number);                 // append an element to end of the array
    void insertAt(int index, int value);     // Inserts an element into an array by index
    int removeAt(const int index);           // deleting value by index;
    int first() const;                       // return first element from array
    int last() const;                        // return last element from array
    int removeFirst();                       // Removes the first element from the array and returns it
    int removeLast();                        //  Removes the last element from the array and returns it
    int getFirstIndexWhere(int value) const; // Array search by value
    void printArray() const;                 // принт array
    int &operator[](const int index);
    void operator+(integerArray &array);
};