//
// main.cpp
// 2023-02-03
// Ivan Konishchev
//

#include <iostream>
#include "integerArray.h"

int main(int argc, const char *argv[])
{
    // Объявление массивов
    integerArray arrayOne;
    integerArray arrayTwo(-5); // Объявление с ошибкой!

    // Добавление в массив значений с одновременным увеличением его размера.
    arrayOne.append(12);
    arrayOne.append(43);

    arrayTwo.append(5);
    arrayTwo.append(99);

    arrayOne.printArray();
    if (auto value = arrayOne[0])
    {
        std::cout << "array index: 0 -> value: " << *value << std::endl;
    }
    if (auto value = arrayOne[5])
    {
        std::cout << "array index: 5 -> value: " << *value << std::endl;
    }
    arrayOne.inserFirst(999);
    arrayOne.insertAt(10, 122);
    arrayOne.insertAt(3, 545);
    arrayOne[5];
    arrayOne.printArray();
    if (auto data = arrayOne.getFirstIndexWhere(43))
    {
        std::cout << "Число 43 найдено в массиве, инедкс: " << *data << std::endl;
    }

    if (auto data = arrayOne.getFirstIndexWhere(45))
    {
        std::cout << "Число 43 найдено в массиве, инедкс: " << *data << std::endl;
    }
    else
    {
        std::cout << "Число 45 не найдено в массиве\n";
    }
    std::cout << "array cout: " << arrayOne.count() << std::endl;
    return 0;
}