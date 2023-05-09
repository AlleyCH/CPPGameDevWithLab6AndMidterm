#include <iostream>

using namespace std;

template<typename T>
class Array
{
private:
    int rows;
    int columns;
    T** array;

public:
    Array(int rows, int columns) : rows(rows), columns(columns)
    {
        array = new T * [rows];
        for (int i = 0; i < rows; i++)
        {
            array[i] = new T[columns];
        }
    }

    ~Array()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] array[i];
        }
        delete[] array;
    }

    void input()
    {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++)
            {
                std::cin >> array[i][j];
            }
        }
    }
};

int main()
{
    Array<int> intArray(2, 3);
    cout << "Please provide the integers for the first array: " << endl;
    intArray.input();

    Array<char> charArray(3, 2);
    cout << "Please provide the characters for the second array: " << endl;
    charArray.input();

    return 0;
}