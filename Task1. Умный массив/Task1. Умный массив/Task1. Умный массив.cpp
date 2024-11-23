#include <iostream>
#include <string>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    class My_array {
    public:
        int* arr;
        int size;

        My_array(int size) : size(size) {
            arr = new int[size] {};
        }
        ~My_array() {
            delete[] arr;
        }
        int get_element(int index) const { // Гетер элемента
            if (index < 0 || index >= size) {
                throw std::invalid_argument("Элемент отсутствует");
            }
            return arr[index];
        }

        void add_element(int value) {
            for (int i = 0; i < size; ++i) { // Проходим по массиву если нашли пустую ячейку записываем значение
                if (arr[i] == 0) { 
                    arr[i] = value; 
                    return;
                }
            }
            throw std::invalid_argument("Массив переполнен"); // Если массив полон
        }
    };

    try {
        My_array arr(5);
        arr.add_element(3);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        /*arr.add_element(15);*/
        for (int i = 0; i < 5; ++i) {// выводим элементы в консоль
            std::cout << arr.get_element(i) << std::endl;
        } 
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}
