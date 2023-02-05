//
// integerArray.cpp
// 2023-02-03
// Ivan Konishchev
//

#include "integerArray.h"

// Init with size
/*
    Negative value size, will throw an exception and create an empty array
    Using:
    integerArray array; - this create epmty array!
    integerArray array(0) / integerArray array(-1) - this create epmty array! and will throw an exception message!
    integerArray array(5) - create array leinght 5 and default value - 0
*/
integerArray::integerArray(int size) : _size(size)
{
    try
    {
        if (size <= 0)
        {
            throw BadAnswer(INCORRECT_ARRAY_LEINGHT);
        }
        else
        {
            _array = new int[_size];
            _isEmpty = false;
        }
    }
    catch (const BadAnswer &error)
    {
        _array = nullptr;
        _size = 0;
        _isEmpty = true;
        _returnValue = 0;
        std::cerr << error.showError();
    }
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
/*
    This method resets the array
*/
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

/*
    This method returns true if the array is empty, and false if the values exist
*/
bool integerArray::isEmpty() const
{
    return _isEmpty;
}

// append an element to end of the array
/*
    This method adds a value to the end of the array,
     and increases the size of the array
*/
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
/*
    This method adds a value to the passed index and expands the array!
    You need to make sure that the index exists,
    otherwise the value will not be added and an exception will occur
    - Error message: "Array is empty!" if array is empty.
    - Error message: "Index out of range!" if array dont contain an index
*/
void integerArray::insertAt(int index, int value)
{
    try
    {
        if (index < 0 || index > _size)
        {
            throw BadAnswer(INDEX_OUT_OF_RANGE);
        }
        else if (_isEmpty && index != 0)
        {
            throw BadAnswer(ARRAY_IS_EMPTY);
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
    catch (const BadAnswer &error)
    {
        std::cerr << error.showError();
    }
}

// return first element from array
/*
    This method returns a pointer to the first element of the array.
    - Error message: "Array is empty!" if array is empty.
*/
std::optional<int> integerArray::first() const
{
    try
    {
        if (_size > 0)
        {
            return _array[0];
        }
        throw BadAnswer(ARRAY_IS_EMPTY);
    }
    catch (const BadAnswer &error)
    {
        std::cerr << error.showError();
        return std::nullopt;
    }
}

// return last element from array
/*
    This method returns a pointer to the last value of the array.
    - Error message: "Array is empty!" if array is empty.
*/
std::optional<int> integerArray::last() const
{
    try
    {
        if (_size > 0)
        {
            return _array[_size - 1];
        }
        throw BadAnswer(ARRAY_IS_EMPTY);
    }
    catch (const BadAnswer &error)
    {
        std::cerr << error.showError();
        return std::nullopt;
    }
}

// Removes the first element from the array and returns it
/*
    This method deletes the first value of the array,
    reduces the size of the array, and returns a pointer to the deleted value.
    - Error message: "Array is empty!" if array is empty.
*/
std::optional<int> integerArray::removeFirst()
{

    try
    {
        if (_size <= 0)
        {
            erase();
            throw BadAnswer(ARRAY_IS_EMPTY);
        }

        _size--;
        _returnValue = _array[0];

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

        return _returnValue;
    }
    catch (const BadAnswer &error)
    {
        std::cerr << error.showError();
        return std::nullopt;
    }
}

//  Removes the last element from the array and returns it
/*
    This method deletes the last value of the array,
    reduces the size of the array, and returns a pointer to the deleted value.
    - Error message: "Array is empty!" if array is empty.
*/
std::optional<int> integerArray::removeLast()
{
    try
    {
        if (_size <= 0)
        {
            erase();
            throw BadAnswer(ARRAY_IS_EMPTY);
        }
        _size--;
        _returnValue = _array[_size];
        if (_size == 0)
        {
            erase();
        }

        return _returnValue;
    }
    catch (const BadAnswer &error)
    {
        std::cerr << error.showError();
        return std::nullopt;
    }
}

// remove value by index
/*
    This method deletes the value of the array by index,
    reduces the size of the array, and returns a pointer to the deleted value.

    It is necessary to make sure that the index exists,
    If the index is missing or the array is empty, an exception is thrown.

    - Error message: "Array is empty!" if array is empty.
    - Error message: "Index out of range!" if array dont contain an index
*/
std::optional<int> integerArray::removeAt(const int index)
{
    try
    {
        if (_isEmpty)
        {
            throw BadAnswer(ARRAY_IS_EMPTY);
        }
        if (index > _size || index < 0)
        {
            throw BadAnswer(INDEX_OUT_OF_RANGE);
        }

        _returnValue = _array[index];
        // int* result = new int(_array[index]);
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
        return _returnValue;
    }
    catch (const BadAnswer &error)
    {
        std::cerr << error.showError();
        return std::nullopt;
    }
}

// Array search by value
/*
    This method searches the array for the passed value,
    and returns a pointer to the index.
    Otherwise it will return nullptr.
    - Returns a pointer to the first index of the value or nullptr if the value is not found.
    - throw Error if array is empty and return nullptr
*/
std::optional<int> integerArray::getFirstIndexWhere(int value)
{
    try
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
        return std::nullopt;
    }
    catch (const BadAnswer &error)
    {
        std::cerr << error.showError();
        return std::nullopt;
    }
}

// insert value at thebeginning
/*
    this method isert value to the beginning of the array
*/
void integerArray::inserFirst(int value)
{
    insertAt(0, value);
}

/*
    overloaded index taking operator.
    Returns a pointer to the array value by index,
    nullptr if array is empry or index out if range..
*/
int &integerArray::operator[](const int index)
{
    // try
    // {
    if (index >= 0 && index < _size)
    {
        return _array[index];
    }
    if (_isEmpty)
    {
        throw BadAnswer(ARRAY_IS_EMPTY).showError();
    }
    throw std::overflow_error("Index out of range!!!");
    // throw  BadAnswer(INDEX_OUT_OF_RANGE).showError();
    // }
    // catch (const BadAnswer &error)
    // {
    //     std::cerr << error.showError();
    //     return nullptr;
    // }
}

// array concatenation
integerArray integerArray::operator+(integerArray &array)
{
    if (_isEmpty && array._isEmpty)
    {
        return *this;
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
    return *this;
}

// array concatenation
integerArray integerArray::operator+(integerArray &&array)
{
    if (_isEmpty && array._isEmpty)
    {
        return *this;
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
    return *this;
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

// Comparing two arrays
bool integerArray::operator==(const integerArray &array)
{
    if (_isEmpty == array._isEmpty)
    {
        if (_size == array._size)
        {
            for (int i = 0; i < _size; i++)
            {
                if (_array[i] != array._array[i])
                {
                    return false;
                }
            }
            return true;
        }
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

// Method for filtering an array
/*
    Method for filtering an array.
    operators: type char :  '<' '>' '='
    Returns a container with elements filtered by one of 3 rules:
    - '>' Returns a container with elements larger than the value
    - '<' Returns a container with elements less than the value
    - '=' Returns a container with elements equal to the value

*/
integerArray integerArray::filter(char operation, int value) const
{
    integerArray retArr;
    switch (operation)
    {
    case '<':
        for (int i = 0; i < _size; i++)
        {
            if (_array[i] < value)
            {
                retArr.append(_array[i]);
            }
        }
        return retArr;
    case '>':
        for (int i = 0; i < _size; i++)
        {
            if (_array[i] > value)
            {
                retArr.append(_array[i]);
            }
        }
        return retArr;
    case '=':
        for (int i = 0; i < _size; i++)
        {
            if (_array[i] == value)
            {
                retArr.append(_array[i]);
            }
        }
        return retArr;

    default:
        throw std::overflow_error("Incorrect operator!");
    }
}

// MARK: - Private auxiliary method
integerArray integerArray::sort(integerArray arr)
{
    if (arr._size == 0)
    {
        return arr;
    }
    int pivot = arr[arr._size / 2];
    integerArray less = arr.filter('<', pivot);
    integerArray equal = arr.filter('=', pivot);
    integerArray great = arr.filter('>', pivot);
    return sort(less) + equal + sort(great);
}

// Public sort method
/*
    Sorting Operators char -> '>'  and  '<'
    Вefault operator '>'
    incorrect operator enable sorting by default '>'
*/
void integerArray::sort(char operation)
{
    integerArray res = sort(*this);
    int *newArray = new int[res._size];
    if (operation == '>' || operation != '<')
    {
        for (int i = 0; i < res._size; i++)
        {
            newArray[i] = res._array[i];
        }
    }
    else
    {
        int revers = res._size - 1;
        for (int i = 0; i < res._size; i++)
        {
            newArray[revers - i] = res._array[i];
        }
    }

    delete[] _array;
    _array = newArray;
}