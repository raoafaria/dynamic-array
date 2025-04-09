#include <iostream>
#include <stdexcept> // for out_of_range

class DynamicArray {
private:
    int* data;
    int capacity;
    int length;

    void resize(int newCapacity) {
        int* newData = new int[newCapacity];
        for (int i = 0; i < length; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    DynamicArray() {
        capacity = 2;
        length = 0;
        data = new int[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void push_back(int value) {
        if (length == capacity) {
            resize(capacity * 2);
        }
        data[length++] = value;
    }

    int get(int index) const {
        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    void set(int index, int value) {
        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of bounds");
        }
        data[index] = value;
    }

    int size() const {
        return length;
    }

    void print() const {
        std::cout << "[";
        for (int i = 0; i < length; i++) {
            std::cout << data[i];
            if (i < length - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    DynamicArray arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);  // triggers resize
    arr.print();        // Output: [10, 20, 30]

    std::cout << "Element at index 1: " << arr.get(1) << std::endl; // 20

    arr.set(1, 99);
    arr.print(); // Output: [10, 99, 30]

    std::cout << "Size: " << arr.size() << std::endl; // 3

    return 0;
}
