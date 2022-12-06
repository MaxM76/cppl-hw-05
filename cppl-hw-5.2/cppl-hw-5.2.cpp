#include <iostream>

template<class T>
class table {
public:
    table(int rows, int cols) {

        elements = new T*[rows];
        for (int i = 0; i < rows; i++) {
            elements[i] = new T[cols];
        }
        rowCount = rows;
        colCount = cols;
    }

    T getElement(int row, int col) const {
        return elements[row][col];
    }

    void setElement(T value, int row, int col) {
        elements[row][col] = value;
    }

    ~table() {
        for (int i = 0; i < rowCount; i++) {
            delete[] elements[i];
        }
        delete[] elements;
    }

    int Size() const {
        return rowCount * colCount;
    }

    T*& operator[](int row) {
        if ((row > -1) && (row < rowCount)) {
            return elements[row];
        }
    }

    const T*& operator[](int row) const {
        if ((row > -1) && (row < rowCount)) {
            return elements[row];
        }
    }

private:
    T** elements = nullptr;
    int rowCount = 0;
    int colCount = 0;
};



int main()
{
    auto test = table<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0]; // выводит 4
}