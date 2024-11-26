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

        // Деструктор: освобождаем память
        ~My_array() {
            delete[] arr;
        }

        // Конструктор копирования
        My_array(const My_array& other) : size(other.size), filled_count(other.filled_count) {
            arr = new int[size];
            for (int i = 0; i < filled_count; ++i) { 
                arr[i] = other.arr[i];
            }
        }

        My_array& operator=(const My_array& other) {
            if (this == &other) {
                return *this; // Защита от самоприсваивания
            }

            delete[] arr;

            size = other.size;
            filled_count = other.filled_count;
            arr = new int[size];
            for (int i = 0; i < filled_count; ++i) { // Копируем только заполненные элементы
                arr[i] = other.arr[i];
            }
            return *this;
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
            arr[filled_count++] = value; 
        }
    };

    try {
        My_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);

        My_array new_array(2);
        new_array.add_element(44);
        new_array.add_element(34);

        arr = new_array; // Присваиваем новый массив

        std::cout << arr.get_element(0) << " " << arr.get_element(1) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}
