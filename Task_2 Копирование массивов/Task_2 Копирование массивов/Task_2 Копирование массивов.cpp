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

        My_array(const My_array& other) : size(other.size) {
            arr = new int[size];
            for (int i = 0; i < size; ++i) {
                arr[i] = other.arr[i];
            }
        }

        // Оператор присваивания
        My_array& operator=(const My_array& other) {
            if (this == &other) {
                return *this; // Защита от самоприсваивания
            }

            // Освобождаем старую память
            delete[] arr;

            // Копируем новые данные
            size = other.size;
            arr = new int[size];
            for (int i = 0; i < size; ++i) {
                arr[i] = other.arr[i];
            }
            return *this;
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
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);

        My_array new_array(2);
        new_array.add_element(44);
        new_array.add_element(34);

        arr = new_array;

        std::cout << arr.get_element(0) << " " << arr.get_element(1) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}
