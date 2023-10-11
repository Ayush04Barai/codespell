#include <iostream>
#include <stdexcept>

class ArrayADT {
private:
    int* arr;
    int size;

public:
    ArrayADT(int capacity) {
        size = capacity;
        arr = new int[capacity];
    }

    ~ArrayADT() {
        delete[] arr;
    }

    int get(int index) {
        if (index >= 0 && index < size) {
            return arr[index];
        } else {
            throw std::out_of_range("Index out of bounds");
        }
    }

    void set(int index, int value) {
        if (index >= 0 && index < size) {
            arr[index] = value;
        } else {
            throw std::out_of_range("Index out of bounds");
        }
    }

    int getSize() {
        return size;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    ArrayADT arr(5);

    for (int i = 0; i < 5; i++) {
        arr.set(i, i * 2);
    }

    std::cout << "Array elements: ";
    arr.display();

    try {
        int value = arr.get(2);
        std::cout << "Value at index 2: " << value << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
