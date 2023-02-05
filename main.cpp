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
    arrayOne.append(15);
    arrayOne.append(3);
    arrayOne.append(-1);
    arrayOne.append(2);
    arrayOne.append(0);
    arrayOne.append(6);
    arrayOne.append(42);
    arrayOne.append(2);
    arrayOne.append(-6);
    arrayOne.sort();
    arrayOne.printArray();

    arrayTwo.append(11);
    arrayTwo.append(43);

    arrayOne.inserFirst(999);
    // arrayOne.insertAt(10, 122); для несуществующих индексов требуется создавать проверки!
    arrayOne.insertAt(3, 545);

    arrayOne + arrayTwo;
    // arrayOne[10] = 111999; для несуществующих индексов требуется создавать проверки!
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