//
// integerArray.cpp
// 2023-02-03
// Ivan Konishchev
//

#include "integerArray.h"

// Init

integerArray::integerArray(int size) : _size(size)
{
    if (size <= 0)
    {
        throw BadAnswer(INCORRECT_ARRAY_LEINGHT);
    }
    _array = new int[_size];
    _isEmpty = false;
}

// copy constructor
integerArray::integerArray(const integerArray &array)
{
    erase();
    _isEmpty = array._isEmpty;
    _size = array._size;
    _array = new int[array._size];
    for (int i = 0; i < _size; i++)
    {
        _array[i] = array._array[i];
    }
}

// Deinit
integerArray::~integerArray()
{
    delete[] _array;
}

// erase array ( private method )
void integerArray::erase()
{
    delete[] _array;
    _array = nullptr;
    _isEmpty = true;
}

// return array leinght
int integerArray::count() const
{
    return _size;
}

// is empty array
bool integerArray::isEmpty() const
{
    return _isEmpty;
}

// append an element to end of the array
void integerArray::append(int number)
{
    _size++;
    int *newArray = new int[_size];

    if (_size <= 1)
    {
        newArray[0] = number;
    }
    else
    {
        for (int i = 0; i < _size - 1; i++)
        {
            newArray[i] = _array[i];
        }
        newArray[_size - 1] = number;
    }

    erase();

    _isEmpty = false;
    _array = newArray;
}

// Inserts an element into an array by index
void integerArray::insertAt(int index, int value)
{
    if (_isEmpty)
    {
        throw BadAnswer(ARRAY_IS_EMPTY);
    }
    if (index > _size)
    {
        throw BadAnswer(INDEX_OUT_OF_RANGE);
    }

    _size++;
    int *newArray = new int[_size];

    for (int i = 0; i < index; i++)
    {
        newArray[i] = _array[i];
    }

    newArray[index] = value;

    if (index + 1 != _size)
    {
        for (int i = index; i < _size; i++)
        {
            newArray[i + 1] = _array[i];
        }
    }

    erase();
    _isEmpty = false;
    _array = newArray;
}

// return first element from array
int integerArray::first() const
{
    if (_size > 0)
    {
        return _array[0];
    }
    throw BadAnswer(ARRAY_IS_EMPTY);
}

// return last element from array
int integerArray::last() const
{
    if (_size > 0)
    {
        return _array[_size - 1];
    }
    throw BadAnswer(ARRAY_IS_EMPTY);
}

// Removes the first element from the array and returns it
int integerArray::removeFirst()
{
    if (_size <= 0)
    {
        erase();
        throw BadAnswer(ARRAY_IS_EMPTY);
    }
    _size--;
    int first = _array[0];
    if (_size == 0)
    {
        erase();
    }
    else
    {
        int *newArray = new int[_size];
        for (int i = 0; i < _size; i++)
        {
            newArray[i] = _array[i + 1];
        }
        erase();
        _isEmpty = false;
        _array = newArray;
    }

    return first;
}

//  Removes the last element from the array and returns it
int integerArray::removeLast()
{
    if (_size <= 0)
    {
        erase();
        throw BadAnswer(ARRAY_IS_EMPTY);
    }
    _size--;
    int last = _array[_size];
    if (_size == 0)
    {
        erase();
    }

    return last;
}

// remove value by index
int integerArray::removeAt(const int index)
{
    if (_isEmpty)
    {
        throw BadAnswer(ARRAY_IS_EMPTY);
    }
    if (index > _size || index < 0)
    {
        throw BadAnswer(INDEX_OUT_OF_RANGE);
    }

    int result = _array[index];
    int *newArray = new int[_size - 1];
    for (int i = 0; i < index; i++)
    {
        newArray[i] = _array[i];
    }
    for (int i = index + 1; i < _size; i++)
    {
        newArray[i - 1] = _array[i];
    }

    erase();
    _isEmpty = false;
    _size--;
    _array = newArray;
    return result;
}

// Array search by value
int integerArray::getFirstIndexWhere(int value) const
{
    if (_size == 0)
    {
        throw BadAnswer(ARRAY_IS_EMPTY);
    }
    for (int i = 0; i < _size; i++)
    {
        if (_array[i] == value)
        {
            return i;
        }
    }
    throw BadAnswer(NO_FIND_VALUE);
}

// insert value at thebeginning
void integerArray::inserFirst(int value)
{
    insertAt(0, value);
}

int &integerArray::operator[](const int index)
{
    if (index >= 0 && index < _size)
    {
        return _array[index];
    }
    if (_isEmpty)
    {
        throw BadAnswer(ARRAY_IS_EMPTY);
    }
    throw BadAnswer(INDEX_OUT_OF_RANGE);
}

void integerArray::operator+(integerArray &array)
{
    if (_isEmpty && array._isEmpty)
    {
        return;
    }
    _isEmpty = false;
    int *newArray = new int[_size + array._size];
    for (int i = 0; i < _size; i++)
    {
        newArray[i] = _array[i];
    }
    for (int i = 0; i < array._size; i++)
    {
        newArray[i + (_size)] = array._array[i];
    }
    erase();
    _isEmpty = false;
    _size += array._size;
    _array = newArray;
}

integerArray &integerArray::operator=(const integerArray &array)
{
    if (this == &array)
    {
        return *this;
    }
    if (_array != nullptr)
    {
        erase();
    }
    _array = new int[array._size];
    for (int i = 0; i < array._size; i++)
    {
        _array[i] = array._array[i];
    }

    _size = array._size;
    _isEmpty = array._isEmpty;
    return *this;
}

bool integerArray::operator==(const integerArray &array)
{
    if (_array == array._array && _isEmpty == array._isEmpty && _size == array._size)
    {
        return true;
    }
    return false;
}

void integerArray::printArray() const
{
    for (int i = 0; i < _size; i++)
    {
        std::cout << "index: " << i << " значение: " << _array[i] << std::endl;
    }
}