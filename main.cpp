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
    integerArray arrayTwo;

    // попытка создать массив с отрицательным индексом
    try
    {
        arrayOne = integerArray(-5);
    }
    catch (const BadAnswer &error)
    {
        std::cout << error.showError();
    }

    // Создание массива размером в 3 эллемента
    try
    {
        arrayOne = integerArray(3);
    }
    catch (const BadAnswer &error)
    {
        std::cout << error.showError();
    }

    // Добавление элементов в конец массива с увеличением его размера
    arrayOne.append(155);
    arrayOne.append(351);
    arrayOne.append(51);
    arrayOne.append(35);

    arrayTwo = arrayOne; // скопирован контейнер

    // вставка элемента в начало массива
    arrayOne.inserFirst(3212);
    // во второй массив добавили значение увеличив при этом его размер
    arrayTwo.append(5);
    arrayTwo.append(999);

    try
    {
        // Доступ к значению по индексу
        std::cout << "Элемент массива arrayTwo по индексу 0 : " << arrayTwo[0] << std::endl;

        // Доступ к неинициализированному пустому массиву индекса не существует!
        std::cout << "Доступ по несуществующему индексу ( пустой массив ): ";
        std::cout << arrayOne[10] << std::endl;
    }
    catch (const BadAnswer &error)
    {
        std::cout << error.showError();
    }

    // добавление элементов в массив с изменением его длинны на количество добавленных элементов.
    std::cout << "Конкатенация массивов: one +  \n";
    arrayOne.printArray(); // печать всего измененного массива
    std::cout << "Конкатенация массивов:  two \n";
    arrayTwo.printArray(); // печать всего измененного массива
    // конкатенация массивов;
    arrayOne + arrayTwo;

    try
    {
        std::cout << "Попытка вставки элемента в массив по индексу: ";
        // вставляем значение в массив по несуществующему индексу
        arrayOne.insertAt(3, 1001);
        std::cout << "значение вставлено, index: 3: значение: " << arrayOne[3] << std::endl;

        std::cout << "Попытка вставки элемента в массив по несуцществующему индексу: ";
        // вставляем значение в массив по несуществующему индексу
        arrayOne.insertAt(100, 1001);
    }
    catch (const BadAnswer &error)
    {
        std::cout << error.showError();
    }

    arrayOne.printArray(); // печать всего измененного массива

    try
    {
        std::cout << "Попытка удалить первый элемент массива, размер массива:  " << arrayOne.count() << std::endl;
        int value = arrayOne.removeFirst();
        std::cout << "Удалено значение: " << value << " index: 0: размер массива: " << arrayOne.count() << std::endl;
    }
    catch (const BadAnswer &error)
    {
        std::cout << error.showError();
    }

    try
    {
        std::cout << "Попытка удалить последний элемент массива, размер массива:  " << arrayOne.count() << std::endl;
        int value = arrayOne.removeLast();
        std::cout << "Элемент удален: " << value << " , размер массива: " << arrayOne.count() << std::endl;
    }
    catch (const BadAnswer &error)
    {
        std::cout << error.showError();
    }

    try
    {
        std::cout << "Поиск в массиве значения 1001 : ";
        int index = arrayOne.getFirstIndexWhere(1001);
        std::cout << "первый найденый индекс с таким содержимым: " << index << std::endl;

        std::cout << "Поиск в массиве значения 2001 : ";
        index = arrayOne.getFirstIndexWhere(2001);
        std::cout << "первый найденый индекс с таким содержимым: " << index << std::endl;
    }
    catch (const BadAnswer &error)
    {
        std::cout << error.showError();
    }

    arrayOne.printArray(); // печать всего измененного массива

    try
    {
        std::cout << "Удаление значения по индексу 2: ";
        int value = arrayOne.removeAt(2);
        std::cout << "удален элемент :" << value << std::endl;

        std::cout << "Удаление значения по несуществующему индексу : ";
        value = arrayOne.removeAt(20);
        std::cout << "удален элемент :" << value << std::endl;
    }
    catch (const BadAnswer &error)
    {
        std::cout << error.showError();
    }

    arrayOne.printArray(); // печать массива для наголядности

    try
    {
        std::cout << "Тест выхода за пределы при удалении \n";
        std::cout << "Удален: " << (arrayOne.removeLast()) << std::endl;
        std::cout << "Удален: " << (arrayOne.removeLast()) << std::endl;
        std::cout << "Удален: " << (arrayOne.removeLast()) << std::endl;
        std::cout << "Удален: " << (arrayOne.removeLast()) << std::endl;
        std::cout << "Удален: " << (arrayOne.removeLast()) << std::endl;
        std::cout << "Удален: " << (arrayOne.removeLast()) << std::endl;
        std::cout << "Удален: " << (arrayOne.removeLast()) << std::endl;
        std::cout << "Удален: " << (arrayOne.removeLast()) << std::endl;
        std::cout << "Удален: " << (arrayOne.removeLast()) << std::endl;
        std::cout << "Удален: " << (arrayOne.removeLast()) << std::endl;
        std::cout << "Удален: " << (arrayOne.removeLast()) << std::endl;
        std::cout << "Удален: " << (arrayOne.removeLast()) << std::endl;
        std::cout << "Удален: " << (arrayOne.removeLast()) << std::endl;
        std::cout << "Удален: " << (arrayOne.removeLast()) << std::endl;
        std::cout << "Удален: " << (arrayOne.removeLast()) << std::endl;
        std::cout << "Удален: " << (arrayOne.removeLast()) << std::endl;
        std::cout << "Удален: " << (arrayOne.removeLast()) << std::endl;
        std::cout << "Удален: " << (arrayOne.removeLast()) << std::endl;
        std::cout << "Удален: " << (arrayOne.removeLast()) << std::endl;
        std::cout << "Удален: " << (arrayOne.removeLast()) << std::endl;
        std::cout << "Удален: " << (arrayOne.removeLast()) << std::endl;
        std::cout << "Удален: " << (arrayOne.removeLast()) << std::endl;
    }
    catch (const BadAnswer &error)
    {
        std::cout << error.showError();
    }

    std::cout << "array cout: " << arrayOne.count() << std::endl;
    return 0;
}