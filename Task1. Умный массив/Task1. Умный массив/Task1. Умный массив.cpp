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
        int filled_count; 

        My_array(int size) : size(size), filled_count(0) {
            arr = new int[size]; 
        }

        ~My_array() {
            delete[] arr;
        }

        int get_element(int index) const {
            if (index < 0 || index >= filled_count) {
                throw std::invalid_argument("Элемент отсутствует");
            }
            return arr[index];
        }

        void add_element(int value) {
            if (filled_count >= size) {
                throw std::invalid_argument("Массив переполнен");
            }
            arr[filled_count++] = value; // Записываем элемент и увеличиваем счётчик
        }
    };

    try {
        My_array arr(5); // Создаём массив размером 5
        arr.add_element(3);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        // arr.add_element(16); // Если раскомментировать, бросит исключение

        for (int i = 0; i < arr.filled_count; ++i) { 
            std::cout << arr.get_element(i) << std::endl;
        }
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}
